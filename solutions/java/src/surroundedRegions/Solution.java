package surroundedRegions;

public class Solution {
    public void solve(char[][] board) {
        if (board.length == 0) {
            return;
        }
        int I = board.length, J = board[0].length;

        for (int i = 0; i < I; i++) {
            dfs(i, 0, I, J, board);
            dfs(i, J - 1, I, J, board);
        }

        for (int j = 1; j < J - 1; j++) {
            dfs(0, j, I, J, board);
            dfs(I - 1, j, I, J, board);
        }

        for (int i = 0; i < I; i++) {
            for (int j = 0; j < J; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'B') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    private int[] di = new int[] { 1, -1, 0, 0 };
    private int[] dj = new int[] { 0, 0, 1, -1 };

    private void dfs(int i, int j, int I, int J, char[][] board) {
        if (i < 0 || j < 0 || i >= I || j >= J || board[i][j] == 'X' || board[i][j] == 'B') {
            return;
        }
        board[i][j] = 'B';
        for (int k = 0; k < 4; k++) {
            dfs(i + di[k], j + dj[k], I, J, board);
        }
    }
}