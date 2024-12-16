def lcs(a, b):
    d = []
    n = len(a)
    m = len(b)

    for i in range(n+1):
        d.append([])
        for _ in range(m+1):
            d[i].append(0)

    for i in range(1, n+1):
        for j in range(1, m+1):
            if a[i-1] == b[j-1]:
                d[i][j] = d[i-1][j-1] + 1
            else: d[i][j] = max(d[i-1][j], d[i][j-1])
    
    return d[n][m]

    

string1 = input()
string2 = input()

print(lcs(string1, string2))