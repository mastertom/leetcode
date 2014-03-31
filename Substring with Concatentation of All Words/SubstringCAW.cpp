#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ans;
        int m=S.size();
        int n=L.size();
        if (n<1) return ans;
        int l=L[0].size();
        unordered_map<string,int> wtn;
        vector<int> need(n,0);
        vector<int> s(m,-1);

        for (int i=0;i<n;i++)
        {
            if (!wtn.count(L[i]))
                    wtn[L[i]]=i;
            need[wtn[L[i]]]++;
        }
        //cout<<wtn[L[0]]<<L[0]<<endl;

        for (int i=0;i<m-l+1;i++)
        {
            //cout<<i<<endl;
            string key=S.substr(i,l);
            //cout<<key<<endl;
            if (wtn.count(key)>0) s[i]=wtn[key];
        }

        for (int offset=0; offset<l;offset++)
        {
            vector<int> found(n,0);
            int count=0;
            int begin =offset;
            for (int i=offset;i<m-l+1;i+=l)
            {
                if (s[i]<0)
                {
                    begin = i+l;
                    count=0;
                    found.clear();
                    found.resize(n,0);
                } else
                {
                    //cout<<"character:"<<S[i]<<" begin "<<begin;
                    int id = s[i];
                    found[id]++;
                    if (need[id] && found[id]<=need[id])
                        count++;
                    if (count == n)
                    {
                        ans.push_back(begin);
                    }
                    if (((i-begin)/l+1) ==n)
                    {
                        id =s[begin];
                        if (need[id] && found[id]==need[id])
                            count--;
                        found[s[begin]]--;
                        begin +=l;
                    }
                }
                //cout<<" ans size: "<<ans.size()<<endl;
                //cout<<" found "<<found[0]<<" "<<found[1]<<endl;
            }


        }
        return ans;
    }
};

int main()
{
    Solution So;
    string S = "mississippi";
    vector<string> L;
    L.push_back("is");
    //L.push_back("b");
    vector <int > ans = So.findSubstring(S,L);
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
}
