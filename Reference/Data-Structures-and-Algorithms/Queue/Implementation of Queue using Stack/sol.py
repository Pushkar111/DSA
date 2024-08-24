class MyQueue:

    def __init__(self):
        # queue is implemented by using 2 stacks
        self.s1=[] # stack-1
        self.s2=[] # stack-2
        
        

    def push(self, x: int) -> None:
        # Move all elements from s1 to s2
        while len(self.s1)!=0:
            self.s2.append(self.s1[-1])
            self.s1.pop()
            
        # Push item into self.s1 
        self.s1.append(x)
        
        # Push everything back to s1 
        while len(self.s2) != 0: 
            self.s1.append(self.s2[-1]) 
            self.s2.pop()
        
        

    def pop(self) -> int:
        # Return top of self.s1 
        return self.s1.pop()
        

    def peek(self) -> int:
        return self.s1[-1]
        
        

    def empty(self) -> bool:
        if self.s1:
            return False
        return True
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
