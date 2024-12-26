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

    int num_0 = 0;
    int num_1 = 0;

    if(m[0] == 1) num_0++;
    else num_1++;

    for (int i=1; i<n; i++) {
        if (m[i-1] != m[i]) {
            if (m[i-1] == 0) num_0++;
            else num_1++;
        }
    }

    cout << min(num_0, num_1);

    return 0;
}