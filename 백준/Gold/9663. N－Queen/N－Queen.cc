#include <bits/stdc++.h>
using namespace std;

int n;
int num = 0;

bool column[40];
bool diag1[40];
bool diag2[40];


void func(int k) {
    if (k == n) {
        num++;
        return;
    }

    for (int i=0; i<n; i++) {
        if (column[i] || diag1[i+k] || diag2[k-i+n-1]) continue;
        column[i] = 1;
        diag1[i+k] = 1;
        diag2[k-i+n-1] = 1;
        func(k+1);
        column[i] = 0;
        diag1[i+k] = 0;
        diag2[k-i+n-1] = 0;
    }

    return;
}


int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> n;

    func(0);

    cout << num;

    return 0;
}