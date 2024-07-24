
count = 0
coins = [500,100,50,10]

n = int(input())

for i in coins:

    temp = int(n/i)
    if temp == 0: continue
    count += temp
    n%=i

print(count)

