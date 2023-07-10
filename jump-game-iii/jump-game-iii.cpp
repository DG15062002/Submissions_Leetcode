class Solution {
public:
    bool isValid(int index, vector<int> & arr){
       if (index >= arr.size() || index < 0) {
        return false;
    }
    return true;
    }
    bool canReach(vector<int>& arr, int start) {
      if (start < 0 || start >= arr.size() || arr[start] < 0) {
        return false;
    }
    if (arr[start] == 0) {
        return true;
    }
    
    int jump = arr[start];
    arr[start] = -1;  // Mark the current position as visited
    
    return canReach(arr, start + jump) || canReach(arr, start - jump);
    }
};