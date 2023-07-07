class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int,int> mp1;// {num, freq}
        unordered_map<int, int> mp2;// {freq,cnt}
        int ans = 0;   
        for(int i = 0; i < nums.size(); i++){
            mp1[nums[i]]++; int frq = mp1[nums[i]];
            if(frq > 1){
                mp2[frq-1]--; if(mp2[frq-1] == 0){mp2.erase(frq-1);}
                mp2[frq]++;
            }
            else if(frq == 1) mp2[frq]++;
        //check whether current prefix [0,i] is eligilble to be ans
        if(mp2.size() > 2) {continue;} // no ans
        // case 1 :- 
        if(mp2.size()==1){
                auto it= mp2.begin(); int freq= it->first; int cnt= it->second;
                // So, there are 'cnt' unique elements whose frequency is 'freq'
                
                // SUB-CASE1: ABCDEF (all ele ocuurs only once)
                if(freq==1){ ans= i+1; }
                // SUB-CASE2: AAAAAA (only one uniue element)
                if(cnt==1){ ans= i+1; }
            }
            // CASE 2: -->
            if(mp2.size()==2){
                 auto it= mp2.begin(); int freq1= it->first; int cnt1= it->second;
                 it++; int freq2= it->first; int cnt2= it->second;
                
                // SUB-CASE1: AABBCCD
                if((freq1==1 && cnt1==1) || (freq2==1 && cnt2==1)){  ans= i+1;  }
                // SUB-CASE2: AABBCCDDD
                if((cnt1==1 && freq1==freq2+1) || (cnt2==1 && freq2==freq1+1)){  ans= i+1;  }
            }
       
    }
     return ans;
    }
};