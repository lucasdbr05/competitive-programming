x = input()
ls = {"":0}

for i in x:
    if not i in ls.keys():
        ls[i]=0
    ls[i]+= 1

odds = 0
odd = ""
x = ""
for (i, qtt) in ls.items():
    if qtt%2:
        odd = i
        odds += 1
    else:
        x += i*(qtt//2)


if odds>1:
    print("NO SOLUTION")
else:
    print(x+odd*ls[odd]+x[::-1])
    
        
