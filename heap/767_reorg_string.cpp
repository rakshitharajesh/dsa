#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second < b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>pq(cmp);
        vector<int>freq(26, 0);
        for(char c : s){
            freq[c - 'a']++;
        }
        for(int i = 0 ; i < 26 ; i++){
            if(freq[i] > 0){
                pq.push({char(i + 'a'), freq[i]});
            }
        }
        while(!pq.empty()){
            // most frequent element
            auto [ch, f] = pq.top();pq.pop();
            // if the current char is hte same as prev -> check the next frequent char
            if(!ans.empty() && ans.back() == ch){
                // no other char -> return ""
                if(pq.empty())
                    return "";
                auto [c, f_] = pq.top();pq.pop();
                ans += c;
                if(f_ > 1)
                    pq.push({c, f_ - 1});
            }
            // then push the most frequent character
            ans += ch;
            if(f > 1){
                pq.push({ch, f - 1});
            }
        }
        return ans;
    }
};