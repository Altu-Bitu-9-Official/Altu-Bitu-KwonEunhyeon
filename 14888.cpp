#include <iostream>
#include <vector>

using namespace std;

int n;  // 수 개수
vector<int> numbers;  //숫자 배열
vector<int> operators;  //연산자 개수 [+, -, *, /]
int max_result = -1000000000; //최댓값 초기화
int min_result = 1000000000;  //최솟값 초기화

// idx: 현재 계산할 숫자의 인덱스
// current_result: 현재까지 계산된 결과값
void backtracking(int idx, int current_result) {
    if (idx == n) {   // 모든 숫자를 다 사용한 경우
        // 최댓값 업데이트
        if (current_result > max_result) {
            max_result = current_result;
        }
        // 최솟값 업데이트
        if (current_result < min_result) {
            min_result = current_result;
        }
        return;
    }

    //4가지 연산자를 각각 시도
    for (int i = 0; i < 4; i++) {
        //해당 연산자가 남아있지 않으면 건너뜀
        if (operators[i] == 0) {
            continue;
        }

        //연산자 사용
        operators[i]--;

        //다음 계산 결과 저장할 변수
        int next_result = 0;

        //i=0: 덧셈
        if (i == 0) {
            next_result = current_result + numbers[idx];
        }
        //i=1: 뺄셈
        else if (i == 1) {
            next_result = current_result - numbers[idx];
        }
        //i=2: 곱셈
        else if (i == 2) {
            next_result = current_result * numbers[idx];
        }
        //i=3: 나눗셈
        else if (i == 3) {
            // 음수 나눗셈 처리
            if (current_result < 0) {
                //음수를 양수로 바꿔서 나눈 후 다시 음수로
                next_result = -((-current_result) / numbers[idx]);
            }
            else {
                next_result = current_result / numbers[idx];
            }
        }

        //다음 숫자로 재귀 호출
        backtracking(idx + 1, next_result);

        //백트래킹 - 연산자 반납
        operators[i]++;
    }
}

int main() {
    cin >> n;

    numbers.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    operators.resize(4);
    for (int i = 0; i < 4; i++) {
        cin >> operators[i];
    }

    //백트래킹 시작
    backtracking(1, numbers[0]);

    cout << max_result << '\n';  // 최댓값
    cout << min_result << '\n';  // 최솟값

    return 0;
}