#include <iostream>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n, m;
    cin >> n >> m;

    int matrix[n][m];

    for (int i=0; i<n; i++) {
        string str;
        cin >> str;

        for(int j=0; j<m; j++) {
            matrix[i][j] = str.at(j) - '0';
        }
    }

    int visit[n][m] = {};
    
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    visit[0][0] = 1;

    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int dir=0; dir<4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (matrix[nx][ny] != 1) continue;
            
            if (visit[nx][ny] != 0 && visit[nx][ny] > visit[cur.first][cur.second] + 1)  {
                visit[nx][ny] = visit[cur.first][cur.second] + 1;
            } else if (visit[nx][ny] == 0) {
                visit[nx][ny] = visit[cur.first][cur.second] + 1;
                Q.push({nx, ny});
            }
        }
    }

    cout << visit[n-1][m-1];
    
    return 0;
}