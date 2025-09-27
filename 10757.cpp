#include <iostream>
#include <stack>
#include <string>

using namespace std;

// stringSum 함수
string stringSum(string a, string b) {
    string result = "";

    int c = 0; //올림수
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || c > 0) {
        int sum = c;

        //a 더하기
        if (i >= 0) {
            sum += (a[i] - '0');  // '5' - '0' = 5
            i--;
        }

        //b 더하기
        if (j >= 0) {
            sum += (b[j] - '0');
            j--;
        }

        //결과
        char digit = sum % 10 + '0';  //일의자리만 문자변환
        result = digit + result;  //앞에 붙여야 함.

        c = sum / 10;  //십의자리는 다음자리로 올림
    }

    return result;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    stack<string> s; //스택 선언

    //두 수 입력 받음
    string A, B;
    cin >> A >> B;

    //스택 삽입
    s.push(A);
    s.push(B);

    string resultB = s.top(); //B
    s.pop();
    string resultA = s.top(); //B+A
    s.pop();

    //결과 계산 및 출력
    string sumresult = stringSum(resultA, resultB);
    cout << sumresult << "\n";

    return 0;

}