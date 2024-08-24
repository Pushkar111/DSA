'''
# Node Class:
class Node:
    def init(self,val):
        self.data = val
        self.left = None
        self.right = None
'''

# Return a list containing the inorder traversal of the given tree
def inOrder(root):
    '''# base case is also covered in below code
    if not root:
        return root
    '''
    
    ans=[]
    curr=root
    stack=[]
    
    while True:
        if curr!=None:
            stack.append(curr)
            curr=curr.left
        elif stack:
            curr=stack.pop()
            ans.append(curr.data)
            curr=curr.right
        else:
            break
    return ans
