class MyStack:

    def __init__(self):
        # Stack can be implemented by using two queues
        self.q1=[]
        self.q2=[]
        
        # To maintain current number of elements
        # self.curr_size = 0
        
        

    def push(self, x: int) -> None:
        # self.curr_size += 1
  
        # Push x first in empty q2 
        self.q2.append(x) 
  
        # Push all the remaining elements in q1 to q2. 
        while len(self.q1)!=0:
            self.q2.append(self.q1[0]) 
            self.q1.pop(0)
  
        # swap the names of two queues 
        self.q1, self.q2 = self.q2, self.q1
         
        

    def pop(self) -> int:
        return self.q1.pop(0)
        

    def top(self) -> int:
        return self.q1[0]
        

    def empty(self) -> bool:
        if self.q1:
            return False
        return True
        """
        Returns whether the stack is empty.
        True == Empty
        False != Empty
        """
        


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
