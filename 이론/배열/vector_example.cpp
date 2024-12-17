#include <bits/stdc++.h>
using namespace std;

int main(void) {

  
  /* basic mathods */
  vector<int> v1(3, 5); // {5,5,5};
  cout << v1.size() << '\n'; // 3
  v1.push_back(7); // {5,5,5,7};

  vector<int> v2(2); // {0,0};
  v2.insert(v2.begin()+1, 3); // {0,3,0};

  vector<int> v3 = {1,2,3,4}; // {1,2,3,4}
  v3.erase(v3.begin()+2); // {1,2,4};

  vector<int> v4; // {}
  v4 = v3; // {1,2,4}
  cout << v4[0] << v4[1] << v4[2] << '\n';
  v4.pop_back(); // {1,2}
  v4.clear(); // {}


  
  /* iteration */
  vector<int> v5 = {1, 2, 3, 4, 5, 6};

  // 1. range-based for lop
  for (int e : v5)
    cout << e << ' ';

  // 2. not bad
  for (int i=0; i<v5.size(); i++) {
    cout << v5[i] << ' ';
  }

  // 3. ***wrong***
  for (int i=0; i<=v5.size()-1; i++) {
    cout << v5[i] << ' ';
  }
  /* 기본적으로 vector size 메소드는 시스템에 따라 unsigned int or unsigned long long 반환. */
  /* 1은 int 이므로 연산 결과 unsigned int로 자동 형변환 발생 -> unsigned int overflow */
}
