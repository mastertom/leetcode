#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        if (T.size()==0) return T;
        int m = S.size();
        int n = T.size();
        string minstring;
        unordered_map <char,int> ctn;
        vector <int> need(n,0);
        vector <int> s;
        vector <int> found(n,0);
        
        for (int i=0;i<n;i++)
        {
            if (!ctn.count(T[i]))
                ctn[T[i]]=i;
            need[ctn[T[i]]]++;
        }
        for (int i=0;i<m;i++)
        {
            if (ctn.count(S[i])>0)
                s.push_back(i);
        }

        if (s.size()==0) return "";
                
        int count=0;
        int begin=0;
        int length=INT_MAX;
        int start=s[0];
        int success = 0;
        for (int i=0;i<s.size();i++)
        {
            int index = s[i];
            int id = ctn[S[index]];
            found[id]++;
            if (found[id]<=need[id])
                count++;
            if (count==n)
            {
                success = 1;
                char c;
                do {
                    if ((index-s[begin]+1)<length)
                    {
                        length = index-s[begin]+1;
                        start = s[begin];
                    }
                    c = ctn[S[s[begin]]];
                    found[c]--;
                    begin++;
                } while (found[c]>=need[c]);
                count--;
            }
        }
        if (!success) return "";
        minstring = S.substr(start,length);                
        return minstring;
    }
};

int main()
{
    Solution SO;
    string S = "a";
    string T = "b";
    string ans = SO.minWindow(S,T);
    cout<<ans<<endl;
}
