#include <iostream>
#include <string>

using namespace std;

int count[2] = {};

int matrix[64][64] = {};

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
        cout << check(n, a, b);
        return;
    } 

    cout << "(";
    func(n/2, a, b);
    func(n/2, a, b+n/2);
    func(n/2, a+n/2, b);
    func(n/2, a+n/2, b+n/2);
    cout << ")";
}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        string str;
        cin >> str;

        for (int j=0; j<n; j++) {
            matrix[i][j] = str[j] - '0';
        }
    }

    func(n, 0, 0);

    return 0;
}