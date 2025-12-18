#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e7;

void floydWarshall(int n, vector<vector<int>>& graph) {
    for (int k = 1; k <= n; k++) { // 중간 정점
        for (int i = 1; i <= n; i++) { //출발 정점
            for (int j = 1; j <= n; j++) { //도착 정점
                int cost = graph[i][k] + graph[k][j];
                graph[i][j] = min(graph[i][j], cost);
            }
        }
    }
}

int main() {
    int n, m, a, b;

    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; i++) {
        graph[i][i] = 0;
    }

    while (m--) {
        cin >> a >> b;
        graph[a][b] = 1;
    }

    floydWarshall(n, graph);

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        int count = 0;

        //i와 비교 가능한 학생 수 세기
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;

            //i->j 갈 수 있거나(i가 작음) || j->i 갈 수 있으면(i가 큼), 비교 가능함
            if (graph[i][j] < INF || graph[j][i] < INF) {
                count++;
            }
        }

        //n-1명 모두와 비교 가능하다면, 내 순위 알 수 있음
        if (count == n - 1) {
            answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}