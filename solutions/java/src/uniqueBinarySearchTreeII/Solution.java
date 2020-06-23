package uniqueBinarySearchTreeII;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Solution {
    // recursive
    public List<TreeNode> generateTrees(int n) {
        if (n == 0) {
            return new ArrayList<TreeNode>();
        }
        return generateTreesImpl(1, n);
    }
    
    private List<TreeNode> generateTreesImpl(int left, int right) {
        if (left > right) {
            return Collections.singletonList(null);
        }
        
        List<TreeNode> TreeNodeList = new ArrayList<>();
        for (int i = left; i <= right; i++) {
            List<TreeNode> leftTreeNodeList = generateTreesImpl(left, i - 1);
            List<TreeNode> rightTreeNodeList = generateTreesImpl(i + 1, right);
            for (TreeNode leftNode : leftTreeNodeList) {
                for (TreeNode rightNode : rightTreeNodeList) {
                    TreeNode head = new TreeNode(i, leftNode, rightNode);
                    TreeNodeList.add(head);
                }
            }
        }
        return TreeNodeList;
    }

    // Dynamic programming

    // public List<TreeNode> generateTrees(int n) {
    //     if (n == 0) {
    //         return new ArrayList<TreeNode>();
    //     }
    //     Map<String, List<TreeNode>> intervalToTreeNodeList = new HashMap<>();
    //     return generateTreesImpl(1, n, intervalToTreeNodeList); 
    // }

    // private List<TreeNode> generateTreesImpl(int left, int right, Map<String, List<TreeNode>> intervalToTreeNodeList) {
    //     if (left > right) {
    //         return Collections.singletonList(null);
    //     }

    //     String intervalKey = String.format("%d_%d", left, right);
    //     if (intervalToTreeNodeList.containsKey(intervalKey)) {
    //         return intervalToTreeNodeList.get(intervalKey);
    //     }

    //     List<TreeNode> treeNodeList = new ArrayList<>();
    //     for (int i = left; i <= right; i++) {
    //         List<TreeNode> leftTreeNodesList = generateTreesImpl(left, i - 1, intervalToTreeNodeList);
    //         List<TreeNode> rightTreeNodesList = generateTreesImpl(i + 1, right, intervalToTreeNodeList);
    //         for (TreeNode leftNode : leftTreeNodesList) {
    //             for (TreeNode rightNode : rightTreeNodesList) {
    //                 treeNodeList.add(new TreeNode(i, leftNode, rightNode));
    //             }
    //         }
    //     }
    //     intervalToTreeNodeList.put(intervalKey, treeNodeList);
    //     return treeNodeList;
    // }
    
}