N, M, K = map(int, input().split())

data = list(map(int, input().split()))

data.sort()

first = data[-1]
second = data[-2]


count = int(M/(K+1)) * K

answer = first * count + second *(M-count)
print(answer)