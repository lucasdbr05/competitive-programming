for _ in range(int(input())):
    n, width = map(int, input().split())
    arr = list(map(int, input().split()))
    arr.sort(reverse=True)
    dict_ = {}
    for i in arr:
        if not i in dict_.keys():
            dict_[i] = 0
        dict_[i] += 1

    ans = 0
    while n:
        aux = width
        for i in dict_:
            while i <= aux and dict_[i]:
                n-=1
                aux -= i
                dict_[i]-=1
        ans += 1
    print(ans)


