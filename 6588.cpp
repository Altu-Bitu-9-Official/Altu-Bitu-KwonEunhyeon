#include <iostream>

using namespace std;

bool is_prime[1000001]; // �Ҽ� ���� ����

// �����佺�׳׽��� ü�� �Ҽ� ���ϱ�
void makePrime() {
    // �ʱ�ȭ (2 �̻� ��� �Ҽ��� ����)
    for (int i = 2; i <= 1000000; i++) {
        is_prime[i] = true;
    }

    for (int i = 2; i * i <= 1000000; i++) {
        if (is_prime[i]) {
            // i�� ����� ����
            for (int j = i * i; j <= 1000000; j += i) {
                is_prime[j] = false;
            }
        }

    }
}

int main() {

    //����� ����ȭ
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    // �Ҽ� �̸� ���
    makePrime();

    int n;

    while (cin >> n && n != 0) {

        //n�� �� Ȧ�� �Ҽ��� ������
        bool found = false; //�� �Ҽ��� ���� ã�Ҵ��� (�ʱⰪ: �� ã��)

        //a�� ���� ������ ���� (b-a�� �ִ��̵���)
        for (int a = 3; a <= n / 2; a += 2) {
            int b = n - a;

            // a, b�� �Ҽ����� Ȯ��
            if (is_prime[a] && is_prime[b]) {
                // ���
                cout << n << " = " << a << " + " << b << '\n';
                found = true;
                break;
            }
        }

        // �� ã�� ���
        if (!found) {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }

    return 0;
}