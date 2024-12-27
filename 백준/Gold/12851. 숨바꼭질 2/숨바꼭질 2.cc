#include <iostream>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n, k;

    cin >> n >> k;

    queue<int> Q;

    int visit[100001] = {};

    Q.push(n);

    if (n == k) {
        cout << 0 << '\n' << 1;
        return 0;
    }

    int min = -1;
    int count = 0;

    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();

        int nx[3] = {cur - 1, cur + 1, cur * 2};

        for (int i=0; i<3; i++) {
            if (nx[i] < 0 || nx[i] >= 100001)  continue;
            if (visit[nx[i]] != 0 && visit[nx[i]] < visit[cur] + 1) continue;
            
            visit[nx[i]] = visit[cur] + 1;
            
            if (nx[i] == k) {
                if (min == -1 || min == visit[nx[i]]) {
                    min = visit[nx[i]];
                    count++;
                    continue;
                }
            } 
            Q.push(nx[i]);
        }
    }

    cout << min << '\n' << count;


    return 0;
}