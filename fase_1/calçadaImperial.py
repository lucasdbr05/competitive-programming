import time
i = time.time()
qtt = int(input())
arr =[]
for i in range(qtt):
    arr.append(int(input()))
# print(arr)
ans = 0

for i in range(qtt):
    for j in range(qtt):
        a = arr[i]
        b = arr[j]

        last = -1
        aux = 0

        for k in range(qtt):
            # print(arr[k], a, b)
            if (arr[k]!= a and arr[k]!= b) or arr[k]==last:
                continue
            aux +=1
            last = arr[k]
        ans = max(ans, aux)




print(ans)

# dict_cal = {}

# if qtt-2>0:
#     for i in range(qtt-2):

#         for j in range(2,qtt):
#             # print(dict_cal)
#             if (j-i>=2 and arr[i] != arr[j]): 
#                 if ((arr[i],arr[j]) not in dict_cal.keys()):
#                     dict_cal[(arr[i],arr[j])] = 0
#                 dict_cal[(arr[i],arr[j])] += 1

#         ans = max(dict_cal.values())
# elif qtt-2<=0:
#     ans = 1
        