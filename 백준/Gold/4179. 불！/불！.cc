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
 
    int r, c;

    cin >> r >> c;

    int matrix[r][c];
    int jihoon[r][c] = {};

    pair<int, int> first_location;
    queue<pair<int, int>> Q;

    for (int i=0; i<r; i++) {

        string str;
        cin >> str;

        for (int j=0; j<c; j++) {

            char tmp = str.at(j);

            if (tmp == '#') matrix[i][j] = -1; // 벽
            else if (tmp == 'F') {
                matrix[i][j] = 1; // 불
                Q.push({i, j});
            } else if (tmp == 'J') {
                jihoon[i][j] = 1;
                first_location = {i, j};
                matrix[i][j] = 0; // 빈공간 취급
            } else matrix[i][j] = 0; // 빈공간
            
        }
    }

    while(!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int dir=0; dir<4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (matrix[nx][ny] == -1 || matrix[nx][ny] != 0) continue;

            matrix[nx][ny] = matrix[cur.first][cur.second] + 1;
            Q.push({nx, ny});
       }
    }

    Q.push(first_location);

    int min = r * c + 1;
    
    while(!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();

        int cur_x = cur.first;
        int cur_y = cur.second;

        if (cur_x == 0 || cur_x == r-1 || cur_y == 0 || cur_y == c-1) {
            if (min > jihoon[cur_x][cur_y]) min = jihoon[cur_x][cur_y];
        }

        for (int dir=0; dir<4; dir++) {
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (matrix[nx][ny] == -1 || jihoon[nx][ny] != 0) continue;
            if (matrix[nx][ny] != 0 && matrix[nx][ny] <= jihoon[cur_x][cur_y] + 1) continue;

            jihoon[nx][ny] = jihoon[cur_x][cur_y] + 1;
            Q.push({nx, ny});
       }
    }

    if (min == r * c + 1) cout << "IMPOSSIBLE";
    else cout << min;

    return 0;
}