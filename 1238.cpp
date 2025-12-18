#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> ci;
const int INF = 2e5;

vector<int> dijkstra(int start, int v, vector<vector<ci>>& graph) {
    vector<int> dist(v + 1, INF); //각 정점까지 최단 경로 저장
    //현재 탐색하는 중간 정점까지 최단 경로
    priority_queue<ci, vector<ci>, greater<>> pq; // first: 시작점으로부터의 거리 /  second: 정점

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int weight = pq.top().first; // 현재 정점까지 경로값
        int node = pq.top().second; //현재 탐색하려는 정점
        pq.pop();

        if (weight > dist[node]) { //이미 더 작은 값으로 기록된 정점
            continue;
        }

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            //시작점 -> 현재 node -> 다음 정점으로 가는 경로값
            int next_weight = weight + graph[node][i].second;

            if (next_weight < dist[next_node]) { //최단 경로 값이 갱신된다면,
                dist[next_node] = next_weight;
                pq.push({ next_weight, next_node });
            }
        }
    }

    return dist;
}

int main() {
    int n, m, x, a, b, w;

    cin >> n >> m >> x;
    vector<vector<ci>> graph(n + 1, vector<ci>(0)); 

    while (m--) {
        cin >> a >> b >> w;
        graph[a].push_back({ b, w }); //방향 그래프
    }

    //X -> 각 마을로 돌아가는 최단거리
    vector<int> dist_from_x = dijkstra(x, n, graph);

    // 각 마을 -> X로 가는 최단거리
    int answer = 0;

    for (int i = 1; i <= n; i++) {
        vector<int> dist_to_x = dijkstra(i, n, graph); //i에서 출발
        int round_trip = dist_to_x[x] + dist_from_x[i]; //i->x + x->i
        answer = max(answer, round_trip);
    }

    cout << answer << '\n';

    return 0;
}