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

        int w, h;
        cin >> w >> h;

        int matrix[h][w];
        int sang[h][w] = {};

        queue<pair<int, int>> Q;
        pair<int, int> location;

        for (int i=0; i<h; i++) {
            string str;
            cin >> str;
            for (int j=0; j<w; j++) {
                if (str[j] == '#') matrix[i][j] = -1;
                else if (str[j] == '.') matrix[i][j] = 0;
                else if (str[j] == '*') {
                    matrix[i][j] = 1;
                    Q.push({i, j});
                } else {
                    matrix[i][j] = 0;
                    sang[i][j] = 1;
                    location = {i, j};
                }
            }
        }

        while(!Q.empty()) {
            pair<int, int> cur = Q.front();
            Q.pop();

            for (int dir=0; dir<4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (matrix[nx][ny] != 0) continue;

                matrix[nx][ny] = matrix[cur.first][cur.second] + 1;
                Q.push({nx, ny});
            }
        }

        Q.push(location);

        int move = -1;

        while(!Q.empty()) {
            pair<int, int> cur = Q.front();
            Q.pop();
            if (cur.first == 0 || cur.first == h-1 || cur.second == 0 || cur.second == w-1) {
                move = sang[cur.first][cur.second];
                break;
            }
            

            for (int dir=0; dir<4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (sang[nx][ny] != 0 || matrix[nx][ny] == -1) continue;

                if (matrix[nx][ny] != 0 && matrix[nx][ny] <= sang[cur.first][cur.second] + 1) continue;

                sang[nx][ny] = sang[cur.first][cur.second] + 1;
                Q.push({nx, ny});
            }
        }


        if (move == -1) cout << "IMPOSSIBLE" << "\n";
        else cout << move << "\n";

        t--;
    }

    return 0;
}