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
    int next[n][n] = {};

    for (int i=0; i<n; i++) {
        fill(matrix[i], matrix[i]+n, 0x3f3f3f3f);
        matrix[i][i] = 0;
    }

    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        matrix[a-1][b-1] = min(matrix[a-1][b-1], c);
        next[a-1][b-1] = b-1;
    }

    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (matrix[i][j] > matrix[i][k] + matrix[k][j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (matrix[i][j] == 0x3f3f3f3f) cout << 0 << ' ';
            else cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (matrix[i][j] == 0 || matrix[i][j] == 0x3f3f3f3f) {
                cout << 0 << '\n';
                continue;
            }
            int a = i;
            vector<int> v;
            v.push_back(a+1);
            while (a != j) {
                v.push_back(next[a][j]+1);
                a = next[a][j];
            }

            cout << v.size() << ' ';

            for (int k=0; k<v.size(); k++) {
                cout << v[k] << ' ';
            }

            cout << '\n';
        }
    }


    return 0;
}