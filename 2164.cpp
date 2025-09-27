#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; //����� ��

    // ���� 1 �� N �� 500,000
    while (true) {
        cin >> n;
        if (n >= 1 && n <= 500000) {
            break;
        }
        else {
            cout << "�߸��� �Է��Դϴ�. ���Է¹ٶ��ϴ�.\n";
        }
    }

    queue<int> q;

    // 1���� n���� ���� ť ����
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    while (q.size() != 1) {
        q.pop(); // ù��° �� ����
        int result = q.front(); // �ι�° ��
        q.pop(); //�ι�° �� ����
        q.push(result); //�ι�° �� �� �ڿ� �߰�
    }

    //������ ī�� ���
    cout << q.front() << "\n";
    return 0;
}