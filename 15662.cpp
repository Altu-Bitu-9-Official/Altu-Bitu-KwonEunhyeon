#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int t; //��Ϲ��� ����
    cin >> t;
    vector<deque<char>> gear(t);

    //��Ϲ��� ���� �Է�
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        for (char c : s) {
            gear[i].push_back(c);
        }
    }

    int k; //ȸ�� Ƚ��
    cin >> k;

    while (k--) {
        int num, dir; // ȸ����ų ��Ϲ��� ��ȣ, ȸ�� ����
        cin >> num >> dir;
        num--; // �Է� 1���� �����ϵ���

        //��Ϲ��� ȸ������ (0: ȸ�� ����, 1: �ð�, -1: �ݽð�)
        vector<int> rotate(t, 0);
        rotate[num] = dir;

        // ���� ��Ϲ���
        for (int i = num - 1; i >= 0; i--) {
            if (gear[i][2] != gear[i + 1][6]) { // �� �ٸ���,
                rotate[i] = -rotate[i + 1]; //�ݴ���� ȸ��
            }
            else { // �� ������,
                break; //ȸ�� ���޵��� ����
            }
        }

        //������ ��Ϲ���
        for (int i = num + 1; i < t; i++) {
            if (gear[i - 1][2] != gear[i][6]) { //�� �ٸ���,
                rotate[i] = -rotate[i - 1]; //�ݴ���� ȸ��
            }
            else { // �� ������,
                break; // ȸ�� ���޵��� ����
            }
        }

        //ȸ�� ����
        for (int i = 0; i < t; i++) {
            if (rotate[i] == 1) { // �ð���� ȸ��
                char last = gear[i].back(); // �� �� ��� ����
                gear[i].pop_back(); // �� �� ��� ����
                gear[i].push_front(last); // �� �� �߰�
            }
            else if (rotate[i] == -1) { // �ݽð���� ȸ��
                char first = gear[i].front(); // �� �� ��� ����
                gear[i].pop_front(); // �� �� ��� ����
                gear[i].push_back(first); // �� �� �߰�
            }
            // rotate[i] == 0�̸�, ȸ�� ����
        }
    }

    // 12�� ������ S���� ��� ����
    int answer = 0;
    for (int i = 0; i < t; i++) {
        if (gear[i][0] == '1') { // 12�� ���� S���̸�
            answer++; // ī��Ʈ ����
        }
    }

    cout << answer;
    return 0;

}