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
        cout << 0 << "\n";
        cout << n;
        return 0;
    }

    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();

        int nx[3] = {cur - 1, cur + 1, cur * 2};

        for (int i=0; i<3; i++) {
            if (nx[i] < 0 || nx[i] >= 200002)  continue;
            if (visit[nx[i]] != 0) continue;

            visit[nx[i]] = visit[cur] + 1;

            if (nx[i] == k) break;
            
            Q.push(nx[i]);
        }
    }

    cout << visit[k] - 1 << "\n";

    int back = k;

    vector<int> v;
    v.push_back(back);

    for (int time=visit[k]-1; time>=1; time--) {
        if (back-1 >= 0 && visit[back-1] == time) {
            back = back-1;
        } else if (back+1 < 200002 && visit[back+1] == time) {
            back = back + 1;
        } else if (back%2 == 0 && visit[back/2] == time) {
            back = back/2;
        }

        v.push_back(back);
    }

    for(int i=v.size()-1; i>=0; i--) {
        cout << v[i] << " ";
    }

    return 0;
}