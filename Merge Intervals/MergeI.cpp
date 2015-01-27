#include <iostream>
#include <vector>
#include <stack>
using namespace std;


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    static bool cmp(Interval a, Interval b){
        return a.start < b.start;
    }

    vector<Interval> merge(vector<Interval> &intervals) {
        stack<Interval> s;
        vector<Interval> result;
        if(intervals.empty())return result;

        sort(intervals.begin(),intervals.end(),cmp);

        s.push(intervals[0]);
        for(int i=1;i<intervals.size();i++){       //1.merge in stack
            if(s.top().end>=intervals[i].start) s.top().end=max( s.top().end, intervals[i].end );
            else s.push(intervals[i]);                          
        }

        while( !s.empty() ){                    //2.output result
            result.push_back(s.top());
            s.pop();
        }

        return result;
    }
};

int main() {
    Solution S;
    Interval i1(1,3);
    Interval i2(2,6);
    Interval i3(8,10);
    Interval i4(15,18);
    vector <Interval> intervals;
    intervals.push_back(i1);
    intervals.push_back(i2);
    intervals.push_back(i3);
    intervals.push_back(i4);
    vector <Interval> solution = S.merge(intervals);
    for (int i =0;i<solution.size();i++){
        cout<<solution[i].start<<" "<<solution[i].end;
    }
    cout<<endl;
    return 0;
}
