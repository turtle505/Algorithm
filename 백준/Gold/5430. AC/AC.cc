#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void print(int* array, int size, int start, int end);

int error = 0;
int reverse = 0;

int main() {

    int t;
    std::cin >> t;

    for(int i=0; i<t; i++) {
        std::string func;
        int n;
        std::string array_input;
        int size;
        int idx_start = 0;
        int idx_end;


        std::cin >> func >> n >> array_input;
        size = n;
        int array[n] = {};
        idx_end = size - 1;
        int tmp = 1;
        int idx = 0;

        for (int j=1; j<array_input.length(); j++) {
            if (array_input.substr(j-1,1) == "[" && array_input.substr(j,1) == "]") break;
            if (array_input.substr(j,1) == "," || array_input.substr(j,1) == "]") {
                array[idx] = std::stoi(array_input.substr(tmp,j-tmp));
                tmp = j+1;
                idx++;
            }
        }

        error = 0;
        reverse = 0;

        for(int j=0; j<func.length(); j++) {
            if (func.substr(j,1) == "R") {
                if (reverse == 0) reverse = 1;
                else reverse = 0;
            } else if (func.substr(j,1) == "D") {
                if (size == 0) {
                    error = 1;
                    break;
                }
                else {
                    switch (reverse) {
                        case 0:
                            idx_start += 1;
                            size -= 1;
                            break;
                        case 1:
                            idx_end -= 1;
                            size -= 1;
                            break;
                    }
                }
            }
        }
        if (size < 0) {
            error = 1;
        }
        print(array, size, idx_start, idx_end);
    }

    return 0;
}

void print(int* array, int size, int start, int end){
    switch (error) {
        case 0:
            if (size == 0) std::cout << "[]" << std::endl;
            else {
                switch (reverse) {
                    case 0:
                        std::cout<<"[";
                        for(int i=start; i<end; i++) {
                            std::cout<<array[i]<<",";
                        }
                        std::cout<<array[end]<<"]"<<std::endl;
                        break;
                    case 1:
                        std::cout<<"[";
                        for(int i=end; i>start; i--) {
                            std::cout<<array[i]<<",";
                        }
                        std::cout<<array[start]<<"]"<<std::endl;
                        break;
                }
            }
            break;
        case 1:
            std::cout << "error" << std::endl;
            break;
    }
    
}