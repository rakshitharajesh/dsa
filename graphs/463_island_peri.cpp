#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<pair<int, int>>dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int islandPerimeter(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    ans += 4;
                    // remove 1 from both the current and the top cell
                    if(i > 0 && grid[i - 1][j] == 1)
                        ans -=2;
                    // remove 1 from the current and the left cell perimeter
                    if(j > 0 && grid[i][j - 1] == 1)
                        ans -= 2;
                }
            }   
        }
        return ans;
    }
    // bfs based approach
    int islandPerimeter_(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>>q;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});grid[i][j] = -1;
                    int ans = solve(q, grid);
                    return ans;
                }
            }
        }
        return -1;
    }
    int solve(queue<pair<int, int>>& q, vector<vector<int>>& grid){
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        while(!q.empty()){
            auto [x, y] = q.front();q.pop();
            //cout << x << " " << y << endl;
            for(auto [dx, dy] : dir){
                int nx = x + dx;int ny = y + dy;
                if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                    if(grid[nx][ny] == -1)
                        continue;
                    if(grid[nx][ny] == 1){
                        q.push({nx, ny});
                        grid[nx][ny] = -1;
                    }
                    else
                        ans++;
                }else
                    ans++;
            }
        }
        return ans;
    }
};