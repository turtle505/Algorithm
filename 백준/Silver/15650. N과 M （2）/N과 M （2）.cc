#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool isused[10];

void func(int k, int next) {
    if (k == m) {
        for (int i=0; i<m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i=next; i<=n; i++) {
        if (!isused[i]) {
            arr[k] = i;
            isused[i] = 1;
            func(k+1, i+1);
            isused[i] = 0;
        }
    }
}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    cin >> n >> m;

    func(0, 1);
     
    return 0;
}