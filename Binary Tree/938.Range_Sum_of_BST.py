class Solution:
    def rangeSumBST(self, root: TreeNode, low: int, high: int) -> int:
        def dfs(root, low, high):
            if not root:
                return 0
            
            if root.val < low:
                return dfs(root.right, low, high)
            elif root.val > high:
                return dfs(root.left, low, high)
            
            return root.val + dfs(root.left, low, high) + dfs(root.right, low, high)
        
        return dfs(root, low, high)