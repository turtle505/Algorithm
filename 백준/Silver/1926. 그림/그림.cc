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

    int matrix[n][m];

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> matrix[i][j];
        }
    }

    bool visit[n][m] = {};

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int max = 0;
    int count = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (matrix[i][j] == 1 && visit[i][j] != 1) {
                queue<pair<int, int>> Q;

                visit[i][j] = 1;
                Q.push({i,j});
                int size = 0;

                while (!Q.empty()) {
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    size++;
                    for (int dir=0; dir<4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (visit[nx][ny] == 1 || matrix[nx][ny] != 1) continue;

                        visit[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }

                count++;
                if (max < size) max = size;
            }
        }
    }

    
    cout << count << "\n" << max;


    return 0;
}