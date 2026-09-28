#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        vector<int>occupied(1001, 0);
        for(const auto& trip : trips){
            occupied[trip[1]] += trip[0];
            occupied[trip[2]] -= trip[0];
            int current = 0;
            for(int p : occupied){
                current += p;
                if(current > capacity)    
                    return false;
            }
        }
        return true;
    }
};