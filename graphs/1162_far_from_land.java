import java.util.Queue;
import java.util.ArrayDeque;

class Solution {
    public int[][] dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    public int maxDistance(int[][] grid) {
        int n = grid.length;
        Queue<int[]>q = new ArrayDeque<int[]>();
        boolean[][]visited = new boolean[n][n];
        // add all the land cells to the queue
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    q.offer(new int[]{i, j});
                }
            }
        }

        int maxDist = -1;

        // edge case - there are no water cells
        if(q.size() == n * n)
            return -1;

        while(!q.isEmpty()){
            int size = q.size();
            maxDist++;
            for(int i = 0 ; i < size ; i++){
                int[] curr = q.poll();
                int x = curr[0];int y = curr[1];
                for(int[] d : dir){
                    int nx = x + d[0];int ny = y + d[1];
                    if(nx < n && nx >= 0 && ny < n && ny >= 0 && !visited[nx][ny] && grid[nx][ny] == 0){
                        visited[nx][ny] = true;
                        q.offer(new int[]{nx, ny});
                    }
                }
            }
        }
        return maxDist;
    }
}