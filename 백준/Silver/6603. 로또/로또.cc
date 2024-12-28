#include <bits/stdc++.h>
using namespace std;

int k;
int num[13];
bool isused[13];
int arr[13];

void solve (int n, int next) {
    if (n == 6) {
        for (int i=0; i<6; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for (int i=next; i<k; i++) {
        if (!isused[i]) {
            arr[n] = num[i];
            isused[i] = 1;
            solve(n+1, i+1);
            isused[i] = 0;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (1) {

        cin >> k;
        if (k == 0) break;

        for (int i=0; i<k; i++) {
            cin >> num[i]; 
        }

        solve(0, 0);

        fill(isused, isused+13, 0);
        fill(num, num+13, 0);
        fill(arr, arr+13, 0);

        cout << '\n';

    }

    return 0;
}
