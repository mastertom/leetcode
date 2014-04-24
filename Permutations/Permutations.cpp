#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void perm(vector<int> num,int k,int n, vector<vector<int> > &res){
        if (k==n){
            res.push_back(num);
        }else{
            for (int i=k;i<=n;i++){
                int tmp = num[k];
                num[k]=num[i];
                num[i]=tmp;
                 
                perm(num,k+1,n,res);
                 
                tmp = num[k];
                num[k]=num[i];
                num[i]=tmp;
            }
        }
    }
 
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        perm(num,0,(num.size()-1),res);
        return res;
    }
};

int main() {
    Solution so;
    int n[] = {1,2,3};
    vector<int> num;
    num.assign(n,n+sizeof(n)/sizeof(int));
    vector<vector<int> > ans = so.permute(num);
    for (int i=0;i<ans.size();i++) {
        for (int j=0;j<ans[i].size();j++)
            cout<<ans[i][j];
        cout<<endl;
    }
}
