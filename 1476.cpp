#include <iostream>

using namespace std;

const int MAX_E = 15;
const int MAX_S = 28;
const int MAX_M = 19;

// E S M에 해당하는 연도 찾기 (브루트포스 활용) 
int findYear(int E, int S, int M){
    int year = 1;
    int e = 1, s = 1, m = 1;

    while (true){
        // 목표 연도를 찾았는지 확인
        if (e == E && s == S && m == M) {
            return year;
        }

        // 다음 연도 이동
        year++;
        e++;
        s++;
        m++;

        // 범위 초과 : 1로 초기화
        if (e > MAX_E) e = 1;
        if (s > MAX_S) s = 1;
        if (m > MAX_M) m = 1;
    }
}

int main(){
    int E, S, M;
    cin >> E >> S >> M;

    int result = findYear(E, S, M);
    cout << result << "\n";

    return 0;
}