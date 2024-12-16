/* 틀린 부분을 찾는 함수를 따로 만들었다. 메모리, 시간은 비효율적이지만 깔끔. */

#include <iostream>
#include <string>

int find(std::string text, int *p1, int *p2) {

    while(1) {

        if (text.at(*p1) != text.at(*p2)) {
            return 1;
        }

        *p1 += 1;
        *p2 -= 1;

        if (*p1 - *p2 >= 0) return 0;
    }
}

int palindrome(std::string text) {


    int* p1 = (int*)malloc(sizeof(int));
    int* p2 = (int*)malloc(sizeof(int));

    *p1 = 0;
    *p2 = text.length() - 1;

    int error = 0;

    if(find(text, p1, p2)){

        if (text.at(*p1+1) == text.at(*p2)) {
            int *tmp1 = (int*)malloc(sizeof(int));
            *tmp1 = *p1 + 1;
            int *tmp2 = (int*)malloc(sizeof(int));
            *tmp2 = *p2;

            if (!find(text, tmp1, tmp2)) {
                error = 1;
            } else {
                error = 2;
            }

            free(tmp1);
            free(tmp2);
        }

        if (text.at(*p1) == text.at(*p2-1)) { // error is 1

            int *tmp1= (int*)malloc(sizeof(int));
            *tmp1 = *p1;
            int *tmp2= (int*)malloc(sizeof(int));
            *tmp2 = *p2 - 1;

            if (!find(text, tmp1, tmp2)) {
                error = 1;
            } else {
                if (error != 1) error = 2;
            }
            
            free(tmp1);
            free(tmp2);
        } 

        if (text.at(*p1+1) != text.at(*p2) && text.at(*p1) != text.at(*p2-1)) error = 2;
            
    }

    free(p1);
    free(p2);


    return error;
}


int main() {

    int t;
    std::cin >> t;

    for (int i=0; i<t; i++) {
        std::string text;
        std::cin >> text;
        std::cout << palindrome(text) << std::endl;
    }

    return 0;
}
