#include <iostream>
using namespace std;

int func2(int arr[], int N) {

    int tmp[101] = {};
    for (int i=0; i<N; i++) {
        tmp[100 - arr[i]]++;
    }

    for (int i=0; i<N; i++) {
        if (tmp[arr[i]] != 0) return 1;
    }
    return 0;
}

int main(void) {

    int arr[3] = {1, 52, 48};
    cout << func2(arr, 3) <<'\n';

}
