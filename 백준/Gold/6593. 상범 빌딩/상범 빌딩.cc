#include <iostream>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};

struct coordinate {
    int first;
    int second;
    int third;
};

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (1) {
        int l, r, c;
        
        cin >> l >> r >> c;

        if (l == 0) break;

        struct coordinate escape;
        queue<struct coordinate> Q;

        int matrix[l][r][c];
        for (int i=0; i<l; i++) {
            for (int j=0; j<r; j++) {
                string str;
                cin >> str;
                for (int k=0; k<c; k++) {
                    if (str[k] == '#') matrix[i][j][k] = -1;
                    else if (str[k] == '.') matrix[i][j][k] = 0;
                    else if (str[k] == 'E') {
                        matrix[i][j][k] = 0;
                        escape.first = i;
                        escape.second = j;
                        escape.third = k;
                    } else {
                        struct coordinate tmp = {i, j, k};
                        Q.push(tmp);
                        matrix[i][j][k] = 1;
                    }
                }

            }
        }

        while (!Q.empty()) {
            struct coordinate cur = Q.front();
            Q.pop();

            for (int dir=0; dir<6; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                int nz = cur.third + dz[dir];

                if (nx<0 || nx>=l || ny<0 || ny>=r || nz<0 || nz>=c) continue;
                if (matrix[nx][ny][nz] != 0) continue;

                matrix[nx][ny][nz] = matrix[cur.first][cur.second][cur.third] + 1;
                struct coordinate tmp;
                tmp.first = nx;
                tmp.second = ny;
                tmp.third = nz;
                Q.push(tmp);
            }
        }

        if (matrix[escape.first][escape.second][escape.third] > 0) 
            cout << "Escaped in " << matrix[escape.first][escape.second][escape.third] - 1 << " minute(s)." << "\n";
        else cout << "Trapped!" << "\n";

    }

    return 0;
}