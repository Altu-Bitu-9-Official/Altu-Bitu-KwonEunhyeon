#include <iostream>
#include <deque>
#include <string>

using namespace std;

//���ڱ������ üũ �Լ�
bool checkChar(char c) {
    // ���� ���ĺ�, ����, ��/���ȣ
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == ' ') || (c == '(' || c == ')' || c == '[' || c == ']'))
        return true;

    return false;
}

// ���ڿ� ���� 3���� üũ�Լ�
bool checkString(string str) {
    // ����3: ���� <= 100
    if (str.length() > 100)
        return false;

    // ����2: �������� ��ħ
    if (str.back() != '.')
        return false;

    // ����1:����, ����, ��ȣ������ ��������
    for (int i = 0; i < str.length() - 1; i++) {
        if (!checkChar(str[i]))
            return false;
    }

    return true;
}

// ��ȣ ���� üũ �Լ�
bool checkBalance(string str) {

    deque<char> dq; // �� ����

    // ��ȣ�� �� ���� 
    for (int i = 0; i < str.length() - 1; i++) { // ���� ����

        // ���� ���ĺ�, ������ ��� �ǳʶ�
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] == ' ')) {
            continue;
        }

        // ��ȣ�� ó��
        else {
            // ���� ��ȣ : �� ����
            if (str[i] == '(' || str[i] == '[') {
                dq.push_back(str[i]);
            }

            // �ݴ� ��ȣ : ��Ī üũ
            else {
                // �� ��������� ��Ī ����
                if (dq.empty()) {
                    return false;
                }

                // ��ȣ ��Ī üũ
                if ((str[i] == ')' && dq.back() != '(') || (str[i] == ']' && dq.back() != '['))
                    return false; // ��Ī ����

                dq.pop_back();
            }
        }
    }

    // ��� ��ȣ ��Ī ������ ���, �� ����־�� ��
    if (dq.empty()) {
        return true;
    }
    else {
        return false;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string x;

    // ���ڿ� �Է� �� �˻� 
    while (true) {
        getline(cin, x); // ���پ� ó��

        // ���� �ԷµǸ� ����
        if (x == ".") {
            break;
        }

        // ���ڿ� ���� üũ
        if (!checkString(x)) {
            cout << "�߸��� �Է��Դϴ�. ���Է¹ٶ��ϴ�.\n";
            continue;
        }

        // ��ȣ ���� üũ
        if (checkBalance(x)) {
            cout << "yes" << "\n";
        }
        else {
            cout << "no" << "\n";
        }
    }

    return 0;
}