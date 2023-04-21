
a = [1]
for i in range(1,5001):
    a.append(a[-1] * (4 * i - 2) // (i + 1))

q = int(input())

for i in range(q):
    x = int(input())
    print(a[x])