#include <iostream>
#include <vector>

using namespace std;

int n; //도시 개수
vector<vector<int>> cost;  // 비용 행렬 cost[i][j] = i에서 j로 가는 비용
int min_cost = 999999999;    //최소 비용 초기화

// idx: 현재까지 방문한 도시 개수
// current: 현재 있는 도시 번호
// total_cost: 현재까지의 총 비용
// start: 시작 도시 (마지막에 돌아가야 함)
void backtracking(int idx, int current, int total_cost, int start, vector<bool>& is_used) {
    // 가지치기: 현재 비용이 이미 최소 비용보다 크면 더 이상 탐색 안 함
    if (total_cost >= min_cost) {
        return;
    }

    // 모든 도시를 다 방문한 경우
    if (idx == n) {
        // 현재 도시에서 시작 도시로 돌아갈 수 있는지 확인
        if (cost[current][start] != 0) {
            // 돌아가는 비용까지 더해서 최소 비용 업데이트
            int final_cost = total_cost + cost[current][start];
            if (final_cost < min_cost) {
                min_cost = final_cost;
            }
        }
        return;
    }

    // 다음 방문할 도시 선택
    for (int next = 0; next < n; next++) {
        // 이미 방문한 도시 건너뜀
        if (is_used[next]) {
            continue;
        }

        //현재 도시에서 다음 도시 갈 수 없으면 건너뜀
        if (cost[current][next] == 0) {
            continue;
        }

        //다음 도시 방문
        is_used[next] = true;

        //다음 도시로 이동
        backtracking(idx + 1, next, total_cost + cost[current][next], start, is_used);

        //방문 취소
        is_used[next] = false;
    }
}

int main() {
    cin >> n;  // 도시 개수

    cost.assign(n, vector<int>(n));   //비용 행렬 초기화

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    //방문 체크 배열
    vector<bool> is_used(n, false);

    //0번 도시에서 시작
    is_used[0] = true;

    //백트래킹 시작
    backtracking(1, 0, 0, 0, is_used);

    cout << min_cost << '\n';

    return 0;
}