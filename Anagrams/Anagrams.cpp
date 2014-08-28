#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        vector<string> anagrams(vector<string> &strs) {
            vector<string> vec,anavec;
            unordered_map<string,vector<string> > mp;
            for(string s:strs){                    //sort every string and store groups of strings that are anagrams in a map
                string tmp=s;
                sort(tmp.begin(),tmp.end());
                mp[tmp].push_back(s);
            }
            for(auto map:mp){                      // find all anagrams
                if(map.second.size()>1)
                vec.insert(vec.end(),map.second.begin(),map.second.end());
            }
            return vec;
        }
    };
int main()
{
    Solution S;
    string s1 = "cat";
    string s2 = "dog";
    string s3 = "tac";
    string s4 = "bbb";
    string s5 = "god";
    vector<string> strs;
    strs.push_back(s1);
    strs.push_back(s2);
    strs.push_back(s3);
    strs.push_back(s4);
    strs.push_back(s5);


    vector<string> ans = S.anagrams(strs);
    for (string s:ans)
        cout<<s<<endl;

}
