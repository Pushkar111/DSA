# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        
        # recursive solution 
        
        if not inorder or not preorder:
            return None
        
        # find the index of root in list inorder
        ind = inorder.index(preorder.pop(0))
            
        # insert the root element(present at index ind in inorder list) in Binary Tree 
        root = TreeNode(inorder[ind])
            
        # for the elements before index 'ind' in inorder, make them left sub-tree
        root.left = self.buildTree(preorder, inorder[0:ind])
            
        # for the elements after index 'ind' in inorder, make them left sub-tree
        root.right = self.buildTree(preorder, inorder[ind+1:])
            
        return root
        
