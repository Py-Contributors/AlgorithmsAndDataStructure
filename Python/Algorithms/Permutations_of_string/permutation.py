def permutation(string, val, length):
    if val == length - 1:
        print(" ".join(string))
    else:
        for i in range(val, length):
            string[val], string[i] = string[i], string[val]
            permutation(string, val + 1, length)
            string[val], string[i] = string[i], string[val]   # reversing the change(Backtracking)


print("Enter your string :")
get_string = input()
print("all permutations for the given string :")
permutation(list(get_string), 0, len(get_string))
