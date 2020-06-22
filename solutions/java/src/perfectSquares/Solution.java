package perfectSquares;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    private List<Integer> getSquares(int n) {
        int a = 1;
        int diff = 3;
        List<Integer> squares = new ArrayList<>();
        while (a <= n) {
            squares.add(a);
            a += diff;
            diff += 2;
        }
        return squares;
    }

    public int numSquares(int n) {
        List<Integer> squares = getSquares(n);
        int[] visited = new int[n + 1];
        List<Integer> queue = new ArrayList<>();
        queue.add(n);
        visited[n] = 1;
        int count = 0;
        while (!queue.isEmpty()) {
            int qSize = queue.size();
            count++;
            while (qSize-- > 0) {
                int x = queue.get(0);
                queue.remove(0);
                for (int i = 0; i < squares.size() && squares.get(i) <= x; i++) {
                    int next = x - squares.get(i);
                    if (visited[next] == 1) {
                        continue;
                    }
                    if (next == 0) {
                        return count;
                    }
                    queue.add(next);
                    visited[next] = 1;
                }
            }
        }
        return count;
    }
}