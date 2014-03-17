#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        if (height.size()<=1)
            return 0;
        int i=0,j=height.size()-1;
        int max=-1,cur;
        while (i<j)
        {
            if(height[i]<height[j])
            {
                cur = (j-i)*height[i];
                i++;
            }
            else
            {
                cur = (j-i)*height[j];
                j--;
            }
            if (cur>max)
                max = cur;
        }
        return max;
    }
};

int main()
{
    Solution SO;
    vector<int> height;
    int h[] = {10,1};
    height.assign(h,h+sizeof(h)/sizeof(int));
    cout<<SO.maxArea(height)<<endl;
    return 0;
}
