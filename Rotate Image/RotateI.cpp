#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if (n<=1)
            return;

        int h,w;
        if (n%2 ==0)
            h = w = n/2;
        else {
            w = (int) (n/2) ;
            h = w+1;
        }
        for (int i=0;i<h;i++)
            for (int j=0;j<w;j++) {
                rotateone(matrix, i,j,n);
                }
    }

    void rotateone(vector<vector<int> > &matrix,int i,int j,int n) {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[n-1-j][i];
        matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
        matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
        matrix[j][n-1-i] = tmp;
    }

    void printm(vector<vector<int> > matrix)
    {
        int n = matrix.size();
        for (int i =0;i<n;i++) {
            for (int j=0;j<n;j++)
                cout<<matrix[i][j]<<"\t";
            cout<<endl;
        }
    }
};

int main()
{
    int r1[4] = {1,2,3,4};
    int r2[4] = {5,6,7,8};
    int r3[4] = {9,10,11,12};
    int r4[4] = {13,14,15,16};

    vector<int> v1(r1,r1+4) ;
    vector<int> v2(r2,r2+4) ;
    vector<int> v3(r3,r3+4);
    vector<int> v4(r4,r4+4) ;

    vector<vector<int> > m;
    m.push_back(v1);
    m.push_back(v2);
    m.push_back(v3);
    m.push_back(v4);

    Solution So;
    So.printm (m);
    So.rotate(m);
    cout<<endl;
    So.printm(m);

    return 0;
}



