#include <iostream>

using namespace std;

const int MAX_E = 15;
const int MAX_S = 28;
const int MAX_M = 19;

// E S M�� �ش��ϴ� ���� ã�� (���Ʈ���� Ȱ��) 
int findYear(int E, int S, int M){
    int year = 1;
    int e = 1, s = 1, m = 1;

    while (true){
        // ��ǥ ������ ã�Ҵ��� Ȯ��
        if (e == E && s == S && m == M) {
            return year;
        }

        // ���� ���� �̵�
        year++;
        e++;
        s++;
        m++;

        // ���� �ʰ� : 1�� �ʱ�ȭ
        if (e > MAX_E) e = 1;
        if (s > MAX_S) s = 1;
        if (m > MAX_M) m = 1;
    }
}

int main(){
    int E, S, M;
    cin >> E >> S >> M;

    int result = findYear(E, S, M);
    cout << result << "\n";

    return 0;
}