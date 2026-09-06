#include <bits/stdc++.h>
using namespace std;

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

 // ignore this class
class MountainArray{
public:
    int get(int ind){
        return 1;
    }
    int length(){
        return 1;
    }
 };

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int low = 0;
        int high = n - 1;
        
        while(low < high){
            int mid = low + (high - low) / 2;
            if(mountainArr.get(mid) < mountainArr.get(mid + 1)){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        int pivot = low;
        // check the left side of the mountain
        low = 0;
        high = pivot;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int find = mountainArr.get(mid);
            if(find == target)
                return mid;
            if(target < find){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        low = pivot + 1;
        high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int find = mountainArr.get(mid);
            int left = mountainArr.get(low);
            int right = mountainArr.get(high);
            if(find == target)
                return mid;
            if(target > find){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return -1;
    }
};  