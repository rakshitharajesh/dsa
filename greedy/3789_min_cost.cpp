#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long common = min(need1, need2);
        // for the common goods
        long long cost = common * min((long long)cost1 + cost2, (long long)costBoth);
        cost += (need1 - common) * min(cost1, costBoth);
        cost += (need2 - common) * min(cost2, costBoth);
        return cost;
    }
};