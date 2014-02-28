#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) 
{
    vector<int> index;
    int n = numbers.size();
    int ii;
    std::unordered_map<int, int> map;
    std::unordered_map<int, int>::const_iterator got;
    for (int i=0;i<n;i++)
    {
        //map int into map
        got = map.find(numbers[i]);
        if (got == map.end())
            map[numbers[i]]=i;
        got = map.find(target-numbers[i]);
        if (got != map.end())
        {
            ii = map[target-numbers[i]];
            if (i!=ii)
            {
                if (i<ii)
                {
                    index.push_back(i+1);
                    index.push_back(ii+1);
                }else
                {
                    index.push_back(ii+1);
                    index.push_back(i+1);
                }
                goto endfor;
            } 
        }
    }
    endfor:
    
    return index;
}

int main()
{
    int target =10;
    static const int arr[] = {2,7,8,11};
    vector<int> numbers (arr, arr + sizeof(arr) / sizeof(arr[0]) );
    vector<int> index=twoSum(numbers,10);
    cout<<index[0]<<index[1]<<endl;
    return 0;
}
