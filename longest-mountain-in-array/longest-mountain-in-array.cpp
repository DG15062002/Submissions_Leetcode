class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return 0;
        int ans = 0,temp = 0,check1 = 0, check2 = 0;
        for(int  i = 1; i < n; i++){
            if(arr[i] > arr[i-1]){
                if(check2 == 1){
                    ans = max(temp,ans);
                    check2 = 0;
                    check1 = 1;
                    temp = 2;
                }
                else{
                    if(check1 == 0){
                    temp =2;
                    check1 = 1;
                    }
                    else
                    temp++;
                }
            }
            else if(arr[i] < arr[i-1]){
                if(check1 == 1){
                    if(check2 == 0)
                    check2 =1;
                    temp++;
                }
                else{
                temp = 0;
                check2 = 0;
                check1 = 0;
            }
            }
            else{
                if(check1 == 1 && check2 == 1)
                 ans = max(temp,ans);
                 check1 = 0;
                 check2 = 0;
                 temp = 0;
            }
        }
        if(check1 == 1 && check2 == 1)
        ans = max(temp,ans);
        return ans;
    }
};