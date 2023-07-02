n1 = input()

dict_n1={}
for i in n1:
    if not i in dict_n1.keys():
        dict_n1[i]=0
    dict_n1[i] += 1

n2 = input()
ast = 0
for i in n2:
    if i in dict_n1.keys():
        dict_n1[i]-=1
    if i == "*":
        ast += 1
       
ans = sum(dict_n1.values())- ast

if not ans:
    print("S")
else:
    print("N")