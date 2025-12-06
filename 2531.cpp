#include <iostream>
#include <vector>

using namespace std;


// belt: 회전 초밥 벨트 배열
// n: 회전 초밥 벨트에 놓인 접시 수
// d: 초밥의 가짓수,  k: 연속해서 먹는 접시 수
// c: 쿠폰 번호
int calcMaxSushi(vector<int>& belt, int n, int d, int k, int c) {

    //각 초밥 종류별로 현재 윈도우에 몇 개 있는지 카운트하는 배열
    vector<int> count_sushi(d + 1, 0);

    // 초기화: 첫 번째 윈도우
    int cnt_types = 0; //현재 윈도우의 초밥 종류 수
    for (int i = 0; i < k; i++) {
        //처음 나타나는 초밥이면 종류 수 증가
        if (count_sushi[belt[i]] == 0) {
            cnt_types++;
        }
        count_sushi[belt[i]]++; //초밥 개수 증가
    }

    int max_types = cnt_types;
    if (count_sushi[c] == 0) { //쿠폰 초밥이 윈도우에 없으면
        max_types = cnt_types + 1; //추가로 +1
    }

    for (int i = 1; i < n; i++) { //i = 새로운 윈도우의 시작 위치
        int remove_sushi = belt[i - 1]; //윈도우 맨 앞 초밥 제거
        count_sushi[remove_sushi]--; //개수 감소
        if (count_sushi[remove_sushi] == 0) { //더 이상 없다면,
            cnt_types--; //종류 수 감소
        }

        int add_sushi = belt[(i + k - 1) % n]; //윈도우 맨 뒤에 추가될 초밥
        if (count_sushi[add_sushi] == 0) { //처음 나타나는 초밥이면,
            cnt_types++; //종류 수 증가
        }
        count_sushi[add_sushi]++; //개수 증가

        //현재 윈도우의 최대 종류 수 계산
        int current_max = cnt_types;
        if (count_sushi[c] == 0) { //쿠폰 초밥이 윈도우에 없으면
            current_max = cnt_types + 1; // 추가로 +1
        }

        //답 갱신
        if (current_max > max_types) {
            max_types = current_max;
        }
    }

    return max_types;
}

int main() {
    int n, d, k, c;

    cin >> n >> d >> k >> c;

    vector<int> belt(n, 0); //벨트 위의 초밥
    for (int i = 0; i < n; i++) {
        cin >> belt[i];
    }

    //먹을 수 있는 초밥 가짓수 최댓값 계산
    int answer = calcMaxSushi(belt, n, d, k, c);

    cout << answer << '\n';

    return 0;
}