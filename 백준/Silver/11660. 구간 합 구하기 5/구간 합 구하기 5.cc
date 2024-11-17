#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[]) {

    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);


    int matrix[n+1][n+1] = {};

    for (int i=1; i<n+1; i++) {
        for (int j=1; j<n+1; j++) {
            scanf("%d", &matrix[i][j]);

            if (i == 1 && j != 1) {
                matrix[i][j] += matrix[i][j-1];
            } else if (i != 1 && j == 1) {
                matrix[i][j] += matrix[i-1][j];
            } else if (i != 1 && j != 1) {
                matrix[i][j] = matrix[i][j] + matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1]; 

            }
        }
    }

    for (int i=0; i<m; i++) {

        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);


        int sum;
        sum = matrix[x2][y2] - matrix[x2][y1-1] - matrix[x1-1][y2] + matrix[x1-1][y1-1];


        // if (x1 == 1 && y1 == 1) {
        //     sum = matrix[x2][y2];
        // } else if (x1 == 1 && y1 != 1) {
        //     sum = matrix[x2][y2] - matrix[x2][y1-1];
        // } else if (x1 != 1 && y1 == 1) {
        //     sum = matrix[x2][y2] - matrix[x1-1][y2];
        // } else {
        //     sum = matrix[x2][y2] - matrix[x2][y1-1] - matrix[x1-1][y2] + matrix[x1-1][y1-1];
        // }



        printf("%d\n", sum);
    }

}