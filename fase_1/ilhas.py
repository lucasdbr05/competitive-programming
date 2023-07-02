n, m = map(int, input().split())
# distancia = [-1]*m
adj_grafo = [[] for _ in range(n)]

for i in range(m):
    u, v, p = map(int, input().split())
    adj_grafo[u-1].append((v,p))
    adj_grafo[v-1].append((u,p))

fonte = int(input())

# print(adj_grafo)

custos = {i:1001 for i in range(1,n+1)}
custos[fonte] = 0
pais = {}
for no in adj_grafo[fonte -1]:
    custos[no[0]] = no[1]
    pais[no[0]] = fonte



processados = []
def ache_no_custo_mais_baixo(custos):
    custo_mais_baixo = float("inf")          #custo infinito
    nodo_custo_mais_baixo = None
    for nodo in custos:             #Vá por cada vértice.
        custo = custos[nodo]
        if custo<custo_mais_baixo and nodo not in processados: #Se for o vértice de menor custo até o momento e ainda não tiver sido processado
            custo_mais_baixo = custo      #atribua como o novo vértice de menor custo.
            nodo_custo_mais_baixo = nodo
    return nodo_custo_mais_baixo

nodo = ache_no_custo_mais_baixo(custos) #Encontra o custo mais baixo que ainda não foi processado.

while nodo is not None:     #Caso todos os vértices tenham sido processados, esse laço while será finalizado.
    custo = custos[nodo]
    vizinhos = adj_grafo[nodo-1]
    for vizinho in vizinhos: #Percorre todos os vizinhos desse vértice.
        novo_custo = custo + vizinho[1]
        if custos[vizinho[0]] > novo_custo:  #Caso seja mais barato chegar a um vizinho a partir desse vértice...
            custos[vizinho[0]] = novo_custo   #atualiza o custo dele.
            pais[vizinho[0]] = nodo    #Esse vértice se torna o novo pai para o vizinho.
    processados.append(nodo)  #Marca o vértice como processado.
    nodo = ache_no_custo_mais_baixo(custos)  #Encontra o próximo vértice a ser processado e o algoritmo é repetido.





# print(adj_grafo, custos, pais, sep="\n")
dist = [i for i in custos.values() if i >0]
max_d = max(dist)
min_d = min(dist)
print(max_d - min_d)





