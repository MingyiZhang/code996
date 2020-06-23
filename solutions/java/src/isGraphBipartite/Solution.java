package isGraphBipartite;

public class Solution {
    public boolean isBipartite(int[][] graph) {
        int length = graph.length;
        if (length == 0) {
            return false;
        }
        int[] color = new int[length];
        for (int i = 0; i < graph.length; i++) {
            if (color[i] == 0) {
                if (!isBipartite(graph, i, 1, color)) {
                    return false;
                }
            }
        }
        return true;
    }

    private boolean isBipartite(int[][] graph, int node, int currentColor, int[] color) {
        if (color[node] == 0) {
            color[node] = currentColor;
            for (int nextNode : graph[node]) {
                if (!isBipartite(graph, nextNode, -currentColor, color)) {
                    return false;
                }
            }
        } else if (color[node] != currentColor) {
            return false;
        }
        return true;
    }
}