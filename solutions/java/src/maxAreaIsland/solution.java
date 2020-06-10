package maxAreaIsland;

import java.util.ArrayList;
import java.util.List;

public class solution {
  private static int[] dx = new int[] {-1, 1, 0, 0};
  private static int[] dy = new int[] {0, 0, 1, -1};

  public static void main(String[] args) {
    int[][] grid = new int[][] {{1, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 1, 1}, {0, 0, 1, 1}};
    int area = maxAreaOfIsland(grid);
  }

  public static int maxAreaOfIsland(int[][] grid) {
    if (grid.length == 0) {
      return 0;
    }
    int maxArea = 0;
    int I = grid.length, J = grid[0].length;
    for (int i = 0; i < I; i++) {
      for (int j = 0; j < J; j++) {
        if (grid[i][j] == 1) {
          //          int area = dfs(i, j, I, J, grid);
          int area = bfs(i, j, I, J, grid);
          if (area > maxArea) {
            maxArea = area;
          }
        }
      }
    }
    return maxArea;
  }

  private static int bfs(int i, int j, int I, int J, int[][] grid) {
    List<Integer> queue = new ArrayList<>();
    queue.add(i);
    queue.add(j);
    int area = 0;
    while (queue.size() != 0) {
      int qSize = queue.size();
      while (qSize > 0) {
        int x = queue.get(0), y = queue.get(1);
        queue.remove(0);
        queue.remove(0);
        qSize = queue.size();
        area++;
        for (int k = 0; k < 4; k++) {
          int xx = x + dx[k];
          int yy = y + dy[k];
          if (xx < 0 || xx >= I || yy < 0 || yy >= J || grid[xx][yy] == 0) {
            continue;
          }
          grid[xx][yy] = 0;
          queue.add(xx);
          queue.add(yy);
        }
      }
    }
    return area;
  }

  private static int dfs(int i, int j, int I, int J, int[][] grid) {
    if (i < 0 || j < 0 || i >= I || j >= J || grid[i][j] == 0) {
      return 0;
    }
    grid[i][j] = 0;
    int area = 1;
    for (int k = 0; k < 4; k++) {
      area += dfs(i + dx[k], j + dy[k], I, J, grid);
    }
    return area;
  }
}
