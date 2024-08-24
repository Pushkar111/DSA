class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        
        # for tabulation
        table = [[0 for x in range(n+1)] for y in range(m+1)]
        
        # table[i][0] and table[0][j] values are 0,
        # bcz theres not any way of travelling in empty grid
    
        # from our base case, we can say that
        # there's one way to travel from [1,1] to [1,1]
        table[1][1] = 1


        # Calculate count of paths for other cells in 
        # bottom-up manner using the recursive solution
        for i in range(1, m+1):
            for j in range(1, n+1):
                if i+1 <= m:
                    table[i+1][j] += table[i][j] 
                if j+1 <= n:
                    table[i][j+1] += table[i][j]
                    
        return table[m][n]
