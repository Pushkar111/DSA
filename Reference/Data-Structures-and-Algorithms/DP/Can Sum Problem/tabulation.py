class Solution:
    def isSubsetSum (self, N, arr, targetSum):
        # initialization of table
        table = [False]*(targetSum+1)
        
        table[0] = True # bcz targetSum=0 is always possible
        
        for i in range(targetSum+1):
            if table[i] == True:
                for num in arr:
                    if i+num < targetSum+1:
                        table[i+num] = True
                        
        return table[targetSum]
    
    
    # time complexity : O(m*n), m = targetSum, n = len(arr)
    # space complexity : O(m), m = targetSum
