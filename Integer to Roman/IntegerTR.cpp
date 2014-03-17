#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int n[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string Roman[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string ans;
        int i=0;
        while (num>0)
        {
            int times =num/n[i];
            num = num - times*n[i];
            for (int j=0;j<times;j++)
                ans.append(Roman[i]);
            i++;
        }
        return ans;
    }
};

int main()
{
    Solution SO;
    int num = 8;
    cout<<SO.intToRoman(num)<<endl;
    return 0;
}
