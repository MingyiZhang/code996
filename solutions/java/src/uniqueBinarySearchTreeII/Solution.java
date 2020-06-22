package uniqueBinarySearchTreeII;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution {
    public List<TreeNode> generateTrees(int n) {
        if (n == 0) {
            return new ArrayList<TreeNode>();
        }
        Map<String, List<TreeNode>> intervalToTreeNodeList = new HashMap<>();
        return generateTreesImpl(1, n, intervalToTreeNodeList); 
    }

    private List<TreeNode> generateTreesImpl(int left, int right, Map<String, List<TreeNode>> intervalToTreeNodeList) {
        if (left > right) {
            return Collections.singletonList(null);
        }

        String intervalKey = String.format("%d_%d", left, right);
        if (intervalToTreeNodeList.containsKey(intervalKey)) {
            return intervalToTreeNodeList.get(intervalKey);
        }

        List<TreeNode> treeNodeList = new ArrayList<>();
        for (int i = left; i <= right; i++) {
            List<TreeNode> leftTreeNodesList = generateTreesImpl(left, i - 1, intervalToTreeNodeList);
            List<TreeNode> rightTreeNodesList = generateTreesImpl(i + 1, right, intervalToTreeNodeList);
            for (TreeNode leftNode : leftTreeNodesList) {
                for (TreeNode rightNode : rightTreeNodesList) {
                    treeNodeList.add(new TreeNode(i, leftNode, rightNode));
                }
            }
        }
        intervalToTreeNodeList.put(intervalKey, treeNodeList);
        return treeNodeList;
    }
    
}