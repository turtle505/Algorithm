#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> v;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({b, a});
    }

    int end = 0;

    int count = 0;

    sort(v.begin(), v.end());

    for (int i=0; i<n; i++) {
        if (end > v[i].second) continue;
        count++;
        end = v[i].first;
    }

    cout << count << '\n';

    return 0;
}