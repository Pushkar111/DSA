def HowSum(targetSum, numbers):
            
            table = [None]*(targetSum+1)
            
            table[0] = [] # bcz targetSum zero is possible for empty list
            
            for i in range(targetSum+1):
                if table[i] != None:
                    for num in numbers:
                        if i+num <= targetSum:
                            table[i+num] = table[i] + [num]
                            
            return table[targetSum]
