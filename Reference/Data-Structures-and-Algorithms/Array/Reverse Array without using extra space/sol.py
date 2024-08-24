def reverse(arr):
  start = 0
  end = len(arr)-1
  
  while start < end:
    arr[start], arr[end] = arr[end], arr[start]
    start += 1
    end -= 1
    
    
    
    
    
    
    
# Time complexity : O(n)
# space complexity : O(1)
  
    
