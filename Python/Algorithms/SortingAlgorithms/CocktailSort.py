def Cocktail(a,n):  
    is_swapped = True;  
    begin = 0  
    end = n - 1;  
    while is_swapped:  
        is_swapped = False;  
        for i in range(begin,end):  
            if a[i] > a[i + 1]:  
                temp = a[i];  
                a[i]=a[i+1];  
                a[i+1]=temp;  
                is_swapped = True;  
        if not(is_swapped):  
            break;  
        is_swapped = False;  
        for i in range(end-1,begin-1,-1):  
            if a[i] > a[i + 1]:  
                temp = a[i];  
                a[i]=a[i+1];  
                a[i+1]=temp;  
                is_swapped = True;  
        ++begin;  
arr = [0, 10, 2, 8, 23, 1, 3, 45];  
n = len(arr);  
Cocktail(arr, n);  
print("printing sorted array :\n");  
for i in range(0,n):  
    print(arr[i]),  