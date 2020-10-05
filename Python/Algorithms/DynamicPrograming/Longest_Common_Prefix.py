'''
Longest Common Prefix
Title - Find the longest common prefix

Sample input and output:
Example 1:
List of Strings:  ['apps', 'appology', 'application']
Longest Common Prefix : app

Example 2:
List of Strings:  ['doggo', 'doggs', 'snoopdogg']
No Common prefix

time complexity: O(n^2)
space complexitY: O(n)
'''


def LongestCommonPrefix(strings):
    '''
    argument takes a list of strings.
    First string is compared with all the other strings.
    If first string is not present in anyone of the strings,
    we remove the last index of first string and repeat until
    all strings contain the first string or length of string=0
    '''
    check = strings[0]
    value = False
    while(not value and len(check) > 0):
        for i in range(1, len(strings)):
            if strings[i].find(check) != 0:
                check = check[:-1]
                value = False
                break
            else:
                value = True
    return check


if __name__ == "__main__":
    strings = list(map(str, input().strip().split()))
    print("List of Strings: ", strings)
    value = LongestCommonPrefix(strings)
    if value:
        print("Longest Common Prefix :", value)
    else:
        print("No Common prefix")
