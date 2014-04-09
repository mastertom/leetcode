#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.length(),n2 = num2.length();
        if (n1<n2) //swap
        {
            string tmps;
            tmps = num1; num1 = num2; num2 = tmps;
        }
        n1 = num1.length(),n2 = num2.length(); // num1 longer than num2
        if (num1 == "0" || num2 == "0")
            return "0";
        vector<string> backup;
        string cur="0";
        backup.push_back(cur);
        for (int i=1;i<10;i++)
        {
            cur = add(cur,num1);
            backup.push_back(cur);
        }
        string ans = "0";
        for (int i=0;i<n2;i++)
        {
            ans = add(multiply10(ans),backup[num2[i]-'0']);
        }
        return ans;
    }
    string add(string num1, string num2) {
        int n1 = num1.length(),n2 = num2.length();
        int carry = 0;
        int i1=n1-1,i2=n2-1;
        string ans;
        while (i1>=0 || i2>=0)
        {
            int sum;
            if (i1>=0 && i2>=0)
                sum = num1[i1]- '0' + num2[i2] - '0' + carry;
            else if (i1>=0 && i2<0)
                sum = num1[i1]- '0' + carry;
            else if (i1<0 && i2>=0)
                sum = num2[i2] - '0' + carry;
            if ( sum >=10 ) {
                ans.push_back(sum%10 +'0');
                carry = 1;
            }else {
                ans.push_back(sum + '0');
                carry = 0;
            }
            i1--;
            i2--;
        }
        if (carry) {
            ans.push_back('1');
            return reverse(ans);
        } else
            return reverse(ans);
        
    }
    string multiply10(string num1) {
        if (num1=="0")
            return "0";
        return num1 + "0";
    }
    string reverse(string num) {
        return string ( num.rbegin(), num.rend() );
    }
};


int main()
{
    Solution So;
    string num1 = "1";
    string num2 = "1";
    //122987502
    cout<<So.multiply(num1,num2)<<endl;
}
