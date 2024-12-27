#include <iostream>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n, m, r;
    cin >> n >> m >> r;

    int items[n];
    for (int i=0; i<n; i++) {
        cin >> items[i];
    }

    int matrix[n][n];

    for (int i=0; i<n; i++) {
        fill(matrix[i], matrix[i]+n, 0x3f3f3f3f);
        matrix[i][i] = 0;
    }

    for (int i=0; i<r; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        matrix[a-1][b-1] = min(matrix[a-1][b-1], c);
        matrix[b-1][a-1] = min(matrix[b-1][a-1], c);
    }

    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (matrix[i][j] > matrix[i][k] + matrix[k][j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }

    int max = -1;
    for (int i=0; i<n; i++) {
        int count = 0;

        vector<int> v;

        for (int j=0; j<n; j++) {
            if (matrix[i][j] > m) continue;
            v.push_back(j);
        }

        for (int e: v) {
            count += items[e];
        }
        if (max == -1 || max < count) max = count;
    }

    cout << max;
     
    return 0;
}