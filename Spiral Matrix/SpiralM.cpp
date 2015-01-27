#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0;
        int right = n-1;
        int up = 0;
        int down = m-1;

        int token =0;
        while (up<=down && left<=right) {
            if (token == 0)   {
                for (int i= left;i<=right;i++)
                    ans.push_back(matrix[up][i]);
                up++;
            }
            if (token ==1) {
                for (int i = up;i<=down;i++)
                    ans.push_back(matrix[i][right]);
                right--;
            }
            if (token ==2) {
                for (int i= right;i>=left;i--)
                    ans.push_back(matrix[down][i]);
                down--;
            }
            if (token ==3) {
                for (int i = down;i>=up;i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
            token = ++token % 4;
        }


        return ans;
        
    }
};

int main() {
    Solution S;
    vector<vector<int> > matrix = { {1,2,3,4,5,6,7,8,9,10}
    };
    vector<int> ans = S.spiralOrder(matrix);
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}


