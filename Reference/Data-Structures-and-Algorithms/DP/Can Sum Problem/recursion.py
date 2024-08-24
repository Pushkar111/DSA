class Solution:
    def isSubsetSum (self, n, set, targetSum):
        
        # n = len(arr), m = targetSum
        # Time Complexity : O(n**sum)
        # space complexity : O(sum)
        
        if sum == 0:
            return True
        if sum < 0:
            return False
            
        for num in set:
            remainder = sum - num
            if self.isSubsetSum(n, set, remainder) == True:
                return True
        return False
        
