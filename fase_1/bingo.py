k, n, u = map(int, input().split())
dict_ans ={i+1:n for i in range(k)}
cartela = [[] for _ in range(k)]

for i in range(k):
    cartela[i] = list(map(int, input().split()))

sorteados = list(map(int, input().split()))    

x = ""
for i in range(u):
    for elm in dict_ans.keys():
        if dict_ans[elm]==0:
            x += str(elm) + " "
    if x:
        print(x.strip())
        break

    for j in range(k):
        if sorteados[i] in cartela[j]:
            dict_ans[j+1] -= 1
    print(dict_ans, cartela, sorteados[i], sep="\n")