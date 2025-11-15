#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n; // 전체 사람 수
int target1, target2; // 촌수 계산할 두 사람
int m; // 부모-자식 관계 개수

vector<vector<int>> graph; //관계 저장하는 인접리스트
vector<bool> visited; //방문 체크 배열
vector<int> dist; //각 사람까지의 촌수 저장

//BFS 이용
int bfs(int start, int end) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    dist[start] = 0; //시작점: 촌수 0

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        //목표 지점에 도달하면 촌수 반환
        if (cur == end) {
            return dist[end];
        }

        //현재 사람과 연결된 모든 사람 탐색함
        for (int i = 0; i < graph[cur].size(); i++) {
            int nxt = graph[cur][i];

            //방문하지 않은 사람이라면
            if (!visited[nxt]) {
                visited[nxt] = true;
                dist[nxt] = dist[cur] + 1; //촌수 +1
                q.push(nxt);
            }
        }
    }

    //목표 지점 도달하지 못한 경우
    return -1;
}

int main() {
    cin >> n;
    cin >> target1 >> target2;
    cin >> m;

    //그래프 초기화
    graph.assign(n + 1, vector<int>());
    visited.assign(n + 1, false);
    dist.assign(n + 1, 0);

    //부모-자식 관계
    for (int i = 0; i < m; i++) {
        int parent, child;
        cin >> parent >> child;

        //부모 -> 자식, 자식 -> 부모 양방향으로 연결함
        graph[parent].push_back(child);
        graph[child].push_back(parent);
    }

    //촌수 계산
    int result = bfs(target1, target2);

    cout << result << '\n';

    return 0;
}