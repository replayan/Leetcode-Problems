# credit : neetcodeIO

class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        def solve(root, current):
            if not root:
                return
            current = chr(ord("a") + root.val) + current
            if root.left and root.right:
                return min(solve(root.left, current), solve(root.right, current))
            if root.left:
                return solve(root.left, current)
            if root.right:
                return solve(root.right, current)
            return current

        return solve(root, "")
