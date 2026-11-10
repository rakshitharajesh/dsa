#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load){
        int n = arrival.size();
        set<int>available;  // ids of the free servers
        for(int j = 0 ; j < k ; j++)available.insert(j);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>busy; // store <endtime, serverid> for the busy servers
        vector<int>cnt(n, 0); // no of requests handled by each server
        for(int i = 0 ; i < n ; i++){
            // check which servers will be freed
            while(!busy.empty() && arrival[i] >= busy.top().first){
                available.insert(busy.top().second);
                busy.pop();
            }
            if(available.empty())
                continue;
            auto it = available.lower_bound(i % k);
            if(it == available.end())it = available.begin();
            int j = *it;    // server number

            available.erase(j);
            busy.push({arrival[i] + load[i], j});
            cnt[j]++;
            
        }
        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int>res;
        for(int j = 0 ; j < cnt.size() ; j++){
            if(cnt[j] == mx)
                res.push_back(j);
        }
        return res;

    }
    vector<int> busiestServers_(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        int maxLoad = INT_MIN;
        unordered_set<int> ans;
        vector<int>servers(k, 0);
        vector<int>cnt(k, 0); // number of requests each server handles
        for(int i = 0 ; i < n ; i++){
            int found = -1;
            // check if there is a free server
            for(int t = 0 ; t < k ; t++){
                int j = (i + k + t) % k;
                if(arrival[i] >= servers[j]){
                    found = j;
                    cnt[j]++;
                    break;
                }
            }
            if(found == -1)
                continue;
            servers[found] = arrival[i] + load[i];
            if(cnt[found] > maxLoad){
                maxLoad = cnt[found];
                ans.clear();
                ans.insert(found);
            }else if(cnt[found] == maxLoad){
                ans.insert(found);
            }
        }
        vector<int>vec(ans.begin(), ans.end());
        return vec;
    }
};