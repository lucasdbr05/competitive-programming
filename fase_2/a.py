def check_2pal(x):
    pals= []
    aux= []

    i=0
    while i <len(x):
        l=r=i
        while l>=0 and r < len(x):
            if r+1<len(x) and l-1>=0 and x[l-1]==x[r+1]:
                l-=1
                r+=1
            else:
                if(r-l+1>=3):
                    aux.append((r-l+1, r, l))
                break
        i+= 1

    i=0
    while i <len(x)-1:
        l, r = i, i+1
        while l>=0 and r < len(x):
            if r+1<len(x) and l-1>=0 and x[l-1]==x[r+1]:
                l-=1
                r+=1
            else:
                if(r-l+1>=3):
                    aux.append((r-l+1, r, l))
                break
        i+= 1
    
    aux.sort(reverse =True)
    # print(aux)
    for (sz, r, l) in aux:
        if len(pals)==0: pals.append((sz, r, l))
        else:
            for (ign, aux_r, aux_l) in pals:
                if aux_r>=r and aux_l<=l:
                    break 
            else:
                pals.append((sz, r, l))
    # print(pals)
    if(len(pals)>=2): return True 
    else: return False 



    

names = input().split()

for name in names:
    if(check_2pal(name)): print(name)