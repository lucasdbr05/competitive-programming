n = int(input())
s = input()
ans =0

for i in range(n):
    #Impar
    l=i
    r=i
    while l>=0 and r<n and s[l]==s[r]:
            ans = max(ans, r-l+1)
            l-=1
            r+=1
    
    #Par
    l=i
    r=i+1
    while l>=0 and r<n and s[l]==s[r]:
            ans = max(ans, r-l+1)
            l-=1
            r+=1

print(ans)