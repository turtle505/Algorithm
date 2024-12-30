#include <iostream>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n, m;
    cin >> n >> m;

    int matrix[n][n];
    for (int i=0; i<n; i++) {
        fill(matrix[i], matrix[i]+n, 0x3f3f3f3f);
        matrix[i][i] = 0;
    }

    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        matrix[a-1][b-1] = min(matrix[a-1][b-1], c);
    }


    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (matrix[i][j] > matrix[i][k] + matrix[k][j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }



    int k;
    cin >> k;
    int city[k];
    for (int i=0; i<k; i++) {
        cin >> city[i];
        city[i]--;
    }


    vector<int> min;
    int min_time = 0x3f3f3f3f;

    for (int i=0; i<n; i++) {
        int time = 0;
        for (int p=0; p<k; p++) {
            time = max(time, matrix[i][city[p]]+matrix[city[p]][i]);
        }

        if (min_time > time) {
            min_time = time;
            min.clear();
            min.push_back(i);
        } else if (min_time == time) {
            min.push_back(i);
        }
    }

    sort(min.begin(), min.end());

    for (int e : min) {
        cout << e+1 << ' ';
    }

    return 0;
}