l = [1, 2]
for i in range(2, 90) :
    l.append(l[-1] + l[-2])
while True :
    try:
        num = int(input())
        print(l[num-1])
    except:
        break
