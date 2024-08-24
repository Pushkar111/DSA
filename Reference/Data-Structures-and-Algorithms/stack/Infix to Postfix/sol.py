class Solution:

    # Function to convert an infix expression to a postfix expression.
    def InfixtoPostfix(self, exp):

        def precedence(operator):
            if operator == '^':
                return 3
            if operator == '*' or operator == '/':
                return 2
            if operator == '+' or operator == '-':
                return 1

            return -1

        exp=str(input('Enter any expression : '))

        out = ''  # for storing postfix expression

        stack = []  # auxiliary stack

        for char in exp:

            # if char is operand
            if char.isalpha():
                out += char

            else: # char is either operator or parenthesis ( i.e char.isalpha() == False )
                if char == '(':
                    stack.append()

                elif char == ')':

                    while stack:

                        temp = stack.pop()

                        if temp == '(':
                            break

                        if not temp.isalpha():
                            out += temp

                else:  # char must be an operator

                    if stack:
                        temp = stack[-1]
                        while stack and precedence(char) <= precedence(temp):
                            out += stack.pop()
                            if stack:
                                temp = stack[-1]

                    stack.append(char)

        while stack:
            out += stack.pop()

        return out
