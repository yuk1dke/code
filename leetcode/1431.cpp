#include <iostream>
//#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
    {
        vector<bool> vecB(candies.size(), false);
        int nMax = *max_element(candies.begin(), candies.end());
        int nDiff{nMax - extraCandies};
        for(int i = 0; i < candies.size(); ++i){
            if(nDiff <= candies[i]){
                vecB[i] = true;
            }
        }

        return vecB;
    }
};

int main(void)
{
    vector<int> candies{4, 2, 1, 1, 2};
    Solution so;
    vector<bool> vecB = so.kidsWithCandies(candies, 1);
    for(auto item : vecB){
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
