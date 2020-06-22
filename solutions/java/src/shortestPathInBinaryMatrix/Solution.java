package shortestPathInBinaryMatrix;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        if (grid.length == 0) {
            return 0;
        }
        int N = grid.length;
        if (grid[0][0] == 1 || grid[N - 1][N - 1] == 1) {
            return -1;
        }
        if (N == 1) {
            return 1;
        }
        
        int[] dx = new int[]{-1, 0, 1, -1, 1, -1, 0, 1};
        int[] dy = new int[]{-1, -1, -1, 0, 0, 1, 1, 1};
        List<Integer> queue = new ArrayList<>();  // queue[x1, y1, x2, y2, ...]
        queue.add(0);
        queue.add(0);
        grid[0][0] = 1;
        int pathLength = 1;
        while (!queue.isEmpty()) {
            int qSize = queue.size();
            pathLength++;
            while (qSize > 0) {
                int x0 = queue.get(0);
                int y0 = queue.get(1);
                queue.remove(0);
                queue.remove(0);
                qSize -= 2;
                for (int k = 0; k < dx.length; k++) {
                    int x = x0 + dx[k];
                    int y = y0 + dy[k];
                    if (x < 0 || x >= N || y < 0 || y >= N || grid[x][y] == 1) {
                        continue;
                    }
                    if (x == N - 1 && y == N - 1) {
                        return pathLength;
                    }
                    grid[x][y] = 1;
                    queue.add(x);
                    queue.add(y);
                }
            }
        }
        return -1; 
    }
}