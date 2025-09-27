#include <iostream>
#include <deque>
#include <string>

using namespace std;

//문자구성요소 체크 함수
bool checkChar(char c) {
    // 영문 알파벳, 공백, 소/대괄호
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == ' ') || (c == '(' || c == ')' || c == '[' || c == ']'))
        return true;

    return false;
}

// 문자열 조건 3가지 체크함수
bool checkString(string str) {
    // 조건3: 길이 <= 100
    if (str.length() > 100)
        return false;

    // 조건2: 온점으로 마침
    if (str.back() != '.')
        return false;

    // 조건1:영문, 공백, 괄호만으로 구성여부
    for (int i = 0; i < str.length() - 1; i++) {
        if (!checkChar(str[i]))
            return false;
    }

    return true;
}

// 괄호 균형 체크 함수
bool checkBalance(string str) {

    deque<char> dq; // 덱 선언

    // 괄호만 덱 삽입 
    for (int i = 0; i < str.length() - 1; i++) { // 온점 제외

        // 영문 알파벳, 공백의 경우 건너뜀
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] == ' ')) {
            continue;
        }

        // 괄호면 처리
        else {
            // 여는 괄호 : 덱 삽입
            if (str[i] == '(' || str[i] == '[') {
                dq.push_back(str[i]);
            }

            // 닫는 괄호 : 매칭 체크
            else {
                // 덱 비어있으면 매칭 실패
                if (dq.empty()) {
                    return false;
                }

                // 괄호 매칭 체크
                if ((str[i] == ')' && dq.back() != '(') || (str[i] == ']' && dq.back() != '['))
                    return false; // 매칭 실패

                dq.pop_back();
            }
        }
    }

    // 모든 괄호 매칭 성공인 경우, 덱 비어있어야 함
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

    // 문자열 입력 및 검사 
    while (true) {
        getline(cin, x); // 한줄씩 처리

        // 온점 입력되면 종료
        if (x == ".") {
            break;
        }

        // 문자열 조건 체크
        if (!checkString(x)) {
            cout << "잘못된 입력입니다. 재입력바랍니다.\n";
            continue;
        }

        // 괄호 균형 체크
        if (checkBalance(x)) {
            cout << "yes" << "\n";
        }
        else {
            cout << "no" << "\n";
        }
    }

    return 0;
}