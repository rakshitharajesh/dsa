#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int partition(vector<int>& arr, int low, int high){
        int pivot = arr[high], pivotloc = low;
        // inserting array elements greater than pivot
        // to the left of pivot
        for(int i = low ; i < high ; i++){
            if(arr[i] > pivot){
                swap(arr[i], arr[pivotloc]);
                pivotloc++;
            }
        }
        // finally put the pivot in the identified pivotloc
        swap(arr[high], arr[pivotloc]);
        return pivotloc;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return findKth(nums, 0, n - 1, k);
    }
    int findKth(vector<int>& nums, int low, int high, int k){
        int p = partition(nums, low, high);
        if(p == k - 1)
            return nums[k - 1];
        else if(p < k - 1){
            // search the right half
            return findKth(nums, p + 1, high, k);
        }
        return findKth(nums, low, p - 1, k);
    }
};