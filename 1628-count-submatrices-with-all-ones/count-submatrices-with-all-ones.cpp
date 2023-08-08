class Solution {
public:
    int numSubmat(vector<vector<int>>& arr) {
        int m = arr.size();
    int n = arr[0].size();
    int ans = 0;

    vector<vector<int>> p_arr(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (!arr[i][j])
                continue;

            if (j != n - 1)
                p_arr[i][j] += p_arr[i][j + 1];

            p_arr[i][j] += (int)arr[i][j];
        }
    }

    for (int j = 0; j < n; j++) {
        int i = m - 1;
        stack<pair<int, int>> q;
        int to_sum = 0;

        while (i >= 0) {
            int c = 0;

            while (!q.empty() && q.top().first > p_arr[i][j]) {
                to_sum -= (q.top().second + 1) * (q.top().first - p_arr[i][j]);
                c += q.top().second + 1;
                q.pop();
            }

            to_sum += p_arr[i][j];
            ans += to_sum;
            q.push({p_arr[i][j], c});
            i--;
        }
    }

    return ans;
    }
};