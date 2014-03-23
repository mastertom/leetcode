#include <iostream>
using namespace std;

class Solution {
public:
int removeElement(int A[], int n, int elem) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
int len = 0;
for (int i = 0; i < n; i++)
{   
    if (A[i] != elem)
        A[len++] = A[i];
}
return len;
}
};

int main()
{
    Solution SO;
    int A[] = {1,2,2,2,2,2,3,5};
    int elem = 2;
    cout<<SO.removeElement(A,sizeof(A)/sizeof(int),elem)<<endl;
}
