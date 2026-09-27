#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool loadPossible(int days, vector<int>& weights, int capacity){
        int daysTaken = 1;
        int currLoad = 0;
        for(int w : weights){
            if(currLoad + w > capacity){
                daysTaken++;
                currLoad = w;
            }else{
                currLoad += w;
            }
        }
        return daysTaken <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(loadPossible(days, weights, mid)){
                high = mid - 1;
                // cout << mid << endl;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};