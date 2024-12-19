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
    visit[n] = 1;
    visit[k] = -1;

    if (n == k) {
        cout << 0;
        return 0;
    }

    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();

        int nx[3] = {cur - 1, cur + 1, cur * 2};

        for (int i=0; i<3; i++) {
            if (nx[i] < 0 || nx[i] >= 100001 || visit[nx[i]] > 0)  continue;
       
            if (visit[nx[i]] == -1) {
                cout << visit[cur];
                return 0;
            } 

            visit[nx[i]] = visit[cur] + 1;
            Q.push(nx[i]);
        }
    }

    cout << "fail";

    return 0;
}