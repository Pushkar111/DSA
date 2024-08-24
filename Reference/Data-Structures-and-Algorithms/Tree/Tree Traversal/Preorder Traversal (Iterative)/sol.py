'''
# Node Class:
class Node:
    def init(self,val):
        self.data = val
        self.left = None
        self.right = None
'''

# Return a list containing the inorder traversal of the given tree
def preOrder(root):
    # base case
    if not root:
        return root
    
    ans=[]
    
    stack=[]
    stack.append(root)

    while stack:
        curr=stack.pop()
        ans.append(curr.data)
        
        if curr.right!=None:  # curr.right must be pushed first in stack
            stack.append(curr.right)
        
        if curr.left!=None:
            stack.append(curr.left)
        
            
    return ans
