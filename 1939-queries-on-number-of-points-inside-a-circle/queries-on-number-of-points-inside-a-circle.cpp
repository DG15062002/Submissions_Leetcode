class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++){
            int xc = queries[i][0];
            int yc = queries[i][1];
            int r = queries[i][2];
            int count = 0;
            for(int j = 0; j < points.size(); j++){
                (pow(points[j][0]-xc,2)+pow(points[j][1]-yc,2) <= pow(r,2)) ? count++:count;
            }
            ans.push_back(count);
        }
        return ans;
    }
};