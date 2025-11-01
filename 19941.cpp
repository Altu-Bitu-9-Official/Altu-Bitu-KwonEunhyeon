#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int answer = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'P') { // 사람이라면,
            // 먹을 수 있는 범위 계산
            int start = max(0, i - k);
            int end = min(n - 1, i + k);

            //왼쪽부터 가까운 햄버거 찾음
            for (int j = start; j <= end; j++) {
                if (s[j] == 'H') { //햄버거 발견한다면,
                    s[j] = 'X'; //햄버거 먹음 표시
                    answer++; //먹은 햄버거 수 증가
                    break; //다음 사람
                }
            }
        }
    }

    cout << answer;
    return 0;

}