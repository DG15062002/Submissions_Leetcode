class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        vector<int> nums3 = nums1;
        int count = 0;
        while(i <  m && j < n){
            if(nums1[i] <= nums2[j]){
            nums3[count++] = nums1[i];
            i++;
        }
        else{
            nums3[count++] = nums2[j];
            j++;
        }
        }
        while(i < m)
        nums3[count++] = nums1[i++];
        while(j < n)
        nums3[count++] = nums2[j++];
        nums1 = nums3;
    }
};