class Solution {
    public void solve(char[][] board) {
        int m = board.length;
        int n = board[0].length;
        boolean[][] visited = new boolean[m][n];
        // dfs from the 4 edges
        for(int i = 0 ; i < m ; i++){
            if(board[i][0] == 'O')
                dfs(board, i, 0, visited);
            if(board[i][n - 1] == 'O')
                dfs(board, i, n - 1, visited);
        }
        for(int j = 0 ; j < n ; j++){
            if(board[0][j] == 'O')
                dfs(board, 0, j, visited);
            if(board[m - 1][j] == 'O')
                dfs(board, m - 1, j, visited);
        }
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++)
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == 'o')
                    board[i][j] = 'O';
        }
    }
    void dfs(char[][] board, int i, int j, boolean[][]visited){
        int m = board.length;
        int n = board[0].length;
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || board[i][j] != 'O')
            return;
        visited[i][j] = true;
        board[i][j] = 'o';
        dfs(board, i + 1, j, visited);
        dfs(board, i - 1, j, visited);
        dfs(board, i, j + 1, visited);
        dfs(board, i, j - 1, visited);
    }
}