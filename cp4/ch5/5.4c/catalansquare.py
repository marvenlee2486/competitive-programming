
a = [1]
for i in range(1,5001):
    a.append(a[-1] * (4 * i - 2) // (i + 1))

n = int(input())
ans = 0

for i in range(0, n + 1):
    ans += a[i] * a[n - i]

print(ans)