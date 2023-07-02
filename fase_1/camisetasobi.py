qtt = int(input())
dict_ans = {"t1":0, "t2":0}

prefs = list(map(int, input().split()))
for i in range(qtt):
    if prefs[i] == 1:
        dict_ans["t1"]+=1
    else:
        dict_ans["t2"]+= 1

t1 = int(input())
t2 = int(input())
print(dict_ans)
if dict_ans["t1"]<=t1 and dict_ans["t2"]<=t2:
    print("S")
else:
    print("N")