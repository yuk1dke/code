#include <iostream>
#include <algorithm>

using namespace std;

class Solution{

public:
    int lengthOfLongestSubstring(const string &s)
    {
        auto maxNum = 0;
        if(maxNum != s.size()){
            auto currentNum = 0;
            auto beginPos = s.begin( );
            auto endPos = beginPos;
            for(unsigned int i = 0; i < s.size(); ++ i){
                auto tempIter = find(beginPos, endPos, s[i]);
                if(tempIter == endPos){
                    ++ currentNum;
                    maxNum <= currentNum ? maxNum = currentNum : 0;
                    ++ endPos;
                }else{
                    beginPos = tempIter + 1;
                    ++ endPos;
                    currentNum = endPos - beginPos;
                }
            }
        }

        return maxNum;
    }
};

int main(int argc, char **argv)
{
    string str[] = {
        "abcabcbb",
        "bbbbb",
        "pwwkew",
        "dvdf",
        "bbtablud"
    };

    Solution so;
    cout << so.lengthOfLongestSubstring(str[4]) << endl;

    return 0;
}

