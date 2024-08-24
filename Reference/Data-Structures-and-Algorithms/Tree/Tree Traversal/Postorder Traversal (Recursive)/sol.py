# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        # base case
        if not root:
            return []
        else:
            return self.postorderTraversal(root.left)+self.postorderTraversal(root.right)+[root.val]
