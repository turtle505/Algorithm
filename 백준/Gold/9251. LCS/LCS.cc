#include <iostream>
#include <string>

int lcs(std::string text1, std::string text2) {

    int text1_len = text1.length();
    int text2_len = text2.length();

    int dp[text1_len+1][text2_len+1] = {};

    int max_length = 0;

    for(int i=1; i<text1_len+1; i++) {
        for(int j=1; j<text2_len+1; j++) {
            if(text1.at(i-1) == text2.at(j-1)) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > max_length) max_length = dp[i][j];
            } else {
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return max_length;
}

int main() {

    std::string text1, text2;
    std::cin >> text1 >> text2;
    std::cout << lcs(text1, text2);

    return 0;
}
