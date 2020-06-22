package friendCircles;

public class Solution {
    public int findCircleNum(int[][] M) {
        int count = 0;
        for (int i = 0; i < M.length; i++) {
            if (M[i][i] == 1) {
                findFriends(i, M);
                count++;
            }
        }
        return count;
    }

    private void findFriends(int index, int[][] M) {
        for (int i = 0; i < M.length; i++) {
            if (index != i && M[index][i] == 1) {
                M[index][i] = 0;
                M[i][index] = 0;
                M[i][i] = 0;
                findFriends(i, M);
            }
        }
    }
}