#include <bits/stdc++.h>
using namespace std;

string str[5];
int matrix[5][5] = {};
int visited[5][5] = {};
int cnt = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<vector<pair<int, int>>> S;

void solve (int k, int a, int b, int lee, int lim) {
    if (k == 7) {
        if (lee >= 4) {
            for (int i=0; i<5; i++) {
                fill(visited[i], visited[i]+5, 0);
            }
            
            int num = 0;

            queue<pair<int, int>> Q;
            Q.push({a, b});
            visited[a][b] = 1;
            num++;

            while (!Q.empty()) {
                pair<int, int> cur = Q.front();
                Q.pop();

                for (int dir=0; dir<4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                    if (visited[nx][ny] != 0) continue;
                    if (matrix[nx][ny] == 0) continue;

                    Q.push({nx, ny});
                    visited[nx][ny] = 1;
                    num++;
                }
            }

            if (num == 7) cnt++;
        }
        return;
    }

    
    for (int i=a; i<5; i++) {
        for (int j=0; j<5; j++) {
            if (i == a && j < b) continue;
            if (matrix[i][j] != 0) continue;
            matrix[i][j] = 1;
            if (str[i][j] == 'S') solve(k+1, i, j, lee+1, lim);
            else solve(k+1, i, j, lee, lim+1);
            matrix[i][j] = 0;

        }
    }
    
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for (int i=0; i<5; i++) {
        cin >> str[i];
    }
    
    solve(0, 0, 0, 0, 0);

    cout << cnt;

    return 0;
}
