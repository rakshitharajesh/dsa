#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second < b.second;
        };
        // max heap
        // {0 or 1 or 2, freq}
        // 0 -> a, 1 -> b and 2 -> c
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>pq(cmp);
        if(a > 0)pq.push({0, a});
        if(b > 0)pq.push({1, b});
        if(c > 0)pq.push({2, c});
        while(!pq.empty()){
            // most frequent character
            auto [c, f] = pq.top();pq.pop();

            if(ans.size() >= 2 && ans[ans.size() - 2] == char(c + 'a') && ans[ans.size() - 1] == char(c + 'a')){
                if(pq.empty()){
                    break;
                }
                // we need to pick a new character
                auto [ch, fr] = pq.top();pq.pop();
                ans += char(ch + 'a');
                if(fr > 1){
                    pq.push({ch, fr - 1});
                }
            }
            ans += char(c + 'a');
            if(f > 1){
                pq.push({c, f - 1});
            }
        }
        return ans;
    }
};