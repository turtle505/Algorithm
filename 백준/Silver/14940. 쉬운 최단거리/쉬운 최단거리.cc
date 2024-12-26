#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int matrix[n][m];
    int visit[n][m] = {};

    queue<pair<int, int>> Q;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 2) {
                Q.push({i, j});
                visit[i][j] = 1;
                matrix[i][j] = 0;

            } 
        }
    }

    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int dir=0; dir<4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir]; 

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visit[nx][ny] == 1 || matrix[nx][ny] == 0) continue;

            Q.push({nx, ny});
            visit[nx][ny] = 1;
            matrix[nx][ny] = matrix[cur.first][cur.second] + 1;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (matrix[i][j] == 0 || visit[i][j] == 1) continue;
            matrix[i][j] = -1;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}