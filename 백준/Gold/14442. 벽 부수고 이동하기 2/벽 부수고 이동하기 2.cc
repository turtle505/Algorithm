#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    string matrix[n];
    int visit[n][m][k+1] = {};

    for (int i=0; i<n; i++) {
        cin >> matrix[i];
    }

    queue<pair<pair<int, int>, int>> Q;
    Q.push({{0, 0}, k});
    visit[0][0][k] = 1;

    while (!Q.empty()) {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int breaked = Q.front().second;
        Q.pop();

        if (x == n-1 && y == m-1) {
            cout << visit[x][y][breaked] << '\n';
            return 0;
        }

        for (int dir=0; dir<4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (matrix[nx][ny] == '1' && breaked == 0) continue;
            if (matrix[nx][ny] == '1' && visit[nx][ny][breaked-1] == 0) {
                visit[nx][ny][breaked-1] = visit[x][y][breaked] + 1;
                Q.push({{nx, ny}, breaked-1});
            }
            if (matrix[nx][ny] == '0' && visit[nx][ny][breaked] == 0) {
                visit[nx][ny][breaked] = visit[x][y][breaked] + 1;
                Q.push({{nx, ny}, breaked});

            }
        }
    }

    cout << -1 << '\n';

    return 0;
}