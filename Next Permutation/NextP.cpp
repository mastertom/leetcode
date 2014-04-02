#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int n = num.size();
        int tmp;
        if (n<=1) return;
        if (n==2) {
            reverse(num,0,1);
            return;
        }
        //find the last increasing pair
        int lastfirst = 0;
        int lastsecond = 0;
        int first =0;
        int second = 1;
        while (second<n)
        {
            if (num[second]>num[first])
            {
                lastfirst = first;
                lastsecond = second;
            }
            first++;
            second++;
        }
        if (lastfirst==lastsecond) {
            reverse(num,0,n-1);
            return;
        }
        tmp = num[lastfirst]; // the value that change with first
        int target;
        for(int i =lastsecond;i<n;i++)
        {
            if (num[i]>tmp)
            {
                target = i;
            }else
                break;
        }
        num[lastfirst] = num[target];
        num[target] = tmp;
        // reverse num between secondlast and n-1
        reverse(num,lastsecond,n-1);
    }
    void reverse(vector<int> &num, int from, int to)
    {
        if (from == to)
            return;
        int tmp;
        while (from<to)
        {
            tmp=num[from];
            num[from]=num[to];
            num[to]=tmp;
            from++;
            to--;
        }
    }
};

int main()
{
    Solution SO;
    int n[] = {3,2};
    vector <int > num;
    num.assign(n,n+sizeof(n)/sizeof(int));
    SO.nextPermutation(num);
    for (int i=0;i<num.size();i++)
        cout<<num[i]<<endl;
}
