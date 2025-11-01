#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> v(n); // �� �༺ �̵� �� �ʿ��� �ּ� �ӵ�

    //�ӵ� �Է�
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    long long speed = v[n - 1]; //���� ���Ϳ� �ʿ��� �ӵ��� ����

    //�ڿ������� �������� ���
    for (int i = n - 2; i >= 0; i--) {
        if (speed < v[i]) { //�� �ӵ��� �䱸 �ӵ����� �۴ٸ�,
            speed = v[i]; //�䱸�ӵ���
        }
        else { //�� �ӵ��� �䱸 �ӵ����� ũ�ų� ���ٸ�,
            // v[i]�� ����� �����
            if (speed % v[i] != 0) { // �������� 0�� �ƴϸ�, ���� ����� �ø�
                speed = (speed / v[i] + 1) * v[i];
            }
            // speed % v[i] == 0 �̸� �̹� �����.
        }
    }

    cout << speed;
    return 0;

}