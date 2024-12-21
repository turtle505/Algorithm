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

    int visit[200002] = {};

    Q.push(n);
    visit[n] = 1;

    if (n == k) {
        cout << 0;
        return 0;
    }

    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();

        int nx[3] = {cur - 1, cur + 1, cur * 2};

        for (int i=0; i<3; i++) {
            if (nx[i] < 0 || nx[i] >= 200002)  continue;
       
            if (i == 2)  {
                if (visit[nx[i]] != 0 && visit[cur] >= visit[nx[i]]) continue;
                visit[nx[i]] = visit[cur];
            } else {
                if (visit[nx[i]] != 0 && visit[cur] + 1 >= visit[nx[i]]) continue;
                visit[nx[i]] = visit[cur] + 1;
            }
            
            Q.push(nx[i]);
        }
    }

    cout << visit[k] - 1;

    return 0;
}