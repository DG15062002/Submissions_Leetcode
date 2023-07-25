class Solution(object):
    def peakIndexInMountainArray(self, arr):
        n = len(arr)
        low = 1
        high = n
        while low <= high:
            mid = (low + high) // 2
            if arr[mid] > arr[mid - 1] and arr[mid] > arr[mid + 1]:
                break
            elif arr[mid] > arr[mid - 1] and arr[mid] < arr[mid + 1]:
                low = mid + 1
            else:
                high = mid - 1
        return mid
