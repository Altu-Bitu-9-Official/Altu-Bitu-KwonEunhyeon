#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n; //컴퓨터 수
int m; //연결된 컴퓨터 쌍의 수

vector<vector<int>> graph; //네트워크 연결 정보
vector<bool> visited; //방문 체크

int bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int cnt = 0; //감염된 컴퓨터 개수(단,1번 제외)

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        //현재 컴퓨터와 연결된 모든 컴퓨터 탐색
        for (int i = 0; i < graph[cur].size(); i++) {
            int nxt = graph[cur][i];

            //아직 방문 안한 컴퓨터라면
            if (!visited[nxt]) {
                visited[nxt] = true;
                q.push(nxt);
                cnt++; //감염된 컴퓨터 +1
            }
        }
    }

    return cnt;
}

int main() {
    cin >> n;
    cin >> m;

    //초기화
    graph.assign(n + 1, vector<int>());
    visited.assign(n + 1, false);

    //네트워크 연결 정보 입력
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        //a, b 양방향으로 연결
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //계산
    int result = bfs(1);

    cout << result << '\n';

    return 0;
}