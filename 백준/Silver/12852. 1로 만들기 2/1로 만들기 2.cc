#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {

    int n;
    std::cin >> n;

    int dp[n+1] = {};
    int trace[n+1] = {};

    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    trace[1] = 1;
    trace[2] = 1;
    trace[3] = 1;

    for(int i=4; i<=n; i++) {
        int tmp1, tmp2, tmp3;
        tmp1 = dp[i-1] + 1;
        if(i%2 == 0) tmp2 = dp[i/2] + 1;
        else tmp2 = 99999;
        if(i%3 == 0) tmp3 = dp[i/3] + 1;
        else tmp3 = 99999;

        if (tmp1 > tmp2) {
            if (tmp2 > tmp3) {
                dp[i] = tmp3;
                trace[i] = i/3;
            } else {
                dp[i] = tmp2;
                trace[i] = i/2;
            }
        } else {
            if (tmp1 > tmp3) {
                dp[i] = tmp3;
                trace[i] = i/3;
            } else {
                dp[i] = tmp1;
                trace[i] = i-1;
            }
        }
        // std::cout << trace[i] << std::endl;
    }

    std::cout << dp[n] << std::endl;

    int idx = n;

    std::cout << n << " ";

    while(idx > 1) {
        std::cout << trace[idx] << " ";
        idx = trace[idx];
    }

    return 0;

}