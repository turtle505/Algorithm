#include <bits/stdc++.h>
using namespace std;

int n, m;
int numbers[10];
bool isused[10];
int number_count[10001];
int arr[8];

void func(int k) {
    if (k == m) {
        for (int i=0; i<m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i=0; i<10001; i++) {
        if (number_count[i] != 0) {
            arr[k] = i;
            number_count[i]--;
            func(k+1);
            number_count[i]++;
        }
        
    }
}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        cin >> numbers[i];
        number_count[numbers[i]]++;
    }

    sort(numbers, numbers+n);

    func(0);
     
    return 0;
}