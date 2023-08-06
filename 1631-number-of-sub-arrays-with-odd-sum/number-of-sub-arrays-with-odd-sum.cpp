class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int oddSumCount = 0; // Count of subarrays ending at the current index with an odd sum
        int evenSumCount = 0; // Count of subarrays ending at the current index with an even sum
        int totalCount = 0; // Total count of subarrays with an odd sum

        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 0) {
                // If the current element is even, the count of even-sum subarrays will increase by 1
                evenSumCount++;
            } else {
                // If the current element is odd, the count of even-sum subarrays will become the count of odd-sum subarrays
                // The count of odd-sum subarrays will become the count of even-sum subarrays plus 1
                int temp = evenSumCount;
                evenSumCount = oddSumCount;
                oddSumCount = temp + 1;
            }

            // Update the total count by adding the count of subarrays with an odd sum
            totalCount = (totalCount + oddSumCount) % 1000000007;
        }

        return totalCount;
    }
};
