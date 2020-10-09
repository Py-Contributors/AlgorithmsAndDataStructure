'''
English_digits = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
Below is marathi numbers list

This program will convert the input number into english number
'''
marathi_digits = ['०', '१', '२', '१', '४', '५', '६', '७', '८', '९']
a = input("Enter marathi digit: ")
if a in marathi_digits:
    print("English Digit: ", marathi_digits.index(a))
# It will go to this condition if marathi number is of more than one digit
else:
    c = 0      # counter is to check input is valid or not
    n1 = ''
    for i in a:
        if i in marathi_digits:
            n1 += str(marathi_digits.index(i))
            c = c + 1
if c != 0:
    print("English Digit: ", n1)
else:
    print("Enter marathi number only")

'''
OUTPUT-:Enter marathi digit:६७८
        English Digit:  678

        Enter marathi digit:०
        English Digit:  0

        Enter marathi digit: seven
        Enter marathi number only

'''
