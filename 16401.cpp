#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//나눠줄 수 있는 조카 수를 계산하는 함수
int cntSnack(int len, vector<int>& snacks) {
    int cnt = 0;  //나눠줄 수 있는 조카 수

    for (int i = 0; i < snacks.size(); i++) {
        cnt += snacks[i] / len;  //각 과자를 len 길이로 나눈 개수
    }

    return cnt;
}

//최대 과자 길이 찾기
int binarySearch(int left, int right, int m, vector<int>& snacks) {
    int result = 0;  //최대 길이 저장

    while (left <= right) {
        int mid = (left + right) / 2;  //중간값 = 과자 길이

        int cnt = cntSnack(mid, snacks);  //mid 길이로 나눠줄 수 있는 조카 수

        if (cnt >= m) {  //mid 길이로 m명 이상 나눠줄 수 있다면, 길이 늘리기
            result = mid;
            left = mid + 1;
        }
        else {  //mid 길이로는 m명에게 못 나눠주면, 길이 줄이기
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;

    //조카 수 m, 과자 수 n
    cin >> m >> n;

    vector<int> snacks(n);
    int max_len = 0;  //과자 중 최대 길이

    for (int i = 0; i < n; i++) {
        cin >> snacks[i];
        if (snacks[i] > max_len) {  //최대 길이 갱신
            max_len = snacks[i];
        }
    }


    //최소 길이: 1
    //최대 길이: 가장 긴 과자의 길이
    cout << binarySearch(1, max_len, m, snacks);

    return 0;
}