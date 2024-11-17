#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {

    int n;
    std::cin >> n;

    int dp[n+1] = {};

    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for(int i=4; i<=n; i++) {
        int tmp = dp[i-1] + 1;
        if (i%2 == 0) {
            if (tmp > dp[i/2] + 1) {
                tmp = dp[i/2] + 1;
            }
        }
        if (i%3 == 0) {
            if (tmp > dp[i/3] + 1) {
                tmp = dp[i/3] + 1;
            }
        }
        dp[i] = tmp;
    }

    std::cout << dp[n];

}