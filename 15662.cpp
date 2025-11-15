#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int t; //톱니바퀴 개수
    cin >> t;
    vector<deque<char>> gear(t);

    //톱니바퀴 상태 입력
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        for (char c : s) {
            gear[i].push_back(c);
        }
    }

    int k; //회전 횟수
    cin >> k;

    while (k--) {
        int num, dir; // 회전시킬 톱니바퀴 번호, 회전 방향
        cin >> num >> dir;
        num--; // 입력 1부터 시작하도록

        //톱니바퀴 회전방향 (0: 회전 안함, 1: 시계, -1: 반시계)
        vector<int> rotate(t, 0);
        rotate[num] = dir;

        // 왼쪽 톱니바퀴
        for (int i = num - 1; i >= 0; i--) {
            if (gear[i][2] != gear[i + 1][6]) { // 극 다르면,
                rotate[i] = -rotate[i + 1]; //반대방향 회전
            }
            else { // 극 같으면,
                break; //회전 전달되지 않음
            }
        }

        //오른쪽 톱니바퀴
        for (int i = num + 1; i < t; i++) {
            if (gear[i - 1][2] != gear[i][6]) { //극 다르면,
                rotate[i] = -rotate[i - 1]; //반대방향 회전
            }
            else { // 극 같으면,
                break; // 회전 전달되지 않음
            }
        }

        //회전 실행
        for (int i = 0; i < t; i++) {
            if (rotate[i] == 1) { // 시계방향 회전
                char last = gear[i].back(); // 맨 뒤 톱니 저장
                gear[i].pop_back(); // 맨 뒤 톱니 제거
                gear[i].push_front(last); // 맨 앞 추가
            }
            else if (rotate[i] == -1) { // 반시계방향 회전
                char first = gear[i].front(); // 맨 앞 톱니 저장
                gear[i].pop_front(); // 맨 앞 톱니 제거
                gear[i].push_back(first); // 맨 뒤 추가
            }
            // rotate[i] == 0이면, 회전 안함
        }
    }

    // 12시 방향이 S극인 톱니 개수
    int answer = 0;
    for (int i = 0; i < t; i++) {
        if (gear[i][0] == '1') { // 12시 방향 S극이면
            answer++; // 카운트 증가
        }
    }

    cout << answer;
    return 0;

}