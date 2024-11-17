def menu():
    n = int(input('请输入方针的阶数\n'))
    a = List(n)
    if strange(a):
        Reverse(a)
    else:
        print('矩阵不可逆')

def List(k):
    a = [] 
    for i in range(k): 
        a.append([]) 
        for j in range(k): 
            x = float(input())
            a[i].append(x) 
    s = [] 
    for i in range(k): 
        s.append([]) 
        for j in range(2 * k): 
            if j < k:
                x = a[i][j]
            elif j - k == i:
                x = 1.0
            else:
                x = 0.0
            s[i].append(x) 
    return s
def strange(a):
    n1 = len(a)
    for m in range(n1-1): 
        k = float(a[m+1][m]/a[m][m]) 
        for m1 in range(1,n1-m): 
            for n in range(m,2*n1): 
                a[m1][n] = float(a[m1][n] - k*a[m1-1][n])
    for m in range(n1):
        if a[m][m] == 0:
            return False
    return True

def Reverse(a):
    l = len(a) 
    n = l - 1
    while(n>=0): 
        for i in range(n+1,l): 
            k = float(a[n][i]/a[i][i])
            for j in range(n+1,2*l):  
                a[n][j] = a[n][j] - k * a[i][j]
        n = n -1
    for i in range(l):
        k = float(1/a[i][i])
        for j in range(i,2*l):
            a[i][j] = k*a[i][j]
    for m in range(l):
        for n in range(2*l):
            print(a[m][n],end=' ')
        print('\n')
menu()
