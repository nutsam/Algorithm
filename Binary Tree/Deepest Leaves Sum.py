# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def dfs(self, root, depth, d):
        if not root:
            return
        
        d[depth] = d.get(depth, 0) + root.val
            
        if root.left:
            self.dfs(root.left, depth+1, d)

        if root.right:
            self.dfs(root.right, depth+1, d)
            
    def deepestLeavesSum(self, root: TreeNode) -> int:
        d = {}
        self.dfs(root, 0, d)

        return d[max(d.keys())]
        