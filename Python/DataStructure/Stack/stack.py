#here we are using demonstrating stack in python
#Initally we take an empty list a then we use append function to push element in the list.
#printed [1,2,3]
#after that elements poped out in Last In First Out Order
  
a = [] 
  

a.append(1) 
a.append(2) 
a.append(3) 
  
print('Initial stack') 
print(a) 
  
print('\nElements popped out from stack:') 
print(a.pop()) 
print(a.pop()) 
print(a.pop()) 
print("Stack printed in LIFO Order") 
print('\nStack after all elements are popped out:') 
print(a) 
  
