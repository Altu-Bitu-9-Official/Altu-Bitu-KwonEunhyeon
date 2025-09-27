#include <iostream>
#include <stack>
#include <string>

using namespace std;

// stringSum �Լ�
string stringSum(string a, string b) {
    string result = "";

    int c = 0; //�ø���
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || c > 0) {
        int sum = c;

        //a ���ϱ�
        if (i >= 0) {
            sum += (a[i] - '0');  // '5' - '0' = 5
            i--;
        }

        //b ���ϱ�
        if (j >= 0) {
            sum += (b[j] - '0');
            j--;
        }

        //���
        char digit = sum % 10 + '0';  //�����ڸ��� ���ں�ȯ
        result = digit + result;  //�տ� �ٿ��� ��.

        c = sum / 10;  //�����ڸ��� �����ڸ��� �ø�
    }

    return result;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    stack<string> s; //���� ����

    //�� �� �Է� ����
    string A, B;
    cin >> A >> B;

    //���� ����
    s.push(A);
    s.push(B);

    string resultB = s.top(); //B
    s.pop();
    string resultA = s.top(); //B+A
    s.pop();

    //��� ��� �� ���
    string sumresult = stringSum(resultA, resultB);
    cout << sumresult << "\n";

    return 0;

}