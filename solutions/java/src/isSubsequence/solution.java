package isSubsequence;

public class solution {
    public boolean isSubsequence(String s, String t) {
        int j = 0;
        for (int i = 0; i < t.length(); i++) {
            if (j >= s.length()) {
                return true;
            }
            if (s.charAt(j) == t.charAt(i)) {
                j++;
            }
        }
        return j >= s.length();
    }
}