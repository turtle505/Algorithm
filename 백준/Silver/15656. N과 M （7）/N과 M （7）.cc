#include <bits/stdc++.h>
using namespace std;

int n, m;
int numbers[10];
int arr[8];

void func(int k) {
    if (k == m) {
        for (int i=0; i<m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i=0; i<n; i++) {
        arr[k] = numbers[i];
        func(k+1);
    }
}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        cin >> numbers[i];
    }

    sort(numbers, numbers+n);

    func(0);
     
    return 0;
}