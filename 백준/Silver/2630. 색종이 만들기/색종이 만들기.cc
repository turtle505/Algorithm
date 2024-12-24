#include <iostream>
#include <vector>

using namespace std;

int count[2] = {};

int matrix[128][128] = {};

int check(int n, int a, int b) {
    int check = matrix[a][b];

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (matrix[a+i][b+j] != check) return -1;
        }
    }

    return check;
}

void func(int n, int a, int b) { // 왼쪽 위 좌표

    if (check(n, a, b) != -1) {
        count[check(n, a, b)]++;
        return;
    } 

    if (check(n/2, a, b) == -1) {
        func(n/2, a, b);
    } else {
        count[check(n/2, a, b)]++;
    }

    if (check(n/2, a+n/2, b) == -1) {
        func(n/2, a+n/2, b);
    } else {
        count[check(n/2, a+n/2, b)]++;
    }

    if (check(n/2, a, b+n/2) == -1) {
        func(n/2, a, b+n/2);
    } else {
        count[check(n/2, a, b+n/2)]++;
    }
    
    if (check(n/2, a+n/2, b+n/2) == -1) {
        func(n/2, a+n/2, b+n/2);
    } else {
        count[check(n/2, a+n/2, b+n/2)]++;
    }
    
}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> matrix[i][j];
        }
    }

    func(n, 0, 0);
 
    cout << count[0] << '\n' << count[1];
    return 0;
}