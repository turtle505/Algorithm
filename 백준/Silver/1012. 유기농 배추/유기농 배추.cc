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
 
    int t;
    cin >> t;

    

    while (t > 0) {
        int m, n, k;
        cin >> m >> n >> k;

        int matrix[m][n] = {};

        for(int i=0; i<k; i++) {
            int x, y;
            cin >> x >> y;
            matrix[x][y] = 1;
        }

        int visit[m][n] = {};

        int count = 0;
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (matrix[i][j] != 1 || visit[i][j] == 1) continue;

                queue<pair<int, int>> Q;
                count++;

                visit[i][j] = 1;
                Q.push({i, j});

                while (!Q.empty()) {

                    pair<int, int> cur = Q.front();
                    Q.pop();

                    for (int dir=0; dir<4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        if (matrix[nx][ny] != 1 || visit[nx][ny] == 1) continue;
                        
                        visit[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }

        cout << count << '\n';

        t--;
    }

    return 0;
}