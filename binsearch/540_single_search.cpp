#include <stdio.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while(low < high){
            int mid = low + (high - low) / 2;
            if(mid % 2 == 0){
                // if the index if even -> the next element should be the same
                if(nums[mid] == nums[mid + 1]){
                    low = mid + 2;
                }else{
                    high = mid;
                }
            }else{
                // if the index is odd -> next prev elements should be the same
                if(nums[mid] == nums[mid - 1]){
                    low = mid + 1;
                }else{
                    high = mid;
                }
            }
        }
        return nums[low];
    }
};