#include <bits/stdc++.h>
using namespace std;

int n;
int matrix[3000][3000];

void solve (int k) {
    if (k == n) return;

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (i == 0 && j == 0) continue;
            if (i == 1 && j == 1) continue;
            for (int n=0; n<k; n++) {
                for (int m=0; m<k; m++) {
                    matrix[i*k+n][j*k+m] = matrix[n][m];
                }
            }
        }
    }
    solve(k*3);
    
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    matrix[0][0] = 1;
    
    solve(1);

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (matrix[i][j] == 1) cout << "*";
            else cout << " ";
        }
        cout << '\n';
    }

    return 0;
}
