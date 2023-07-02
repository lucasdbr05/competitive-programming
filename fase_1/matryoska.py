qtt = int(input())

bonecas = list(map(int, input().split()))

counter = 0
ans = ""

def quickSort(bonecas):
    if len(bonecas)<=1:
        return bonecas
    else:
        pivot = bonecas[0]
        maiores = [i for i in bonecas[1:] if i > pivot]
        menores = [i for i in bonecas[1:] if i <= pivot]
        
        
        return quickSort(menores)+ [pivot] + quickSort(maiores)
    
newBonecas = quickSort(bonecas)


for i in range(qtt):
    if bonecas[i]!= newBonecas[i]:
        counter+= 1
        ans += str(newBonecas[i])+" "
ans = ans.strip()      

print(counter, ans, sep="\n")





