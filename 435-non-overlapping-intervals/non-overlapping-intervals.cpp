class Solution {
public:
struct Interval {
    int start;
    int end;
    Interval(int s, int e) : start(s), end(e) {}
};

static bool compareIntervals(Interval& a, Interval& b) {
    return a.end < b.end;
}

int maxNonOverlappingIntervals(vector<Interval>& intervals) {
    if (intervals.empty()) return 0;

    // Sort intervals based on ending points
    sort(intervals.begin(), intervals.end(), compareIntervals);

    int count = 1; // Count of non-overlapping intervals
    int lastEnding = intervals[0].end; // Ending point of the last selected interval

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].start >= lastEnding) {
            count++;
            lastEnding = intervals[i].end;
        }
    }

    return count;
}

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> v;
        for(auto i : intervals){
            v.push_back({i[0],i[1]});
        }
        return n-maxNonOverlappingIntervals(v);
    }
};