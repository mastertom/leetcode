#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows<=1 || s.length()<=nRows)
            return s;
        string ans (s.length(),'x');
        int screenStep = nRows+nRows-2;
        
        for(int cur=0, i=0 ; i<nRows ;i++){
            int copyStep = i%(nRows-1)==0? 1:2;
            int curB=cur;
            for (int j=i; j<s.length(); j+=screenStep){
                //copy(s,j,ans,cur);
                ans[cur]=s[j];

                cur+=copyStep;
                //cout<<cur<<" "<<ans<<endl;
            }
            if(copyStep==1) continue;
            int curC = cur;
            cur=curB+1;

            for (int j=nRows*2-2-i;j<s.length(); j+=screenStep){
                //copy(s,j,ans,cur);
                ans[cur]=s[j];
                cur+=copyStep;
                //cout<<cur<<" "<<ans<<endl;
            }
            if(cur>curC)
            cur--;
            
        }

        return ans;
    }

};

int main()
{
    string s ="PAYPALISHIRING";
    int nRows = 3;
    string ans;
    Solution So;
    ans = So.convert(s,nRows);
    cout<<ans<<endl;
    return 0;
}
