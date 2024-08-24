
class Solution:
    def __init__(self):
        self.memo = [[-1 for i in range(n+1)] for j in range(W+1)]
    
    #Function to return max value that can be put in knapsack of capacity W.
    def knapSack(self,W, wt, val, n):
        
        if self.memo[W][n] != -1:
            return self.memo[W][n]

        if W == 0 or n == 0:
            self.memo[W][n] = 0
            return self.memo[W][n]
            
        if wt[n-1] > W:
            self.memo[W][n] = self.knapSack(W, wt, val, n-1)
            return self.memo[W][n]
            
        else:
            self.memo[W][n] = max(val[n-1] + self.knapSack(W-wt[n-1], wt, val, n-1), self.knapSack(W, wt, val, n-1))
            return self.memo[W][n]
        
        
        
        
        OR
        
        
        
        
class Solution:
    
    #Function to return max value that can be put in knapsack of capacity W.
    def knapSack(self,W, wt, val, n):
        
        # helper function to solve KnapSack problem
        def solve(W, wt, val, n):
            if memo[W][n] != -1:
                return memo[W][n]
            if W == 0 or n == 0:
                memo[W][n] = 0
                return memo[W][n]
            if wt[n-1] > W:
                memo[W][n] = solve(W, wt, val, n-1)
                return memo[W][n]
            else:
                memo[W][n] = max(val[n-1] + solve(W-wt[n-1], wt, val, n-1), solve(W, wt, val, n-1))
                return memo[W][n]
       
       
        # code here
        memo = [[-1 for j in range(n+1)] for x in range(W+1)]
        solve(W, wt, val, n)
        return memo[W][n]
        
 
