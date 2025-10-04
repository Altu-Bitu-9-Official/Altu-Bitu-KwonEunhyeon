#include <iostream>
using namespace std;

int N, K;
char wheel[25];  // ����
int S[100];      // ȸ�� ĭ ��
char letter[100]; // ���� ��ġ ����

// ������ ���� �̹� ���Ǿ����� Ȯ�ο��� �Լ�
bool Used(char c) {
    for (int i = 0; i < N; i++) {
        if (wheel[i] == c) {
            return true;
        }
    }
    return false;
}

// ����ȸ�� �� ���ڹ�ġ �Լ�
bool rotateWheel() {
    int pos = 0;  //�� ȭ��ǥ�� ����Ű�� ���� ��ġ

    // K�� ȸ��
    for (int i = 0; i < K; i++) {
        // ������ �ð�������� S[i]ĭ ȸ�� -> ȭ��ǥ�� �ݽð�������� S[i]ĭ �̵�
        pos = (pos - S[i] % N + N) % N;

        // ���� ��ġ ���� Ȯ��
        if (wheel[pos] == '?') {  // � �������� ���� ���� ĭ
            // ���ڰ� �ٸ� ���� ���Ǿ����� Ȯ��
            if (Used(letter[i])) {
                return false;  // ���� ���� �� ���� ������ false
            }
            wheel[pos] = letter[i];  // ���ڹ�ġ
        }
        else { //���� ������ ĭ
            // ���� �������� Ȯ��
            if (wheel[pos] != letter[i]) {
                return false;  // �ٸ� ���ڸ� false
            }
        }
    }

    // ������ ��ġ���� �ð���� ���
    for (int i = 0; i < N; i++) {
        cout << wheel[pos];
        pos = (pos + 1) % N; //�ð����
    }
    cout << '\n';

    return true;
}

int main() {
    //�Է�
    cin >> N >> K;

    // ���� �ʱ�ȭ
    for (int i = 0; i < N; i++) {
        wheel[i] = '?'; //��� ĭ ���� �������� ����
    }

    //ȸ�� ���� �Է�
    for (int i = 0; i < K; i++) {
        cin >> S[i] >> letter[i];
    }

    //���� 
    bool result = rotateWheel();

    //���
    if (!result) {
        cout << "!\n";
    }

    return 0;
}