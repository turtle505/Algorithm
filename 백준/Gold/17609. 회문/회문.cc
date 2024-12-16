#include <iostream>
#include <string>

int palindrome(std::string text) {

    int p1 = 0;
    int p2 = text.length() - 1;

    int error = 0;

    while(1) {

        if (text.at(p1) != text.at(p2)) {
            if (text.at(p1+1) == text.at(p2)) {
                error++;
                int p1_tmp = p1 + 1;
                int p2_tmp = p2;
                while(1) {
                    if (text.at(p1_tmp) != text.at(p2_tmp)) {
                        error = 0;
                        break;
                    }
                    p1_tmp++;
                    p2_tmp--;
                    if (p1_tmp - p2_tmp >= 0) return 1;                    
                }
            }
            
            if (text.at(p1) == text.at(p2-1)) {
                error++;
                int p1_tmp = p1;
                int p2_tmp = p2-1;
                while(1) {
                    if (text.at(p1_tmp) != text.at(p2_tmp)) {
                        error++;
                        return 2;
                    }
                    p1_tmp++;
                    p2_tmp--;
                    if (p1_tmp - p2_tmp >= 0) return 1;                    
                }                
            } else {
                return 2;
            }
        } else {
            p1++;
            p2--;
        }

        if (p1 - p2 >= 0) break;

    }

    if (error >= 2) return 2;
    else return error;
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