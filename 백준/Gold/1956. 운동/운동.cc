#include <iostream>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int v, e;
    cin >> v >> e;

    int matrix[v][v];

    for (int i=0; i<v; i++) {
        fill(matrix[i], matrix[i]+v, 0x3f3f3f3f);
    }

    for (int i=0; i<e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        matrix[a-1][b-1] = c;
    }

    for (int k=0; k<v; k++) {
        for (int i=0; i<v; i++) {
            for (int j=0; j<v; j++) {
                if (matrix[i][j] > matrix[i][k] + matrix[k][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }

    int cycle[v];

    int distance = 0x3f3f3f3f;


    for (int i=0; i<v; i++) {
        for (int j=0; j<v; j++) {
            distance = min(distance, matrix[i][j] + matrix[j][i]);
        }
    }

    if (distance == 0x3f3f3f3f) cout << -1 << '\n';
    else cout << distance << '\n';

    return 0;
}