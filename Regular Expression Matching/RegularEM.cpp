#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {

        return true;
    }
};

int main()
{
    Solution SO;
    char s[] = "aaa";
    char p[] = "a*a";
    cout<<isMatch(s,p)<<endl;
    return 0;
}
