#include <bits/stdc++.h>
using namespace std;

int n;
int max_cnt = 0;
int strength[10];
int weight[10];

void solve (int k) {

    if (k == n) {
        int cnt = 0;
        for (int i=0; i<n; i++) {
            if (strength[i] <= 0) cnt++;
        }
        if (cnt > max_cnt) max_cnt = cnt;
        return;
    }

    for (int i=0; i<n; i++) {
        if (i == k) continue;
        if (strength[k] <= 0 || strength[i] <= 0) {
            solve(k+1);
            continue;
        }
        strength[k] -= weight[i];
        strength[i] -= weight[k];
        solve(k+1);
        strength[k] += weight[i];
        strength[i] += weight[k];
    }

}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> strength[i];
        cin >> weight[i];
    }

    solve(0);

    cout << max_cnt;

    return 0;
}
