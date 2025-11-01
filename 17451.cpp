#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> v(n); // 각 행성 이동 시 필요한 최소 속도

    //속도 입력
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    long long speed = v[n - 1]; //지구 복귀에 필요한 속도로 시작

    //뒤에서부터 역순으로 계산
    for (int i = n - 2; i >= 0; i--) {
        if (speed < v[i]) { //현 속도가 요구 속도보다 작다면,
            speed = v[i]; //요구속도로
        }
        else { //현 속도가 요구 속도보다 크거나 같다면,
            // v[i]의 배수로 만들기
            if (speed % v[i] != 0) { // 나머지가 0이 아니면, 다음 배수로 올림
                speed = (speed / v[i] + 1) * v[i];
            }
            // speed % v[i] == 0 이면 이미 배수임.
        }
    }

    cout << speed;
    return 0;

}