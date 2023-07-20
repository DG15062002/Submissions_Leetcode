class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long res = mass;
        sort(asteroids.begin(),asteroids.end());
        for(auto i : asteroids){
            if(res < i) return false;
            res+=i;
        }
        return true;
    }
};