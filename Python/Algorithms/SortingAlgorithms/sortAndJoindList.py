
a = "HacktoberFest{2020}"
print(len(a))

print(a)

#Ngelist 1 1
hasilv5 = []
hasilv6 = []
for x in range (0,len(a),2):
    print x
    v5 = a[x] 
    v6 = a[x+1]
    hasilv5.append(v5)
    hasilv6.append(v6) 
    print(v5,v6)

print("=========")
print(hasilv5)
print(hasilv6)
print("=========")

#Join per Array Index
wow = map(''.join, zip(hasilv5,hasilv6))
print(wow)

#Join String1

# def gabunglist(wow):
#     #inisial string
#     string1 = ""
#     return(string1.join(wow))

# print(gabunglist(wow))

#Join List ke 2
# hasilwow = ''.join([str(hw) for hw in wow])
# print(hasilwow)

#Join List Ke 3
hasilwow = ''.join(map(str, wow))
print(hasilwow)
