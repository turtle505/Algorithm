#include <bits/stdc++.h>
using namespace std;

int n, s;
int cnt;
int num[20];
bool isused[20];


void func(int k, int sum) {
    if (k == n) {
        if (sum == s) {
            cnt++;
            return;
        } else {
            return;
        }
        
    }

    func(k+1, sum);
    func(k+1, sum+num[k]);

    return;
}


int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> n >> s;

    for (int i=0; i<n; i++) {
        cin >> num[i];
    }

    func(0, 0);
    
    if(s == 0) cnt--;
    cout << cnt;

    return 0;
}