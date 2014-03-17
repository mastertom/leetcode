lass Solution {
public:
    string longestPalindrome(string s) {
        int n =s.length();
        if (n<=1)
            return s;
        string ans=s.substr(0,1);
        for (int i=0;i<n;i++)
        {
            string longestodd = expandodd(s,i);
            if (longestodd.length() > ans.length())
                ans=longestodd;
        }
        for (int i=0;i<n-1;i++)
        {
            string longesteven = expandeven(s,i,i+1);
            if (longesteven.length() > ans.length())
                ans=longesteven;
        }
        return ans;
    }
    string expandodd(string s,int i)
    {
        int n =s.length();
        int l=i;
        int r=i;
        while(l>=0 && r<n && s[l]==s[r])
        {
            l--;r++;
        }
        return s.substr(l+1,r-l-1);
    }
    string expandeven(string s,int i,int j)
    {
        if (s[i]!=s[j])
            return s.substr(i,1);
        int n =s.length();
        int l=i;
        int r=j;
        while(l>=0 && r<n && s[l]==s[r])
        {
            l--;r++;
        }
        return s.substr(l+1,r-l-1);
    }
};

