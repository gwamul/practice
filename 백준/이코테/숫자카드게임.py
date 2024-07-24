N, M = map(int, input().split())
result = 0
for i in range(N):
    data = list(map(int, input().split()))
    max_min = min(data)
    result = max(result, max_min)

print(result)