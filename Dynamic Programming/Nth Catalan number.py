c = [0]*(105)
c[0] = 1
c[1] = 1
for i in range(2,105):
    for j in range(0,i):
        c[i] += c[j]*c[i-j-1]

t = int(input())

for _ in range(t):
    n = int(input())
    print(c[n])