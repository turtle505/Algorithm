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

    // i번째에서 끝나는 거 개수..
    int dp[n+1] = {};

    fill(dp, dp+n+1, 0);

    // process first element

    dp[0] = 1;
    dp[1] = 1;

    if (code.at(0) == '0') {
        dp[1] = 0;
        cout << 0;
        return 0;
    }

    for (int i=2; i<n+1; i++) {
        if (code.at(i-1) == '0') {
            if (code.at(i-2) == '1' || code.at(i-2) == '2') {
                dp[i] = dp[i-2];
            } else {
                dp[n] = 0;
                break;
            }
        } else if (code.at(i-2) == '1' || (code.at(i-2) == '2' && code.at(i-1) - '0' <= 6)) {
            dp[i] += dp[i-1] + dp[i-2];
        } else {
            dp[i] += dp[i-1];
        }

        dp[i] %= 1000000;
    }

    cout << (dp[n])%1000000;


    return 0;
}