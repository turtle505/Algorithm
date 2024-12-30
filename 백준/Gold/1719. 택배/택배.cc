#include <iostream>
#include <algorithm>
#include <string>
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

    int name[n][n] = {};


    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        matrix[a-1][b-1] = c;
        matrix[b-1][a-1] = c;
        name[a-1][b-1] = b-1;
        name[b-1][a-1] = a-1;
    }


    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (matrix[i][j] > matrix[i][k] + matrix[k][j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                    name[i][j] = name[i][k];
                }

            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i == j) cout << '-' << ' ';
            else cout << name[i][j] + 1 << ' ';
        }
        cout << '\n';
    }



    return 0;
}