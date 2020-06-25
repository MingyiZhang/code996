package findMinArrowShots;

import java.util.Arrays;

public class Solution {
    public int findMinArrowShots(int[][] points) {
        if (points.length == 0) {
            return 0;
        }
        Arrays.sort(points, (p1, p2) -> p1[1] - p2[1]);

        int end = points[0][1];
        int numberOfShots = 1;
        for (int[] p : points) {
            if (p[0] > end) {
                end = p[1];
                numberOfShots++;
            }
        }
        return numberOfShots;
    }
}