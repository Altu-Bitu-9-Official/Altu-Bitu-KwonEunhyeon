#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n; // 수열
    int a[1001]; //입력받을 수열
    int dp[1001]; //dp[i] = i번째 숫자를 마지막으로 포함하는 가장 긴 증가수열 길이
    int max_len = 0; //가장 긴 길이 저장할 변수

    // 입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    //최장 증가 수열 길이 계산
    for (int i = 0; i < n; i++) {
        int len = 0; // i번째 숫자 앞에서 찾은 최대 길이

        // i번째 숫자보다 앞에 있는 숫자 확인
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) { //j번째 숫자< i번째 숫자보다 작다면
                len = max(dp[j], len);  //j번째 위치까지 LIS 길이들 중 최댓값
            }
        }

        //i번째 숫자를 마지막으로 하는 증가수열 길이
        dp[i] = len + 1;

        // 전체 중에서 가장 긴 길이 갱신
        if (max_len < dp[i]) {
            max_len = dp[i];
        }
    }

    cout << max_len << "\n";

    return 0;

}