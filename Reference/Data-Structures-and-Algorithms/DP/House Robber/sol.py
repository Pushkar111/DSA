# Recursive
class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) <= 2:
            return max(nums)
        
        return self.robMax(nums, len(nums) - 1) # start from the last/top
    
    
    def robMax(self, nums, i):
        if i < 0:
            return 0 # when i < 0 we just have to return 0
        return max(nums[i] + self.robMax(nums, i - 2), self.robMax(nums, i - 1))



# Memoization (Top-Down)
class Solution:
    def rob(self, nums: List[int]) -> int:
        
        length = len(nums)
        
        # Memoization (Top-Down)
        memo = [-1] * length
        
        def robFrom(nums, i):
            if i == 0:
                return nums[0]
            
            if i == 1:
                return max(nums[0], nums[1])
            
            if memo[i] != -1:
                return memo[i]

            memo[i] = max(robFrom(nums, i-2) + nums[i], robFrom(nums, i-1))
            return memo[i]
        
        return robFrom(nums, length-1)



# tabulation (i.e Iterative + Memoization) 
class Solution:
    def rob(self, nums: List[int]) -> int:
        
        if len(nums) == 0:
            return 0
        
        table = [-1]*(len(nums)+1)
        
        table[0] = 0
        table[1] = nums[0]
        
        for i in range(1, len(nums)):
            currVal = nums[i]
            table[i+1] = max(table[i-1] + currVal, table[i])
        return table[len(nums)]
      

      
# Iterative + 2 variables
class Solution:
    def rob(self, nums: List[int]) -> int:
        
        dp1, dp2 = 0, 0
        for num in nums:
            dp1, dp2 = dp2, max(dp1 + num, dp2)          
        return dp2
