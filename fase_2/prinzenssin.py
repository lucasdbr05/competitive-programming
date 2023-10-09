aux = []
for i in range(26):
    a = chr(ord('a')+i)
    aux.append(a)
    # print(a)
for i in range(26):
    a = chr(ord('a')+i) 
    for j in range(26):
        b = a 
        b+= chr(ord('a')+j)
        aux.append(b)
        # print(b)
for i in range(26):
    a = chr(ord('a')+i) 
    for j in range(26):
        b = a 
        b+= chr(ord('a')+j)
        for k in range(26):
            c = b 
            c += chr(ord('a')+k)
            aux.append(a)
            print(c)


for i in range(int(input())):
    n = int(input())
    x = input()

    ans  =''
    for s in aux:
        if not x.count(s):
            ans = s 
            break 
    print(ans)
