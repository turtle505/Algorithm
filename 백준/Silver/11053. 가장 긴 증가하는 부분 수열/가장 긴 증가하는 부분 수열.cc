#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n;
    cin >> n;

    int arr[n] = {};
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int cp[n] = {};
    fill(cp, cp+n, 1);

    int max_length = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (arr[j] < arr[i]) cp[i] = max(cp[j]+1, cp[i]);
        }

        max_length = max(max_length, cp[i]);
    }

    cout << max_length << '\n';

    return 0;
}