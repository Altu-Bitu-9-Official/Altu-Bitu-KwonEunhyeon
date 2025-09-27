#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; //명령의 수

    // 조건 1 ≤ N ≤ 500,000
    while (true) {
        cin >> n;
        if (n >= 1 && n <= 500000) {
            break;
        }
        else {
            cout << "잘못된 입력입니다. 재입력바랍니다.\n";
        }
    }

    queue<int> q;

    // 1부터 n까지 숫자 큐 삽입
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    while (q.size() != 1) {
        q.pop(); // 첫번째 수 제거
        int result = q.front(); // 두번째 수
        q.pop(); //두번째 수 제거
        q.push(result); //두번째 수 맨 뒤에 추가
    }

    //마지막 카드 출력
    cout << q.front() << "\n";
    return 0;
}