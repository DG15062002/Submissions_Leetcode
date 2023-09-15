class Solution {
public:
    
    vector<int> par;
    
    int find_par(int x)
    {
        if(par[x] == x)
            return x;
        return find_par(par[x]);
    }
    
    int minCostConnectPoints(vector<vector<int>>& p) {
        
        int n = p.size();
        par.resize(n);
        for(int i=0;i<n;i++)
        {
            par[i] = i;
        }
        priority_queue<vector<int>> pq;
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(i==j)
                    continue;
                pq.push({-(abs(p[i][0]-p[j][0]) + abs(p[i][1]-p[j][1])),i,j});
            }
        }
        
        int res = 0,i=0;
        while(i<n-1)
        {
            vector<int> t = pq.top();
            int p1 = find_par(t[1]);
            int p2 = find_par(t[2]);
            if(p1!=p2)
            {
                par[p1] = p2;
                res+=(-t[0]);
                i++;
            }
            pq.pop();
            
        }
        return res;
    }
};