#include <iostream>
#include <vector>

using namespace std;


// arr: 수열 배열,  n: 수열 길이,  k: 같은 원소 최대 개수
int calcMaxLength(vector<int>& arr, int n, int k) {

    vector<int> count_num(100001, 0); //각 숫자별 현재 구간에 몇 개 있는지 카운트하는 배열

    int max_length = 0; //최장 연속 부분 수열 길이
    int left = 0; //구간 시작 포인터
    int right = 0; //구간 끝 포인터

    while (right < n) {
        count_num[arr[right]]++; //right 위치의 숫자를 구간에 추가


        while (count_num[arr[right]] > k) { //arr[right] 숫자가 k개를 초과하면,
            count_num[arr[left]]--; //left 위치 숫자 제거
            left++; //left 포인터 오른쪽으로 이동
        }

        int current_length = right - left + 1; //현재 구간 [left, right]의 길이 계산

        //답 갱신
        if (current_length > max_length) {
            max_length = current_length;
        }

        right++; //right 포인터 오른쪽으로 이동
    }

    return max_length;
}

int main() {
    int n, k;

    cin >> n >> k;

    vector<int> arr(n, 0); //수열 배열
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //같은 원소가 k개 이하인, 최장 연속 부분 수열의 길이 계산
    int answer = calcMaxLength(arr, n, k);

    cout << answer << '\n';

    return 0;
}