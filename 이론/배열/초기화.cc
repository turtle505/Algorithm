#include <cstring>
#include <algorithm>

int main() {
    int a[21];
    int b[21][21];

    // 1. memset
    memset(a, 1, sizeof a);
    memset(b, 0, sizeof b);

    // 2. for
    for (int i=0; i<21; i++) {
        a[i] = 0;
    }
    for (int i=0; i<21; i++) {
        for (int j=0; j<21; j++) {
            b[i][j] = 0;
        }
    }

    // 3. fill
    fill(a, a+21, 0);
    for (int i=0; i<21; i++) {
        fill(b[i], b[i]+21, 0);
    }
}
