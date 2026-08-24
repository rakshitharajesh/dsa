#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<pair<int, int>>dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>>pq;
        pq.push({grid[0][0], 0, 0});

        while(!pq.empty()){
            auto [m, x, y] = pq.top();pq.pop();
            for(const auto&[dx, dy] : dir){
                int nx = x + dx;
                int ny = y + dy;
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] != -1){
                    if(nx == n - 1 && ny == n - 1)
                        return max(m, grid[nx][ny]);
                    pq.push({max(m, grid[nx][ny]), nx, ny});
                    // mark the popped index -> visited 
                    // we found the best way to reach (x, y)
                    grid[nx][ny] = -1;
                }
            }
        }
        return 0;
    }
};