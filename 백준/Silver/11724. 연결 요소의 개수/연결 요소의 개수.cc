#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int matrix[n][n] = {};

    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        matrix[a-1][b-1] = 1;
        matrix[b-1][a-1] = 1;
    }

    for (int i=0; i<n; i++) {
        matrix[i][i] = 1;
    } 

    int connected_component = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (matrix[i][j] == 0) continue;

            queue<int> q;
            q.push(j); 
            q.push(i);
            matrix[i][j] = 0;
            matrix[j][i] = 0;

            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                for (int k=0; k<n; k++) {
                    if (matrix[cur][k] == 0) continue;
                    q.push(k);
                    matrix[cur][k] = 0;
                    matrix[k][cur] = 0;
                }
            }
            connected_component++;
        }
    }

    cout << connected_component << '\n';

    return 0;
}