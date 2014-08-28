#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<int> > ans;
        vector<vector<string> > ret;
        if (n==0) return ret;

        vector<int> ans1;
        for (int i=1;i<=n;i++)
            helper(1,n,ans1,i,ans);

        //ans->ret
        for (auto a:ans) {
            vector<string> solution;
            for (auto col:a) {
                string line(n,'.');
                line[col-1] = 'Q';
                solution.push_back(line);
            }
            ret.push_back(solution);
        }
        return ret;
    }

    void helper(int row, int n, vector<int>tmp, int col, vector<vector<int> > & result ) {
        if (row> n || col > n) 
            return;
        if (check(row,col,tmp)) {
            tmp.push_back(col);
            if (tmp.size() == n)
                result.push_back(tmp);
            else {
                for(int i=1;i<=n;i++)
                    helper(row+1,n,tmp,i,result);
            }
        }
    }

    bool check(int row, int col, vector<int>tmp) {
        for (int i=1;i< row;i++) 
            if (col==tmp[i-1] || abs(tmp[i-1]-col)==abs(i - row))
                return false;
        return true;

    }
};

int main() {
    int n =1;
    Solution S;
    vector<vector<string> > ans = S.solveNQueens(n);
    
    cout<<ans.size()<<endl;
}

