#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int palindrome(int arr[], int a, int b) {
    while(1) {
        if (arr[a-1] != arr[b-1]) return 0;
        a++;
        b--;
        if (a >= b) break;
    }

    return 1;
}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int arr[n] = {};
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    
    int dp[n+1][n+1];

    for (int i=0; i<n+1; i++) {
        fill(dp[i], dp[i]+n+1, 0);
    }

    int length = 1;

    for(int length = 1; length <= n; length ++) {
        for (int i=1; i<n+2-length; i++) {
            int a = i;
            int b = i + length - 1;

            while(1) {
                if (arr[a-1] != arr[b-1]) {
                    dp[i][i+length - 1] = 0;
                    break;
                }

                a++;
                b--;

                if (a >= b || dp[a][b] == 1) {
                    dp[i][i+length-1] = 1;
                    break;
                }
            }
        }
    }


    int m;
    cin >> m;

    for (int i=0; i<m; i++) {
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << '\n'; 
    }

    return 0;
}