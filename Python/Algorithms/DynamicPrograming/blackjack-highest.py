#Blackjack Highest
'''Have the function BlackjackHighest(strArr) take the strArr parameter being passed which will be an array of numbers and letters representing
blackjack cards. Numbers in the array will be written out. So for example strArr may be ["two","three","ace","king"].
The full list of possibilities for strArr is: two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace.
Your program should output below, above, or blackjack signifying if you have blackjack (numbers add up to 21)
or not and the highest card in your hand in relation to whether or not you have blackjack. If the array contains an ace but your hand will go above 21,
you must count the ace as a 1. You must always try and stay below the 21 mark. So using the array mentioned above, the output should be below king.
The ace is counted as a 1 in this example because if it wasn't you would be above the 21 mark.

Another example would be if strArr was ["four","ten","king"], the output here should be above king.
If you have a tie between a ten and a face card in your hand, return the face card as the "highest card".
If you have multiple face cards, the order of importance is jack, queen, king.

Examples
Input: ["four","ace","ten"]
Output: below ten
Input: ["ace","queen"]
Output: blackjack ace'''


def BlackjackHighest(strArr):
  lowVal, topVal, rating = 0,0,0
  total = 0
  isAce =  False
  lst = []
  repr = ""
  for i in strArr:
    if i == "two":
      lowVal, topVal, rating = 2,2,2
    elif i =="three":
      lowVal, topVal, rating = 3,3,3
    elif i =="four":
      lowVal, topVal, rating = 4,4,4
    elif i =="five":
      lowVal, topVal, rating = 5,5,5
    elif i =="six":
      lowVal, topVal, rating = 6,6,6
    elif i =="seven":
      lowVal, topVal, rating = 7,7,7
    elif i =="eight":
      lowVal, topVal, rating = 8,8,8
    elif i =="nine":
      lowVal, topVal, rating = 9,9,9
    elif i =="ten":
      lowVal, topVal, rating = 10,10,10
    elif i =="jack":
      lowVal, topVal, rating = 10,10,11
    elif i =="queen":
      lowVal, topVal, rating = 10,10,12
    elif i =="king":
      lowVal, topVal, rating = 10,10,13
    elif i =="ace":
      isAce = True
      lowVal, topVal, rating = 1,11,14
  
    total = total + topVal
    lst.append(rating)

  if total > 21 and isAce:
    total = (total - 11) + 1
    idx = lst.index(14)
    lst[idx] = 1
    
  var = lst.index(max(lst))
  var = strArr[var]
  if total > 21:
    return ("above "+var)
  elif total == 21:
    return ("blackjack "+var)
  elif total < 21:
    return ("below "+var)


# keep this function call here 
print(BlackjackHighest(input()))


'''== RUNNING TEST CASES ==

== INPUT ==
["ace","queen"]

== OUTPUT ==
blackjack ace

<< CORRECT >>

== INPUT ==
["four","ace","ten"]

== OUTPUT ==
below ten

<< CORRECT >>'''
