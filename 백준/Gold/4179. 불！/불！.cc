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
    int fire[r][c] = {};
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
                fire[i][j] = 1;
                Q.push({i, j});
            } else if (tmp == 'J') {

                jihoon[i][j] = 1;
                first_location = {i, j};
                matrix[i][j] = 0; // 빈공간 취급
            } else matrix[i][j] = 0; // 빈공간
            
        }
    }

    if (first_location.first == 0 || first_location.first == r-1 || first_location.second == 0 || first_location.second == c-1) {
        cout << 1;
        return 0;
    }

    while(!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int dir=0; dir<4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (matrix[nx][ny] == -1 || fire[nx][ny] != 0) continue;

            fire[nx][ny] = fire[cur.first][cur.second] + 1;
            Q.push({nx, ny});
            
       }
    }

    // for (int i=0; i<r; i++) {
    //     for (int j=0; j<c; j++) {
    //         cout << fire[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    Q.push(first_location);

    int min = r*c;
    
    while(!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int dir=0; dir<4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (matrix[nx][ny] == -1 || jihoon[nx][ny] != 0) continue;
            if (fire[nx][ny] != 0 && fire[nx][ny] <= jihoon[cur.first][cur.second] + 1) continue;

        
            jihoon[nx][ny] = jihoon[cur.first][cur.second] + 1;
            if (nx == 0 || nx == r-1 || ny == 0 || ny == c-1) {
                if (min > jihoon[nx][ny]) min = jihoon[nx][ny];
            }
            Q.push({nx, ny});
             
       }
    }

    // for (int i=0; i<r; i++) {
    //     for (int j=0; j<c; j++) {
    //         cout << jihoon[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    if (min == r*c) cout << "IMPOSSIBLE";
    else cout << min;


    return 0;
}