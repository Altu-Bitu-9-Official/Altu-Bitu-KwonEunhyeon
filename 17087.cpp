#include <iostream>
#include <vector>

using namespace std;

// �ִ����� ��� �Լ�
int getGcdRecur(int a, int b) {
    if (b == 0) {
        return a;
    }
    return getGcdRecur(b, a % b);
}

//���� �Լ�
int absInt(int x) {
    return (x < 0) ? -x : x;
}

int main() {
    int N, S;
    cin >> N >> S;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    //ù ������ ������ �Ÿ����� �ʱ�ȭ
    int gcd = absInt(A[0] - S);

    for (int i = 1; i < N; i++) {
        int diff = absInt(A[i] - S);
        gcd = getGcdRecur(gcd, diff);
    }

    cout << gcd << "\n";

    return 0;
}