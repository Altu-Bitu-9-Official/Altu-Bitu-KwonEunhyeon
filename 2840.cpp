#include <iostream>
using namespace std;

int N, K;
char wheel[25];  // 바퀴
int S[100];      // 회전 칸 수
char letter[100]; // 멈춘 위치 글자

// 바퀴에 글자 이미 사용되었는지 확인여부 함수
bool Used(char c) {
    for (int i = 0; i < N; i++) {
        if (wheel[i] == c) {
            return true;
        }
    }
    return false;
}

// 바퀴회전 및 글자배치 함수
bool rotateWheel() {
    int pos = 0;  //현 화살표가 가리키는 바퀴 위치

    // K번 회전
    for (int i = 0; i < K; i++) {
        // 바퀴를 시계방향으로 S[i]칸 회전 -> 화살표는 반시계방향으로 S[i]칸 이동
        pos = (pos - S[i] % N + N) % N;

        // 현재 위치 글자 확인
        if (wheel[pos] == '?') {  // 어떤 글자인지 결정 못한 칸
            // 글자가 다른 곳에 사용되었는지 확인
            if (Used(letter[i])) {
                return false;  // 같은 글자 두 곳에 있으면 false
            }
            wheel[pos] = letter[i];  // 글자배치
        }
        else { //글자 결정된 칸
            // 같은 글자인지 확인
            if (wheel[pos] != letter[i]) {
                return false;  // 다른 글자면 false
            }
        }
    }

    // 마지막 위치부터 시계방향 출력
    for (int i = 0; i < N; i++) {
        cout << wheel[pos];
        pos = (pos + 1) % N; //시계방향
    }
    cout << '\n';

    return true;
}

int main() {
    //입력
    cin >> N >> K;

    // 바퀴 초기화
    for (int i = 0; i < N; i++) {
        wheel[i] = '?'; //모든 칸 아직 결정되지 않음
    }

    //회전 정보 입력
    for (int i = 0; i < K; i++) {
        cin >> S[i] >> letter[i];
    }

    //연산 
    bool result = rotateWheel();

    //출력
    if (!result) {
        cout << "!\n";
    }

    return 0;
}