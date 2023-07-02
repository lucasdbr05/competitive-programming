deck = input()
len_deck = len(deck)
x = 0

naipes = {"C":13,"P":13,"E":13, "U":13}

c = []
p = []
e = []
u = []

aux = ""
while x < len_deck:
    i = deck[x]
    if i not in naipes.keys():
        aux += i

    else:
        aux = int(aux)
        if i=="C":
            if aux not in c and naipes[i] != "erro":
                c.append(int(aux))
                naipes[i] -= 1
            else:
                naipes[i] = "erro"
    
        elif i=="P":
            if aux not in p and naipes[i] != "erro":
                p.append(int(aux))
                naipes[i] -= 1
            else:
                naipes[i] = "erro"
            
        elif i=="E":
            if aux not in e and naipes[i] != "erro":
                e.append(int(aux))
                naipes[i] -= 1
            else:
                naipes[i] = "erro"
           
        elif i=="U":
            if aux not in u and naipes[i] != "erro":
                u.append(int(aux))
                naipes[i] -= 1
            else:
                naipes[i] = "erro"
            
        aux = ""

    x+=1
    # print(naipes)

print(naipes["C"])
print(naipes["E"])
print(naipes["U"])
print(naipes["P"])

