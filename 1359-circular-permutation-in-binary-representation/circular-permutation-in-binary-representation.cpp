class Solution {
public:
vector<int> grayCode(int n) {
         vector<int> res;
        res.push_back( 0 );
        for( int k = 0; k<n; k++ ) {
            int i = res.size(), t = (1<<k) ;
            while( i ) {
                int temp = res[--i] | t;
                res.push_back( temp );
            }
        }
        return res;
    }
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans = grayCode(n),res;
        auto it = find(ans.begin(),ans.end(),start);
        if(it == ans.begin()) return ans;
        for(int i = (int)(it-ans.begin()); i < ans.size(); i++)
        res.push_back(ans[i]);
        for(int i = 0; i < (int)(it-ans.begin()); i++)
        res.push_back(ans[i]);
        return res;
    }
};