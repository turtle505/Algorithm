#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    long long matrix[n];
    for (int i=0; i<n; i++) {
        cin >> matrix[i];
    }

    for (int i=0; i<m; i++) {
        sort(matrix, matrix+n);
        long long sum = matrix[0] + matrix[1];
        matrix[0] = sum;
        matrix[1] = sum;
    }

    cout << accumulate(matrix, matrix+n, (long long) 0);

    return 0;
}