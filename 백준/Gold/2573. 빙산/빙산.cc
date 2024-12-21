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
    vector<pair<int, int>> zeros;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 0) zeros.push_back({i, j});
        }
    }

    queue<pair<int, int>> Q;
    int years = 0;
    int zeros_size = zeros.size();


    while(1) {
        if (zeros_size == n*m) {
            years = 0;
            break;
        }
        int count = 0;

        int visit[n][m] = {};

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (matrix[i][j] == 0 || visit[i][j] != 0) continue;
                Q.push({i, j});
                visit[i][j] = 1;
                

                while (!Q.empty()) {
                    pair<int, int> cur = Q.front();
                    Q.pop();

                    for (int dir=0; dir<4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (visit[nx][ny] != 0 || matrix[nx][ny] == 0) continue;

                        visit[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
                count++;
            }
        }

        if (count > 1) break;

        years++;


        for (int i=0; i<zeros_size; i++) {
            for (int dir=0; dir<4; dir++) {
                int nx = zeros[i].first + dx[dir];
                int ny = zeros[i].second + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (matrix[nx][ny] == 0) continue;

                matrix[nx][ny]--;
                if (matrix[nx][ny] == 0) zeros.push_back({nx, ny});
            }
        }
        zeros_size = zeros.size();
    }

    cout << years;


    return 0;
}