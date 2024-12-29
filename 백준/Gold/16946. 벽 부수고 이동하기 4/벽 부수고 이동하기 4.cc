#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    string str[n];
    for (int i=0; i<n; i++) {
        cin >> str[i];
    }

    int matrix[n*m] = {};
    int idx = 0;

    int visited[n][m] = {};


    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (str[i][j] == '1') continue;
            if (visited[i][j] != 0) continue;

            queue<pair<int, int>> Q;
            vector<pair<int, int>> v;
            int cnt = 1;
            idx++;
            
            Q.push({i, j});
            v.push_back({i, j});
            visited[i][j] = 1;

            while (!Q.empty()) {
                pair<int, int> cur = Q.front();
                Q.pop();

                for (int dir=0; dir<4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (str[nx][ny] == '1' || visited[nx][ny] != 0) continue;

                    Q.push({nx, ny});
                    v.push_back({nx, ny});
                    visited[nx][ny] = 1;
                    cnt++;
                }
            }
            
            for (pair<int, int> e : v) {
                visited[e.first][e.second] = idx;
                matrix[idx] = cnt;
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (str[i][j] == '0') cout << 0;
            else {
                int sum = 1;
                vector<int> v;
                for (int dir=0; dir<4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (find(v.begin(), v.end(), visited[nx][ny]) != v.end()) continue;
                    v.push_back(visited[nx][ny]);
                }

                for (int e : v) {
                    sum += matrix[e];
                    sum %= 10;
                }
                cout << sum;
            }
        }
        cout << '\n';
    }
    return 0;
}
