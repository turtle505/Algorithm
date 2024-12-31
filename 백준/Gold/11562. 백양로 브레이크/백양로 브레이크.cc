#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;

    cin >> n >> m;

    int matrix[n][n];

    for (int i=0; i<n; i++) {
        fill(matrix[i], matrix[i]+n, 0x3f3f3f3f);
        matrix[i][i] = 0;
    }

    for (int i=0; i<m; i++) {
        int u, v, b;
        cin >> u >> v >> b;

        matrix[u-1][v-1] = 0;
        if (b == 1) matrix[v-1][u-1] = 0;
        else matrix[v-1][u-1] = 1;
    }

    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (matrix[i][j] > matrix[i][k] + matrix[k][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }

    int k;
    cin >> k;

    while (k > 0) {
        int s, e;
        cin >> s >> e;

        cout << matrix[s-1][e-1] << '\n';

        k--;
    }
    
    return 0;
}
