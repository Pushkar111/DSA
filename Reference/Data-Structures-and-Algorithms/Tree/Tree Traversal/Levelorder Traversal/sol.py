def LevelOrder(root):
    # Base Case
    if root is None:
        return
     
    # Create an empty queue
    # for level order traversal
    queue = []
    
    # to store the traversal order
    ans=[]
 
    # Enqueue Root and initialize height
    queue.append(root)
 
    while queue:
       
        # Print front of queue and
        # remove it from queue
        ans.append(root.data)
        node = queue.pop(0)
 
        #Enqueue left child
        if node.left is not None:
            queue.append(node.left)
 
        # Enqueue right child
        if node.right is not None:
            queue.append(node.right)
        
   return ans



# time complexity : O(n)
# space complexity : O(n)
