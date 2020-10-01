
def fibonacciList(n):
   
    if n <= 1:
        return n
    else:
        return fibonacciList(n - 1) + fibonacciList(n - 2)


n = int(input("Enter the number of terms: "))
fibList = [fibonacciList(i) for i in range(n)]
print(fibList)
