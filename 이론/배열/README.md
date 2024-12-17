# 배열

## 초기화
[초기화.cc](https://github.com/turtle505/Algorithm/blob/main/%EC%9D%B4%EB%A1%A0/%EB%B0%B0%EC%97%B4/%EC%B4%88%EA%B8%B0%ED%99%94.cc)
1. cstring 헤더의 memset 함수.
   - 0, -1만 넣을 수 있음
   - 2차원 이상의 배열을 함수의 인자로 넘기면 오동작
3. for문 이용. 하나하나 바꾸기.
4. algorithm 헤더의 fill 함수 => 가장 추천

## STL Vector
[여러 메소드들과 원소 순회 예시](https://github.com/turtle505/Algorithm/blob/main/%EC%9D%B4%EB%A1%A0/%EB%B0%B0%EC%97%B4/vector_example.cpp)

Vector는 배열과 거의 동일한 기능을 수행하는 자료구조로, 배열과 마찬가지로 원소가 메모리에 연속하게 저장되어 있어 O(1)에 인덱스를 가지고 각 원소에 접근할 수 있다. 배열과 달리 크기를 자유롭게 늘이거나 줄일 수 있다.

- insert, erase: O(N)
- push_back, pop_back: O(1)

또한, vector에서 =을 사용하면 deep copy 발생.

## 예제
주어진 길이 N의 int 배열 arr에서 합이 100인 서로 다른 위치의 두 원소가 존재하면 1을, 존재하지 않으면 0을 반환하는 함수를 작성하라. (조건: O(N))
