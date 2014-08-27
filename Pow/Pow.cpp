#include <iostream>
using namespace std;

class Solution {
public:
    double power(double x, int n) {
	if (n == 0)
		return 1;
 
	double v = power(x, n / 2);
 
	if (n % 2 == 0) {
		return v * v;
	} else {
		return v * v * x;
	}
}
 
    double pow(double x, int n) {
	if (n < 0) {
		return 1 / power(x, -n);
	} else {
		return power(x, n);
	}
}
};

int main()
{
    Solution S;
    double x =10.0;
    int n = 5;
    cout<<S.pow(x,n)<<endl;
}
