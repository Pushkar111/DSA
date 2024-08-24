#Function to find the minimum element in the given BST.
def minValue(root):
    if not root:
        return None
    
    current = root
  
    # loop down to find the lefmost leaf
    while current.left:
        current = current.left
  
    return current.data
