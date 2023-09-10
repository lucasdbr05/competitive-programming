s = input()
aux = input()
ans = 0
for i in range(len(s)):
    ans +=s[i:i+len(aux)].count(aux)
print(ans)