from typing import List, Dict, Tuple


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def divide_conquer(left: int, right: int) -> List[TreeNode]:
    if left > right:
        return [None]
    trees = list()
    for i in range(left, right + 1):
        left_trees = divide_conquer(left, i - 1)
        right_trees = divide_conquer(i + 1, right)
        for tree1 in left_trees:
            for tree2 in right_trees:
                head = TreeNode(i)
                head.left = tree1
                head.right = tree2
                trees.append(head)
    return trees


def generate_tree(n: int) -> List[TreeNode]:
    if n == 0:
        return list()
    return divide_conquer(1, n)
