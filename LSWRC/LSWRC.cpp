#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int maxcount = 0;
    int count = 0;
    int len = s.size();
    int index = 1;
    unordered_map<char,int> map;
    for (int i=0;i<len;i++)
    {
        if (map.find(s[i])== map.end())
        {
            count++;
            map[s[i]]=index++;
        }else
        {
            if (count>maxcount)
                maxcount = count;
            //update delete all shows before this
            int value = map[s[i]];
            int erasenum = 0;
            auto it = map.begin();
            while(it!=map.end())
            {
                if (it->second<value)
                {
                    map.erase(it++);
                    erasenum++;
                }
                else
                    ++it;
            }
            map[s[i]]=index++;
            count=count-erasenum;
        }
        //cout<<s[i]<<"\t"<<map[s[i]]<<"\t"<<count<<"\t"<<maxcount<<endl;

    }
    if (count>maxcount)
        maxcount =count;
    return maxcount;
}

int main()
{
    string s = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
    //s ="qopubjguxhxdipfzwswybgfylqvjzhar";
    cout<<lengthOfLongestSubstring(s)<<endl;
    cout<<"should be 12\n";
    return 0;
}
