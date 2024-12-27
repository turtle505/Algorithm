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
    int visit[n][m][2] = {};

    for (int i=0; i<n; i++) {
        string str;
        cin >> str;
        for (int j=0; j<m; j++) {
            matrix[i][j] = str[j] - '0';
            if (matrix[i][j] == 1) matrix[i][j] = -1;
        }
    }

    queue<pair<pair<int, int>, int>> Q;
    Q.push({{0, 0}, 1});
    visit[0][0][1] = 1;

    while (!Q.empty()) {
        pair<int, int> cur = Q.front().first;
        int breaked = Q.front().second;
        Q.pop();

        for (int dir=0; dir<4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (matrix[nx][ny] > 0) continue;
            if (matrix[nx][ny] == -1 && breaked) {
                Q.push({{nx, ny}, 0});
                visit[nx][ny][0] = visit[cur.first][cur.second][1] + 1;
            } else if (matrix[nx][ny] == 0 && !visit[nx][ny][breaked]) {
                Q.push({{nx, ny}, breaked});
                visit[nx][ny][breaked] = visit[cur.first][cur.second][breaked] + 1;
            }  
        }
    }

    if (visit[n-1][m-1][0] == 0 && visit[n-1][m-1][1] == 0) cout << -1 << '\n';
    else if (visit[n-1][m-1][0] == 0) cout << visit[n-1][m-1][1] << '\n';
    else if (visit[n-1][m-1][1] == 0) cout << visit[n-1][m-1][0] << '\n';
    else {
        if (visit[n-1][m-1][0] > visit[n-1][m-1][1]) cout << visit[n-1][m-1][1] << '\n';
        else cout << visit[n-1][m-1][0] << '\n';
    }

    return 0;
}