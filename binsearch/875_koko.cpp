#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool solve(long long mid, vector<int>& piles, int h){
        long long take = 0;
        for(int p : piles){
            take += p < mid ? 1 : (p + mid - 1) / mid;
        }
        return take <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int high = *max_element(piles.begin(), piles.end());
        sort(piles.begin(), piles.end());
        int low = 1;
        int ans = 0;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(solve(mid, piles, h)){
                ans = mid;
                high = mid - 1;
                // cout << ans << endl;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};