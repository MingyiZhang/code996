package courseScheduleII;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<List<Integer>> graph = new ArrayList<>(numCourses);
        for (int i = 0; i < numCourses; i++) {
            graph.add(new ArrayList<Integer>());
        }
        int[] valencies = new int[numCourses];
        for (int[] pre : prerequisites) {
            graph.get(pre[0]).add(pre[1]);
            valencies[pre[1]]++;
        }
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (valencies[i] == 0) {
                queue.add(i);
            }
        }

        int[] ret = new int[numCourses];
        while (!queue.isEmpty()) {
            int currentCourse = queue.poll();
            numCourses--;
            ret[numCourses] = currentCourse;
            for (int nextCourse : graph.get(currentCourse)) {
                if (--valencies[nextCourse] == 0) {
                    queue.add(nextCourse);
                }
            }
        }

        return numCourses == 0 ? ret : new int[]{};
    }
}