#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq; //최소 힙 (루트가 가장 작은 수)

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x;
            cin >> x;

            pq.push(x); // 힙 추가

            if (pq.size() > N) {  //힙의 크기 > N 이면, 가장 작은 수 제거 -> 가장 큰 N개의 수 남음
                pq.pop();
            }
        }
    }

    // 최소 힙의 루트 : N번째 큰 수
    cout << pq.top() << "\n";

    return 0;
}
