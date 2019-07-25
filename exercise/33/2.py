l = [1, 1]
for i in range(2, 80):
    l.append(l[i-1] + l[i-2])
while True :
    try:
        fr,to = map(int, input().split())
        print(sum(l[ fr-1 : to ]))
    except:
        break
