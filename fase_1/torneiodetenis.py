qtt = 6
i = 0
while qtt:
    x = input()
    if x == "V":
        i+= 1
    qtt -= 1

if i>=5:
    print("1")    
elif i>=3:
    print("2")    
elif i>=1:
    print("3")    
else:
    print("-1")    