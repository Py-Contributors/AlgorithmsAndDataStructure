"""
This program will read data with marathi numbers from [Data_Marathidigits.txt]
and convert into
English data and write onto [Data_Englishdigits.txt]

"""

marathi_digits = ['०', '१', '२', '३', '४', '५', '६', '७', '८', '९']
new_marathiList = []
new_EnglishList = []
# Reading data from the file
with open("marathinum.txt", 'r', encoding='utf-8') as marathi_file:
    for line in marathi_file:
        line = line.replace('\n', ' ')
        mark = line.split(' ')
        for m in mark:
            if m in marathi_digits:
                new_marathiList.append(m)
                new_EnglishList.append(str(marathi_digits.index(m)))
            # This will check for numbers more than one digit
            elif (len(m) > 0 and m[0] in marathi_digits):
                n = ''
                n1 = ''
                for j in m:
                    if j in marathi_digits:
                        n1 += str(marathi_digits.index(j))
                        n += j
                new_marathiList.append(n)
                new_EnglishList.append(n1)
    # This will show you the marathi nnumbers in the file.
    # And their corresponding English numbers.
    print(new_marathiList)
    print(new_EnglishList)
    # Writing data onoto another file.
    with open("nomdigits.txt", 'w') as wData:
        marathi_file.seek(0)
        for line in marathi_file:
            line = line.split(' ')
            for i in line:
                if i not in new_marathiList:
                    wData.write(i + ' ')
                else:
                    wData.write(new_EnglishList[new_marathiList.index(i)] + '')
