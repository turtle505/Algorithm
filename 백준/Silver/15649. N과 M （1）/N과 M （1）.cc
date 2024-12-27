#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[8];
bool isused[10];

void func(int k) {
    if (k == m) {
        for (int i=0; i<m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }

    for (int i=1; i<=n; i++) {
        if (!isused[i]) {
            arr[k] = i;
            isused[i] = 1;
            func(k+1);
            isused[i] = 0;
        }
    }
}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    cin >> n >> m;

    func(0);
     
    return 0;
}