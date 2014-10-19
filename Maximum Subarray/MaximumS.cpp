#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n==0) return 0;
        if (n==1) return A[0];
        int S[n];
        S[0] = A[0];
        for (int i=1;i<n;i++) {
            S[i] = max_two(S[i-1] + A[i],A[i]);
            cout<<S[i]<<endl;
        }
        return max_all(S,n);    
    }

    int max_two(int a, int b) {
        if (a>b)
            return a;
        else
            return b;
    }

    int max_all(int A[], int n) {
        int ans = A[0];
        for (int i=1;i<n;i++) {
            if (A[i] >ans)
                ans = A[i];
        }
        return ans;
    }
};

int main() {
    Solution S;
    int A[] = {-2,1,-3,4,-1,2,1,-5,4};
    int n = sizeof(A)/sizeof(int);

    int ans = S.maxSubArray(A,n);
    cout<<ans<<endl;

    return 0;
}
