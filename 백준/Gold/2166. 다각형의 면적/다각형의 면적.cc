#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<pair<double, double>> v;
    for (int i=0; i<n; i++) {
        double a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    double sum = 0;
    for (int i=1; i<n-1; i++) {
        double a = v[0].first;
        double b = v[0].second;
        double c = v[i].first;
        double d = v[i].second;
        double e = v[i+1].first;
        double f = v[i+1].second;

        sum += (a*d + c*f + e*b - c*b - e*d - a*f) / 2;
    }

    cout << fixed;
    cout.precision(1);
    cout << abs(sum);
    
    return 0;
}
