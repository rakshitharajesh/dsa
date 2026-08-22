#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<pair<int, int>>dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        using t = tuple<int, int, int>;
        priority_queue<t, vector<t>, greater<t>>pq;
        pq.push({0, 0, 0});
        // the minimum effort to reach (i, j)
        vector<vector<int>>minEffort(m, vector<int>(n, INT_MAX));
        minEffort[0][0] = 0;
        while(!pq.empty()){
            const auto[effort, x, y] = pq.top();pq.pop();
            if(x == m - 1 && y == n - 1)
                return effort;
            // we already found a better way to reach this node
            if(minEffort[x][y] < effort)
                continue;
            for(const auto& [dx, dy] : dir){
                int nx = x + dx;int ny = y + dy;
                if(nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;
                
                int currJump = abs(heights[nx][ny] - heights[x][y]);
                //cout << heights[x][y] << " and " << heights[nx][ny] << ":" << endl;
                //cout << nx << ", " << ny << " " << x << ", " << y << " " << (heights[nx][ny] - heights[x][y]) << endl;
                
                int currEffort = max(currJump, effort);
                if(currEffort < minEffort[nx][ny]){
                    minEffort[nx][ny] = currEffort;
                    pq.push({currEffort, nx, ny});
                }
                
            }
        }
        return 0;
    }
};