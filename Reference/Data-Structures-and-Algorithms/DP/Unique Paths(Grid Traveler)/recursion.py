class Solution:
    def uniquePaths(self, m: int, n: int) -> int:   
        
        # Time Complexity : O(2**(m+n))
        # Space Complexity : O(m+n)
        
        # Recursive Solution - This will give TLE for large grid sizes
        if m == 1 and n == 1:
            return 1
        if m == 0 or n == 0:
            return 0
        return self.uniquePaths(m-1, n) + self.uniquePaths(m, n-1)
        
