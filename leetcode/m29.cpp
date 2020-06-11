#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        if(0 == matrix.size() || 0 == matrix[0].size()){
            return {};
        }

        int rows = matrix.size();
        int columns = matrix[0].size();
        vector<int> vecInt(rows * columns, 0);
        int nLeft = 0;
        int nRight = columns - 1;
        int nTop = 0;
        int nBottom = rows - 1;
        int i = 0;
        while(nLeft <= nRight && nTop <= nBottom){
            for(int column = nLeft; column <= nRight; ++column){
                vecInt[i++] = matrix[nTop][column];
            }
            for(int row = nTop + 1; row <= nBottom; ++row){
                vecInt[i++] = matrix[row][nRight];
            }
            if(nLeft < nRight && nTop < nBottom){
                for(int column = nRight - 1; nLeft < column; --column){
                    vecInt[i++] = matrix[nBottom][column];
                }
                for(int row = nBottom; nTop < row; --row){
                    vecInt[i++] = matrix[row][nLeft];
                }
            }
            ++nLeft;
            ++nTop;
            --nRight;
            --nBottom;
        }

        return vecInt;
    }
};


int main(void)
{
    Solution so;

    vector<vector<int>> vecInt{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto ret = so.spiralOrder(vecInt);
    for(auto item : ret){
        cout << item << " " << endl;
    }

    return 0;
}
