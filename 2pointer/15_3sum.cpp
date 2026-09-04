#include <bits/stdc++.h>
using namespace std;
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int n = nums.length;
        List<List<Integer>>ans = new ArrayList<>();
        Arrays.sort(nums);
        for(int i = 0 ; i < n ; i++){
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int target = -nums[i];
            int left = i + 1;
            int right = n - 1;
            while(left < right){
                int sum = nums[left] + nums[right];
                if(sum == target){
                    ans.add(new ArrayList<>(List.of(nums[i], nums[left], nums[right])));
                    left++;right--;
                    // duplicates ignored
                    while(left < right && nums[left] == nums[left - 1])
                        left++;
                    while(left < right && nums[right] == nums[right + 1])
                        right--;
                }else if(sum < target){
                    left++;
                    while(left < right && nums[left] == nums[left - 1])left++;
                }else{
                    right--;
                    while(left > right && nums[right] == nums[right + 1])
                        right--;
                }
            }
        }
        return ans;
    }
}