#include <iostream>
using namespace std;

class Solution {
public:
    int jump(int A[], int n){
        int ret = 0;
        int last =0;
        int curr = 0;
        for(int i=0;i<n;i++) {
            if (i>last) {
                if ( (curr == last) && (last < n-1) )
                    return -1;
                last = curr;
                ret++;
            }
            curr = max(curr, i+A[i]);
        }
        return ret;
        
    }
};


int main() {
    Solution So;
    int A[5] = {2,3,1,1,4};
    cout<<So.jump(A,5)<<endl;
    
    return 0;
}
