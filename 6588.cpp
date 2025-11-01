#include <iostream>

using namespace std;

bool is_prime[1000001]; // 소수 여부 저장

// 에라토스테네스의 체로 소수 구하기
void makePrime() {
    // 초기화 (2 이상 모두 소수로 가정)
    for (int i = 2; i <= 1000000; i++) {
        is_prime[i] = true;
    }

    for (int i = 2; i * i <= 1000000; i++) {
        if (is_prime[i]) {
            // i의 배수들 제거
            for (int j = i * i; j <= 1000000; j += i) {
                is_prime[j] = false;
            }
        }

    }
}

int main() {

    //입출력 최적화
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    // 소수 미리 계산
    makePrime();

    int n;

    while (cin >> n && n != 0) {

        //n을 두 홀수 소수의 합으로
        bool found = false; //두 소수의 합을 찾았는지 (초기값: 못 찾음)

        //a는 작은 수부터 시작 (b-a가 최대이도록)
        for (int a = 3; a <= n / 2; a += 2) {
            int b = n - a;

            // a, b가 소수인지 확인
            if (is_prime[a] && is_prime[b]) {
                // 출력
                cout << n << " = " << a << " + " << b << '\n';
                found = true;
                break;
            }
        }

        // 못 찾은 경우
        if (!found) {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }

    return 0;
}