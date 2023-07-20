class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(auto i : asteroids){
            int check = 0;
            if(ans.empty() || i > 0)
            ans.push_back(i);
            else
            if(!ans.empty() && ans.back() > 0){
                while(!ans.empty() && ans.back() > 0){
                    int temp = ans.back();
                    if(-i > temp){
                        ans.pop_back();
                        check =1;
                    }
                    else
                    if(-i == temp){
                        ans.pop_back();
                        check = 0;
                        break;
                    }
                    else
                    {check = 0;
                    break;}
                }
            if(check == 1)
            ans.push_back(i);}
        else ans.push_back(i);
    }
    return ans;
    }
};