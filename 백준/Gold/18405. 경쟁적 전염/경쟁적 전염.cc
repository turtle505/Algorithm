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
 
    int n, k;
    cin >> n >> k;

    int matrix[n][n];

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> matrix[i][j];
        }

    }

    int s, x, y;
    cin >> s >> x >> y;

    queue<pair<int, int>> Q;


    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (matrix[i][j] != 0) Q.push({i, j});
        }
    }


    int queue_size = Q.size();


    while (s > 0) {

        int new_visit[n][n] = {};

        while (queue_size > 0) {
            pair<int, int> cur = Q.front();
            Q.pop();

            for (int dir=0; dir<4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (matrix[nx][ny] != 0 && new_visit[nx][ny] == 0) continue; // 이전 회차에 전염됨
                if (new_visit[nx][ny] != 0 && matrix[nx][ny] <= matrix[cur.first][cur.second]) continue;
                
                matrix[nx][ny] = matrix[cur.first][cur.second];
                new_visit[nx][ny] = 1;
                Q.push({nx, ny});
            }
            queue_size--;
        }
        queue_size = Q.size();

        s--;
    }

    cout << matrix[x-1][y-1];
    


    return 0;
}