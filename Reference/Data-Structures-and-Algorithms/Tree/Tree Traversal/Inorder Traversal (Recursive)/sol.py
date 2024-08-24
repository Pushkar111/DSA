# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        if root:
            res += self.inorderTraversal(root.left) + [root.val] + self.inorderTraversal(root.right)
        return res
    
    
    # inorder : L->Root->R
    # preorder : Root->L->R
    # postorder : L->R->Root
        
