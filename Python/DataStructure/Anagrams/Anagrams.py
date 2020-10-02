#Checking if two words are anagrams
#   __Author__   :  ArunKumar-25
  
# without having to import anything  
def is_anagram(str1, str2):  
    return sorted(str1) == sorted(str2)  
  
print(is_anagram('top', 'pot'))
print(is_anagram('cry', 'fry'))