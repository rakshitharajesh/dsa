#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n = capacity.size();
        map<pair<long long, long long>, long long>pair_set;
        long long ans = 0;
        // prefix sum
        vector<long long>sum(n, 0);
        for(int j = 0 ; j < n ; j++){
            sum[j] = (j > 0) ? sum[j - 1] + capacity[j] : capacity[j];
            // consider the number that was 2 indices behind
            // it is now valid as a left endpoint and can be added to the pair_set
            if(j >= 2){
                pair_set[{capacity[j - 2], sum[j - 2]}]++;
            }
            // check for a valid left point
            auto it = pair_set.find({capacity[j], sum[j] - capacity[j] * 2LL});
            if(it != pair_set.end())
                ans += it -> second;
        }
        return ans;
    }
};  