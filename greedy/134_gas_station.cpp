#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = cost.size();
        vector<int>net(n);
        int c = 0;
        // net represents the gas gained at each point
        for(int i = 0 ; i < n ; i++){
            net[i] = gas[i] - cost[i];
            c += net[i];
        }
        if(c < 0)
            return -1;
        // curr represents the current fuel level - this should never be negative
        int start = 0;
        int curr = 0;
        for(int end = 0 ; end < n ; end++){
            curr += net[end];
            while(start <= end && curr < 0){
                curr -= net[start++];
            }
        }
        return curr >= 0 ? start : -1;
    }
};  