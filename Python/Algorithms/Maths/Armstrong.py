
def is_armstrong(number):
    # Calculate the number of digits
    num_digits = len(str(number))
    
    # Calculate the sum of each digit raised to the power of the number of digits
    sum_of_digits = sum(int(digit) ** num_digits for digit in str(number))
    
    # Check if the number is equal to the sum of its digits raised to the power of the number of digits
    return number == sum_of_digits

def generate_armstrong_numbers(start, end):
    armstrong_numbers = []
    for num in range(start, end + 1):
        if is_armstrong(num):
            armstrong_numbers.append(num)
    return armstrong_numbers

start_range = int(input("Enter the start of range: "))
end_range = int(input("Enter the end of range: "))

print("Armstrong numbers between", start_range, "and", end_range, "are:")
print(generate_armstrong_numbers(start_range, end_range))
