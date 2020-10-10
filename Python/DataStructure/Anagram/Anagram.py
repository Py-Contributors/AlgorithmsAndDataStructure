# Checking if two words are anagrams or not
# or without having to import anything
def is_anagram(str1, str2):
    return sorted(str1) == sorted(str2)


print(is_anagram('geek', 'eegk'))
print(is_anagram('geek', 'peek'))
