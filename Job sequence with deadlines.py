s=list(map(str,input("Enter jobs:").split()))
d=list(map(int,input("Enter deadlines:").split()))
p=list(map(int,input("Enter profits:").split()))
p1=[]
l=[]
a=max(d)
for i in range(a):
    l.append(-1)
for i in p:
    p1.append(i)
p.sort(reverse=True)
for i in p:
    a = p1.index(i)
    n = d[a]
    n1 = s[a]
    for j in range(n - 1, -1, -1):
        if l[j] == -1:
            l[j] = n1
            break
        else:
            j=j-1
print("Job sequence is:")
print(l)
print("Total profit:",sum(p[:max(d)]))