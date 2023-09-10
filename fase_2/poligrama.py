from math import gcd
n = int(input())
s = input()


alpha = {chr(i):0 for i in range(97, 97+26)}
for i in range(n):
    alpha[s[i]]+=1

mdc= aux = max(alpha.values())

for num in alpha.values():
    if num and num!= aux:
        mdc = gcd(mdc, num)
# print(alpha, mdc)
ans = ""
for elem, qtt in alpha.items():
    ans += elem *(qtt//mdc)

if len(ans)==n:
    print("*")
else:
    val = True
    d = {}
    for i in ans:
        if not i in d:
            d[i]= ans.count(i)
    for i in range(0, n, len(ans)):
        aux = d.copy()
        for j in  range(len(ans)):
            aux[s[i+j]]-=1
        if any(aux.values()):
            val = False
            break
    if val:
        print(s[:len(ans)])
    else:
        print("*")


    