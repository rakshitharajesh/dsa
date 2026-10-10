#include <bits/stdc++.h>
using namespace std;
class Solution {
    public int removeElement(int[] nums, int val) {
        int k = 0; // position where the next non-val value needs to be 
        int n = nums.length;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] != val){
                nums[k++] = nums[i];
            }
        }
        return k;
    }
}