qtt = int(input())

amgs = {}
aux_ams = {}
ans = []

counter = 0
was_t = False
for i in range(qtt):
    c, x = input().split()
    x = int(x)
    if c == "T":
        was_t = True
        counter+= x
        continue
    if not was_t:
        counter += 1
    was_t= False
    if c =="R":
        if x not in amgs.keys():
            amgs[x] = -counter
        else:
            aux_ams[x]= -counter

        
    if c== "E":
        if x not in aux_ams.keys():
            amgs[x] += counter 
        else:
            aux_ams[x] += counter
            amgs[x]+= aux_ams[x]
            aux_ams[x] = 0

    # print(amgs)
    # print(aux_ams)


amgs = {k:v for k,v in sorted(amgs.items(), key= lambda item: item[0])}
for i in aux_ams.keys():
    if aux_ams[i]<0:
        amgs[i]= aux_ams[i]        
for i in amgs.keys():
    if amgs[i]<0:
        amgs[i]= -1


    
for k,v in amgs.items():
    print(k, v)

