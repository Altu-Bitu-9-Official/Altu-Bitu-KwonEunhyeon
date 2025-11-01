#include <iostream>
#include <vector>

using namespace std;

// 최대공약수 재귀 함수
int getGcdRecur(int a, int b) {
    if (b == 0) {
        return a;
    }
    return getGcdRecur(b, a % b);
}

//절댓값 함수
int absInt(int x) {
    return (x < 0) ? -x : x;
}

int main() {
    int N, S;
    cin >> N >> S;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    //첫 동생과 수빈이 거리차로 초기화
    int gcd = absInt(A[0] - S);

    for (int i = 1; i < N; i++) {
        int diff = absInt(A[i] - S);
        gcd = getGcdRecur(gcd, diff);
    }

    cout << gcd << "\n";

    return 0;
}