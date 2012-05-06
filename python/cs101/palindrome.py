#Define a procedure is_palindrome, that takes as input a string, and returns a
#Boolean indicating if the input string is a palindrome.

#Base Case: '' => True
#Recursive Case: if first and last characters don't match => False
#if they do match, is middle palindrome?

def is_palindrome(s):
    if s == '' or len(s) == 1:
        return True
    elif s[0] != s[-1]:
        return False
    else:
        return is_palindrome(s[1:-1])           

    
print is_palindrome('')
#>>> True
print is_palindrome('abab')
#>>> False
print is_palindrome('abba')
#>>> True