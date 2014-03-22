#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string dict = "()[]{}";
        stack <int> st;
        for(int i=0;i<s.length();i++)
        {
            char c = s[i];
            int index= (int) dict.find(c);
            if (index >-1 )
            {
                if (index%2 ==0)
                    st.push(index);
                else
                {
                    if (st.size()==0)
                        return false;
                    int last = st.top();
                    st.pop();
                    if (index != (last+1))
                        return false;
                }
            }
        }
        if (st.size()==0)
            return true;
        else
            return false;
    }
};

int main()
{
    Solution So;
    string s ="]";
    cout<<So.isValid(s)<<endl;
}
