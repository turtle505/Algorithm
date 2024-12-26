#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int tree[n];
    for (int i=0; i<n; i++) {
        cin >> tree[i];
    }

    sort(tree, tree+n);

    int start = 0;
    int end = tree[n-1];
    int mid = end/2;

    while (1) {
        long long sum = 0;

        for (int j=0; j<n; j++) {
            if (tree[j] > mid) {
                sum += tree[j] - mid;
            }
        }

        if (sum >= m) start = mid;
        else end = mid;

        mid = (start + end) / 2;

        if (start == end || end - start == 1) break;
    }

    cout << start;

    return 0;
}