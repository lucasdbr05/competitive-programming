n = int(input())

while n:
    k = -1
    ans = 0
    s = input()

    for i in range(len(s)):
        if s[i]=='R':
            if i-k>ans:
                ans = i-k
            k=i
        if i== len(s)-1:
            if len(s)-k>ans:
                ans = len(s)-k
    if not ans:
        ans = len(s)+1
    print(ans)

    n-=1