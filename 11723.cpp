#include <iostream>
#include <string>

using namespace std;

const int MAX = 21;  // ��Ʈ���� : 1~20

int main(){
    //���� ����� �ڵ�
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> M;

    int S = 0;  // ��Ʈ����ũ ����

    while (M--){
        string op;
        cin >> op;

        if (op == "add") {
            int x;
            cin >> x;
            S |= (1 << x);  // x��° ��Ʈ 1��(OR����)
        }
        else if (op == "remove") {
            int x;
            cin >> x;
            S &= ~(1 << x);  // x��° ��Ʈ 0����
        }
        else if (op == "check") {
            int x;
            cin >> x;

            //x��° ��Ʈ Ȯ�� (AND����)
            if (S & (1 << x)) {
                cout << "1\n"; //����
            }
            else {
                cout << "0\n"; //����
            }
        }
        else if (op == "toggle"){
            int x;
            cin >> x;

            S ^= (1 << x);  // x��° ��Ʈ ����(XOR����)
        }
        else if (op == "all"){
            S = (1 << MAX) - 1;  //{1, 2, 3, ..., 20} ����
        }
        else if (op == "empty") {
            S = 0;  // ������
        }
    }

    return 0;
}