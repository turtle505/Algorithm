#include <iostream>

int main() {
    
    int t;
    std::cin >> t;
    
    int dp[31][31] {};
    
    for(int i=1; i<31; i++) {
        dp[i][i] = 1;
        dp[1][i] = i;
    }
    
    for(int j=2; j<31; j++) {
        for(int i=2; i<j; i++) {
            for(int k=i-1; k<j; k++) {
                dp[i][j] += dp[i-1][k];
            }
        }
    }
    
    for(int i=0; i<t; i++) {
        int a, b;
        std::cin>>a>>b;
        
        std::cout << dp[a][b] << std::endl;         
    }
    
    return 0;
    
}