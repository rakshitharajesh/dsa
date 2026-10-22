#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        auto digitSum = [](int x){
            int s = 0;
            while(x != 0){
                s += x % 10;
                x /= 10;
            }
            return s;
        };
        int n = nums.size();
        vector<pair<int, int>>sumVal;
        for(int x : nums){
            sumVal.emplace_back(digitSum(x), x);
        }
        sort(sumVal.begin(), sumVal.end());
        unordered_map<int, int>rank;
        for(int i = 0 ; i < n ; i++)rank[sumVal[i].second] = i;
        vector<int>home;
        for(int x : nums)home.push_back(rank[x]);
        int swaps = 0;
        for(int i = 0 ; i < n ; ++i){
            while(home[i] != i){
                int j = home[i];
                swap(home[i], home[j]);
                swaps++;
            }
        }
        return swaps;

    }
};