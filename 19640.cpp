#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Person {
    int id;      // 사원번호
    int days;    // 근무일수
    int hurry;   // 급한 정도
    int line;    // 줄 번호
};

//우선순위 함수
struct Compare {
    bool operator()(const Person& a, const Person& b) {
        if (a.days != b.days)
            return a.days < b.days;      // 근무일수 많으면 먼저
        if (a.hurry != b.hurry)
            return a.hurry < b.hurry;  // 급하면 먼저
        return a.line > b.line;  // 줄 번호 작으면 먼저
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    int deca_id = K; //데카 사원번호

    vector<Person> people(N);  //사원 정보 저장
    vector<queue<int>> lines(M); // 사원 인덱스 저장


    //사원 정보 입력, 줄 배치
    for (int i = 0; i < N; i++) {
        int D, H;
        cin >> D >> H;

        int line_no = i % M; //i번째 사람 : (i % M)번째 줄로
        people[i] = { i, D, H, line_no };
        lines[line_no].push(i);
    }

    priority_queue<Person, vector<Person>, Compare> pq;

    // 각 줄의 첫번째 사람 힙 추가
    for (int i = 0; i < M; i++) {
        if (!lines[i].empty()) {
            int idx = lines[i].front();
            lines[i].pop();
            pq.push(people[idx]);
        }
    }

    int count = 0;

    while (!pq.empty()) {
        Person now = pq.top();
        pq.pop();

        if (now.id == K) // 데카 차례
            break;

        count++;

        // 같은 줄 다음 사람을 힙 추가
        int line_no = now.line;
        if (!lines[line_no].empty()) {
            int idx = lines[line_no].front();
            lines[line_no].pop();
            pq.push(people[idx]);
        }
    }

    cout << count << "\n";

    return 0;
}

