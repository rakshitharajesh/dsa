#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        // sort the logs based on the time
        sort(logs.begin(), logs.end() ,[](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        // sort the queries
        int q = queries.size();
        // idx[i] holds the ith smallest value in queries array
        vector<int>idx(q);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){
            return queries[a] < queries[b];
        });
        // sliding window
        int left = 0;
        int right = 0;
        vector<int>ans(q);
        int logcount = logs.size();
        int active = 0;
        // represent the number of times server[i] receives a  request 
        vector<int>cnt(n + 1, 0);
        for(int i : idx){
            int q = queries[i];
            // l and r define the limits for wach query
            int l = q - x;int r = q;
            while(right < logcount && logs[right][1] <= r){
                cnt[logs[right][0]]++;
                if(cnt[logs[right++][0]] == 1)
                    active++;
            }
            while(left < right && logs[left][1] < l){
                cnt[logs[left][0]]--;
                if(cnt[logs[left++][0]] == 0){
                    active--;
                }
            }
            ans[i] = n - active;
        }
        return ans;
    }
};