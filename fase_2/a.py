for _ in range(int(input())):
    ans = ""
    r1 = "It's in the box!"
    r2 = "You died!"
    r3 = "Bora ralar:"
    aux = []
    ans = ""
    dict_x = {chr(i):0 for i in range(65, 65+26)}
    dict_arr = {chr(i):0 for i in range(65, 65+26)}
    x = list(input())
    arr = []
    for i in range(3): arr.extend(list(input()))
    x.sort()
    arr.sort()
    for i in x: 
        if (i!=" "): dict_x[i]+= 1
    for i in arr: 
        if (i!=" "): dict_arr[i]+= 1
    for i in range(65, 65+26):
        l = chr(i)
        if dict_x[l]> dict_arr[l]: aux.append(l)
        elif dict_x[l]< dict_arr[l]: 
            ans = r2 
            break
    
    if ans: print(ans)
    elif aux: print(f"{r3} {''.join(aux)}")
    else: print(r1)

