#include <iostream>
#include <vector>
#include <unordered_map> // or map

using namespace std;

class Solution{
public:

    vector<int> twoSum2(vector<int> &nums, int target)
    {
        unordered_map<int, int> m;

        for(int i = 0; i < nums.size( ); i++){

            m[nums[i]] = i;
        }

        int temp = 0;

        for(int i = 0; i < nums.size( ); i++){

            temp = target - nums[i];

            if(m.find(temp) != m.end( ) && m[temp] != i){

                return {i,m[temp]};
            }
        }

        return {};
    }

    vector<int> twoSum1(vector<int> &nums, int target)
    {
        unordered_map<int, int> m;
        int temp = 0;

        for(int i = 0; i < nums.size( ); i++){

            int temp = target - nums[i];

            if(m.find(temp) != m.end( )){

                return {m[temp],i};
            }

            m[nums[i]] = i;
        }
        return {};
    }
};

int main(void)
{
    Solution so;
    //vector<int> vecInt{2, 7, 11, 15};
    //vector<int> vecInt{0, 4, 3, 0};
    vector<int> vecInt{-3, 4, 3, 90};

    vector<int > tt = so.twoSum1(vecInt, 0);

    for(int i : tt){

        cout << i;
    }

    cout << endl;

    return 0;
}
