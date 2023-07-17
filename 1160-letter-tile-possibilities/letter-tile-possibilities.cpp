class Solution {
public:
    void solve(const string& tiles, string& combination, vector<bool>& visited, set<string>& st) {
        for (int i = 0; i < tiles.size(); i++) {
            if (visited[i]) {
                continue;
            }
            
            combination.push_back(tiles[i]);
            visited[i] = true;
            st.insert(combination);
            solve(tiles, combination, visited, st);
            combination.pop_back();
            visited[i] = false;
        }
    }
    
    int numTilePossibilities(string tiles) {
        int ans = 0;
        vector<bool> visited(tiles.size(), false);
        string combination = "";
        set<string> st; 
        
        solve(tiles, combination, visited, st);
        return st.size();
    }
};
