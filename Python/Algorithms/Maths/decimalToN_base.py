def conversion(value: int, base: int):
    data = []
    while value >= base:
        data.append(int(value % base))
        value = int(value / base)
    data.append(value)
    data.reverse()
    for i in range(0, len(data)):
        if data[i] > 9:
            temp = data[i] - 10
            data.remove(data[i])
            temp += 65
            data.insert(i, chr(temp))
    return data


val = int(input("Enter decimal value: "))
bas = int(input("Base you want: "))
d = conversion(val, bas)
print("Converted value is: ")
print(' '.join(map(str, d)))
