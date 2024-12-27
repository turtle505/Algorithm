#include <bits/stdc++.h>
using namespace std;

int l, c;

char characters[15];
bool isused[15] = {};
char arr[15];

void func(int k, int vowel, int next) {
    if (k == l) {
        if (vowel == 0 || l - vowel < 2) return;
        else {
            for (int i=0; i<l; i++) {
                cout << arr[i];
            }
            cout << '\n';
            return;
        }
    }

    for (int i=next; i<c; i++) {
        if (!isused[i]) {
            arr[k] = characters[i];
            isused[i] = 1;
            if (characters[i] == 'a' || characters[i] == 'e' || characters[i] == 'i' || characters[i] == 'o' || characters[i] == 'u')
                func(k+1, vowel+1, i+1);
            else
                func(k+1, vowel, i+1);
            isused[i] = 0;
        }
    }

    return;

}


int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> l >> c;
    
    for (int i=0; i<c; i++) 
        cin >> characters[i];

    sort(characters, characters+c);

    func(0, 0, 0);


    return 0;
}