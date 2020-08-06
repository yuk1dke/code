#include <pthread.h>
#include <future>
#include <iostream>
#include <thread>

using namespace std;

class Foo {
public:
#if 1
    // 1
    Foo()
    {
        mMutex1.lock();
        mMutex2.lock();
    }

    void first(function<void()> printFirst)
    {
        printFirst();
        mMutex1.unlock();
    }

    void second(function<void()> printSecond)
    {
        mMutex1.lock();
        printSecond();
        mMutex1.unlock();
        mMutex2.unlock();
    }

    void third(function<void()> printThird)
    {
        mMutex2.lock();
        printThird();
        mMutex2.unlock();
    }
#elif 0
    // 2 !
    Foo()
    {
    }

    void first(function<void()> printFirst)
    {
        unique_lock<mutex> lock(mLock);
        printFirst();
        con1.notify_all();
    }

    void second(function<void()> printSecond)
    {
        unique_lock<mutex> lock(mLock);
        con1.wait(lock);
        printSecond();
        lock.unlock();
        con2.notify_all();
    }

    void third(function<void()> printThird)
    {
        unique_lock<mutex> lock(mLock);
        con2.wait(lock);
        printThird();
    }

#elif 0
    // 3
    Foo()
        : count(0)
    {
    }

    void first(function<void()> printFirst)
    {
        unique_lock<mutex> lock(mLock);
        printFirst();
        ++count;
        con.notify_all();
    }

    void second(function<void()> printSecond)
    {
        unique_lock<mutex> lock(mLock);
        con.wait(lock, [this]() {
            return count == 1;
        });
        printSecond();
        ++count;
        con.notify_all();
    }

    void third(function<void()> printThird)
    {
        unique_lock<mutex> lock(mLock);
        con.wait(lock, [this]() {
            return count == 2;
        });
        printThird();
    }

#elif 0
    Foo()
    {
    }

    void first(function<void()> printFirst)
    {
        printFirst();
        p1.set_value();
    }

    void second(function<void()> printSecond)
    {
        p1.get_future().wait();
        printSecond();
        p2.set_value();
    }

    void third(function<void()> printThird)
    {
        p2.get_future().wait();
        printThird();
    }
#elif 0
    // 5
    Foo()
    {
        pthread_mutex_init(&one, NULL);
        pthread_mutex_init(&two, NULL);
        pthread_mutex_lock(&one);
        pthread_mutex_lock(&two);
    }

    void first(function<void()> printFirst)
    {
        printFirst();
        pthread_mutex_unlock(&one);
    }

    void second(function<void()> printSecond)
    {
        pthread_mutex_lock(&one);
        printSecond();
        pthread_mutex_unlock(&one);
        pthread_mutex_unlock(&two);
    }

    void third(function<void()> printThird)
    {
        pthread_mutex_lock(&two);
        printThird();
        pthread_mutex_unlock(&two);
#endif

    void pOne()
    {
        cout << "one";
    }

    void pTwo()
    {
        cout << "two";
    }

    void pThree()
    {
        cout << "three";
    }

private:
#if 1
    // 1
    mutex mMutex1;
    mutex mMutex2;
#elif 0
    // 2 !
    mutex              mLock;
    condition_variable con1;
    condition_variable con2;
#elif 0
    // 3
    int                count;
    mutex              mLock;
    condition_variable con;
#elif 0
    // 4
    promise<void> p1;
    promise<void> p2;
#elif 0
        // 5
        pthread_mutex_t one;
        pthread_mutex_t two;
#endif
};

int main(int argc, char** argv)
{
    Foo f;

#if 1
    thread t1{&Foo::first, ref(f), bind(&Foo::pOne, ref(f))};
    thread t2{&Foo::second, ref(f), bind(&Foo::pTwo, ref(f))};
    thread t3{&Foo::third, ref(f), bind(&Foo::pThree, ref(f))};
    t1.join();
    t2.join();
    t3.join();
#endif

    return 0;
}
