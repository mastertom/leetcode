#include <iostream>
using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {

        int last =0;
        for (int i=0;i<n;i++)
        {
            if (i > last)
                return false;
            if (i + A[i] > last)
                last = i + A[i];
        }
        return true;
    }
};

int main() {
    Solution So;
    int A[3] = {1,0,0};
    cout<<So.canJump(A,3)<<endl;
    
    return 0;
}
