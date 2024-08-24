'''
1) Create an empty stack.
2) One by one push all characters of string to stack.
3) One by one pop all characters from stack and put them back to string.
'''


# A stack based function to reverse a string
def reverse(string):
     
    # Create a empty stack
    stack = []
 
    # Push all characters of string to stack
    for i in string:
        stack.append(i)
 
    # Making the string empty since all
    #characters are saved in stack
    string=""
 
    # Pop all characters of string and put them back to string
    for i in range(len(stack):
        string+=stack.pop()
         
    return string
