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
 
    int n;
    cin >> n;

    int matrix[n][n] = {};

    for (int i=0; i<n; i++) {
        string str;
        cin >> str;
        for (int j=0; j<n; j++) {
            if (str[j] == 'R') matrix[i][j] = 0;
            else if (str[j] == 'G') matrix[i][j] = 1;
            else matrix[i][j] = 2;
        }
    }

    queue<pair<int, int>> Q;

    int visit[n][n] = {};
    int count_normal = 0;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int color;
            if (visit[i][j] == 0) {
                Q.push({i, j});
                visit[i][j] = 1;
                color = matrix[i][j];
                count_normal++;
            }

            while (!Q.empty()) {
                pair<int, int> cur = Q.front();
                Q.pop();

                for (int dir=0; dir<4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (visit[nx][ny] != 0 || matrix[nx][ny] != color) continue;

                    Q.push({nx, ny});
                    visit[nx][ny] = 1;
                }
            }
        }
    }

    int visit_blind[n][n] = {};

    int count_blind = 0;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int color;
            if (visit_blind[i][j] == 0) {
                Q.push({i, j});
                visit_blind[i][j] = 1;
                color = matrix[i][j];
                count_blind++;
            }

            while (!Q.empty()) {
                pair<int, int> cur = Q.front();
                Q.pop();

                for (int dir=0; dir<4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (visit_blind[nx][ny] != 0) continue;

                    if (color == 0 || color == 1) {
                        if (matrix[nx][ny] == 2) continue;
                    } else {
                        if (matrix[nx][ny] != 2) continue;
                    }

                    Q.push({nx, ny});
                    visit_blind[nx][ny] = 1;
                }
            }
        }
    }

    cout << count_normal << " " << count_blind;

    return 0;
}