class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> intervals;
    for (int i = 0; i < ranges.size(); ++i) {
        intervals.push_back(make_pair(max(0, i - ranges[i]), min(n, i + ranges[i])));
    }

    sort(intervals.begin(), intervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    });

    int current_end = 0;
    int next_end = 0;
    int taps = 0;
    int i = 0;

    while (i < intervals.size() && current_end < n) {
        while (i < intervals.size() && intervals[i].first <= current_end) {
            next_end = max(next_end, intervals[i].second);
            i++;
        }

        if (next_end <= current_end) {
            return -1;
        }

        taps++;
        current_end = next_end;
    }

    return (current_end >= n) ? taps : -1;

    }
};