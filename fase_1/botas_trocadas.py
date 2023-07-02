qtt = int(input())
pairs = {}
counter = 0

while qtt:
    tam, ft = input().split()
    tam = int(tam)
    if not tam in pairs.keys():
        pairs[tam]= (0,0)
    
    if ft == "E":
        pairs[tam] = (pairs[tam][0]+1, pairs[tam][1])
    else:
        pairs[tam] = (pairs[tam][0], pairs[tam][1]+1)
    qtt -= 1

for tam in pairs.keys():
    l, r = pairs[tam]
    counter += min(l,r)

    
print(pairs)
print(counter)

