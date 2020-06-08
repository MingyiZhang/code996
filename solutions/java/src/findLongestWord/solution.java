package findlongestword;

class Solution {
    public String findLongestWord(String s, List<String> d) {
        String ret = "";
        for (String word : d) {
            int l1 = ret.length(), l2 = word.length();
            if (l1 > l2 || (l1 == l2 && ret.compareTo(word) < 0)) {
                continue;
            }
            if (isSubStr(s, word)) {
                ret = word;
            }
        }
        return ret;
    }

    private boolean isSubStr(String s, String word) {
        int i = 0, j = 0;
        while (i < s.length() && j < word.length()) {
            if (s.charAt(i) == word.charAt(j)) {
                j++;
            } 
            i++;
        }
        return j == word.length();
    }
}

