n, m = map(int, input().split())

x = input().split()

ideal = []
for i in x:
    i = i.split(":")
    t = int(i[0])*60*60 + int(i[1])*60 + int(i[2])
    ideal.append(t)


pen = float("inf")
idx=0
for i in range(m):
    aux = 0
    e = input().split()
    for j in range(n):
        a = e[j].split(":")
        t = int(a[0])*60*60 + int(a[1])*60 + int(a[2])

        if ideal[j] >= t:
            aux += (ideal[j]-t)*2
        else:
            aux += (-ideal[j]+t)
    
    if aux < pen:
        pen = aux 
        idx = i +1

print(f"Equipe vencedora: {idx}")
print(f"Penalidade: {pen} ponto(s)")

        
        

