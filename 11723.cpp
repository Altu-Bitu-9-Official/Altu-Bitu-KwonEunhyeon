#include <iostream>
#include <string>

using namespace std;

const int MAX = 21;  // 비트범위 : 1~20

int main(){
    //빠른 입출력 코드
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> M;

    int S = 0;  // 비트마스크 집합

    while (M--){
        string op;
        cin >> op;

        if (op == "add") {
            int x;
            cin >> x;
            S |= (1 << x);  // x번째 비트 1로(OR연산)
        }
        else if (op == "remove") {
            int x;
            cin >> x;
            S &= ~(1 << x);  // x번째 비트 0으로
        }
        else if (op == "check") {
            int x;
            cin >> x;

            //x번째 비트 확인 (AND연산)
            if (S & (1 << x)) {
                cout << "1\n"; //있음
            }
            else {
                cout << "0\n"; //없음
            }
        }
        else if (op == "toggle"){
            int x;
            cin >> x;

            S ^= (1 << x);  // x번째 비트 반전(XOR연산)
        }
        else if (op == "all"){
            S = (1 << MAX) - 1;  //{1, 2, 3, ..., 20} 집합
        }
        else if (op == "empty") {
            S = 0;  // 공집합
        }
    }

    return 0;
}