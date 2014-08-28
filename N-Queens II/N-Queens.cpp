#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        if (n==0) return 0;

        int ret = 0;
        vector<int> ans1;
        for (int i=1;i<=n;i++)
            helper(1,n,ans1,i,ret);

        //ans->ret
        return ret;
    }

    void helper(int row, int n, vector<int>tmp, int col, int & ret ) {
        if (row> n || col > n) 
            return;
        if (check(row,col,tmp)) {
            tmp.push_back(col);
            if (tmp.size() == n)
                ret++;
            else {
                for(int i=1;i<=n;i++)
                    helper(row+1,n,tmp,i,ret);
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
    int n =50;
    Solution S;
    cout<<S.totalNQueens(n)<<endl;
}

