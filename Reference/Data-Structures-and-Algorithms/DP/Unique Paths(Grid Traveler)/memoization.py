# for memoization
memo = {}

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        
        key = str(m) + ',' + str(n)
        if key in memo:
            return memo[key]
        
        if m == 1 and n == 1:
            return 1
        if m == 0 or n == 0:
            return 0
        
        memo[key] = self.uniquePaths(m-1, n) + self.uniquePaths(m, n-1)
        
        return memo[key]
    
        # time complexity : O(m*n)
        # space complexity : O(m+n)
