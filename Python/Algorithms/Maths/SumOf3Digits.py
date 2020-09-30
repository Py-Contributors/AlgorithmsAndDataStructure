"""
Title - Sum of digits of a three digit number
Displays the sum of digits of any three digit number entered by user
Time complexity - O(1)
"""
n = int(input("Enter a number = "))     # taking string input and typecasting it to int

# the first digit of three digit no. is stored in a with floor division by 100
a = n//100;     
# the second or middle digit is stored in b
b = (n//10)%10
# the third or last digit is stored in c by getting remainder after dividing by 10
c = n%10

# finally sum of all three digits of the given number
print("Sum of digit of",n," = ",a+b+c)
