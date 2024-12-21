#include <iostream>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n, l, r;
    cin >> n >> l >> r;

    int people[n][n];

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> people[i][j];
        }
    }

    int day = -1;

    while(1) {
        day++;
        int matrix[n][n] = {};

        int num = 1;

        queue<pair<int, int>> Q;
        vector<pair<int, int>> V;

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (matrix[i][j] != 0) continue;
                matrix[i][j] = num;
                Q.push({i, j});
                V.push_back({i, j});

                while(!Q.empty()) {
                    pair<int, int> cur = Q.front();
                    Q.pop();

                    for (int dir=0; dir<4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (matrix[nx][ny] != 0) continue;

                        if (abs(people[nx][ny] - people[cur.first][cur.second]) >= l && abs(people[nx][ny] - people[cur.first][cur.second]) <= r) {
                            matrix[nx][ny] = num;
                            Q.push({nx, ny});
                        }  
                    }
                }
                num++;
            }
        }

        if (num == n*n + 1) break;

        int num2 = 1;

        int visit[n][n] = {};


        for (pair<int, int> e : V) {
            Q.push(e);

            vector<pair<int, int>> tmp;
            tmp.push_back(e);

            int total_people = people[e.first][e.second];
            int count = 1;

            visit[e.first][e.second] = 1;

            while(!Q.empty()) {
                pair<int, int> cur = Q.front();
                Q.pop();

                for (int dir=0; dir<4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (matrix[nx][ny] == num2 && visit[nx][ny] == 0) {
                        total_people += people[nx][ny];
                        visit[nx][ny] = 1;
                        count++;
                        Q.push({nx, ny});
                        tmp.push_back({nx, ny});
                    }
                }
            }
            
            int each_people = floor(total_people / count);

            Q.push(e);

            for (pair<int, int> d: tmp) {
                people[d.first][d.second] = each_people;
            }

            num2++;
        }
    }

    cout << day;


    return 0;
}