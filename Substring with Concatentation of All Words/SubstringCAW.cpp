#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ans;

        return ans;
    }
};

int main()
{
    Solution So;
    string S = "barfoothefoobarman";
    vector<string> L;
    L.push_back("for");
    L.push_back("bar");
    vector <int > ans = So.findSubstring(S,L);
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
}
