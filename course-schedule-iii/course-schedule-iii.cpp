class Solution {
public:
    // static bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    //     // Sort by the first value
    //     if (a.first < b.first) {
    //         return true;
    //     }
    //     else if (a.first > b.first) {
    //         return false;
    //     }
    //     else {
    //         // Sort by the second value if the first values are equal
    //         return a.second < b.second;
    //     }
    // }

    // static bool compare2(const pair<int, int>& a, const pair<int, int>& b) {
    //     // Sort by the second value in descending order
    //     if (a.second > b.second) {
    //         return true;
    //     }
    //     else if (a.second < b.second) {
    //         return false;
    //     }
    //     else {
    //         // Sort by the first value if the second values are equal
    //         return a.first < b.first;
    //     }
    // }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // Sort courses by end day in ascending order
        });

        priority_queue<int> pq; // Max heap to store the durations of selected courses
        int currentDay = 0;

        for (const auto& course : courses) {
            int duration = course[0];
            int endDay = course[1];

            if (currentDay + duration <= endDay) {
                pq.push(duration); // Include the course
                currentDay += duration;
            }
            else if (!pq.empty() && duration < pq.top()) {
                currentDay -= pq.top(); // Replace the longest duration course
                pq.pop();
                pq.push(duration);
                currentDay += duration;
            }
        }

        return pq.size();
    }
};
