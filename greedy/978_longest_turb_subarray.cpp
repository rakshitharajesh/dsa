#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        int right = 1;
        int maxLen = 1;
        bool nextIncrease;
        while(left < right && left < n && right < n){
            if(arr[right] > arr[right - 1]){
                // we include this in our current possible answer
                if(nextIncrease || right == 1){
                    nextIncrease = false;
                    maxLen = max(maxLen, right - left + 1);
                    right++;
                }else{
                    // left pointer is moved forward
                    left = right - 1;
                    nextIncrease = true;
                }
            }else if(arr[right] < arr[right - 1]){
                if(!nextIncrease || right == 1){
                    // we include this in our current answer
                    nextIncrease = true;
                    maxLen = max(maxLen, right - left + 1);
                    right++;
                }else{
                    // move left forward
                    left = right - 1;
                    nextIncrease = false;
                }
            }else{
                // if arr[right] == arr[right - 1] then we move left = right
                // and move the right pointer forward
                left = right;
                right++;
            }
        }
        return maxLen;  
    }
};