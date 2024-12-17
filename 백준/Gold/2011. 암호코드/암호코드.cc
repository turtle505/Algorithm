#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    string code;

    cin >> code;

    int n = code.length();

    int dp[n+1][n+1] = {};

    for (int i=0; i<n+1; i++) {
        fill(dp[i], dp[i]+n+1, 0);
    }

    if (code.at(0) == '0') {
        cout << 0;
        return 0;
    } else if (n == 1) {
        cout << 1;
        return 0;
    }

    dp[1][1] = 1;
    if (code.at(0) == '1' || (code.at(0) == '2' && code.at(1) - '0' <= 6)) {
        dp[1][2] = 1;
    } else {
        dp[1][2] = 0;
    }
    
    for (int i=2; i<n; i++) {
        if (code.at(i-1) == '0') {
            if (code.at(i-2) == '1' || code.at(i-2) == '2') {
                dp[i][i] = 0;
                dp[i][i+1] = 0;
            } else {
                dp[n][n] = 0;
                dp[n-1][n] = 0;
                break;
            }

        } else if (code.at(i-1) == '1' || (code.at(i-1) == '2' && code.at(i) - '0' <= 6)) {
            dp[i][i] = dp[i-1][i-1] + dp[i-2][i-1];
            dp[i][i+1] = dp[i-1][i-1] + dp[i-2][i-1];
        } else {
            dp[i][i] = dp[i-1][i-1] + dp[i-2][i-1];
            dp[i][i+1] = 0;
        }

        dp[i][i] %= 1000000;
        dp[i][i+1] %= 1000000;
    }

    if (code.at(n-1) == '0') {

    } else {
        dp[n][n] = dp[n-1][n-1] + dp[n-2][n-1];
    }

    cout << (dp[n][n] + dp[n-1][n])%1000000;


    return 0;
}