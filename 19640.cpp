#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Person {
    int id;      // �����ȣ
    int days;    // �ٹ��ϼ�
    int hurry;   // ���� ����
    int line;    // �� ��ȣ
};

//�켱���� �Լ�
struct Compare {
    bool operator()(const Person& a, const Person& b) {
        if (a.days != b.days)
            return a.days < b.days;      // �ٹ��ϼ� ������ ����
        if (a.hurry != b.hurry)
            return a.hurry < b.hurry;  // ���ϸ� ����
        return a.line > b.line;  // �� ��ȣ ������ ����
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    int deca_id = K; //��ī �����ȣ

    vector<Person> people(N);  //��� ���� ����
    vector<queue<int>> lines(M); // ��� �ε��� ����


    //��� ���� �Է�, �� ��ġ
    for (int i = 0; i < N; i++) {
        int D, H;
        cin >> D >> H;

        int line_no = i % M; //i��° ��� : (i % M)��° �ٷ�
        people[i] = { i, D, H, line_no };
        lines[line_no].push(i);
    }

    priority_queue<Person, vector<Person>, Compare> pq;

    // �� ���� ù��° ��� �� �߰�
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

        if (now.id == K) // ��ī ����
            break;

        count++;

        // ���� �� ���� ����� �� �߰�
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

