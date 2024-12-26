#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    int n = str.size();
    int m[n];

    for (int i=0; i<n; i++) {
        m[i] = str[i] - '0';
    }

    int count[2] = {};

    count[m[0]]++;

    for (int i=1; i<n; i++) {
        if (m[i-1] != m[i]) {
            count[m[i]]++;
        }
    }

    int result = count[0] > count[1]? count[1]:count[0];

    cout << result;

    return 0;
}