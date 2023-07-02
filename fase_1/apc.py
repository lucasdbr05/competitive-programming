a, j = map(int, input().split())

max_dist = 0
for i in range(a):
    arr = list(map(int, input().split())) 
    l,r =0,0
    while r<j:
        while arr[r] != 1:
            if r + 1==j:
                break
            r+= 1
            
        print(l,r, sep="    ")
        if (arr[l] ==0 and l==0) or (arr[r]==0 and r==j-1):
            max_dist = max(max_dist, r-l)
        else:
            max_dist = max(max_dist, (r-l)//2)
        l=r
        r+= 1
        


                
print(max_dist)


"""

def mediana_e_mais_proximo_media_e_pos(lista):
    new_list = lista.copy()
    new_list.sort()
    # print(new_list)
    tam = len(lista)
    if tam > 0:
        if tam % 2 == 0:
            mediana = (new_list[int(tam/2)] + new_list[int(tam/2-1)])/2
        else:
            mediana = (new_list[int(tam/2)])
        somador = 0
        for i in new_list:
            somador += i
        media = somador/tam
        delta = new_list[tam-1] - new_list[0]
        prox_media = new_list[0]
        index=0
        for i in lista:
            if abs(media-i) < delta:
                prox_media = i
                index = lista.index(i)
                # print(delta)
                delta = abs(media - i)
    else:
        prox_media = None
        mediana = None
        index = None
    return [mediana, prox_media, index]

lista = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
print(mediana_e_mais_proximo_media_e_pos(lista), end="\n\n")

lista = [123, 486, 159, 321, 357, 753, 125, 652, 111, 987, 987]
print(mediana_e_mais_proximo_media_e_pos(lista), end="\n\n")

lista = [1, 2, 3, 4]
print(mediana_e_mais_proximo_media_e_pos(lista))
"""