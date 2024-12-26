#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int matrix[n];
    for (int i=0; i<n; i++) {
        cin >> matrix[i];
    }

    sort(matrix, matrix+n);

    for (int i=n-1; i>=0; i--) {
        cout << matrix[i] << '\n';
    }

    return 0;
}