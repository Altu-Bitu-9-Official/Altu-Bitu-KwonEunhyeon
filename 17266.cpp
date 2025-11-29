#include <iostream>
#include <vector>

using namespace std;

// 높이 h로 굴다리를 다 비출 수 있는지 체크 함수
bool check(int n, int h, vector<int>& x, int m) {
    if (x[0] - h > 0) {  // 맨 처음 0을 비출 수 있는지
        return false;
    }

    // 가로등 사이사이 체크
    for (int i = 1; i < m; i++) {
        int prev_end = x[i - 1] + h;  // 앞 가로등이 비추는 끝
        int curr_start = x[i] - h;     //현재 가로등이 비추는 시작지점

        if (prev_end < curr_start) {  //사이에 어두운 구간 있음
            return false;
        }
    }


    if (x[m - 1] + h < n) {  //마지막 n까지 비출 수 있는지
        return false;
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> x(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i];
    }

    int left = 1;
    int right = n;
    int ans = n;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (check(n, mid, x, m)) {
            //mid 높이로 가능 -> 더 낮은 높이
            ans = mid;
            right = mid - 1;
        }
        else {
            //mid 높이로 불가능 -> 높이 올리기
            left = mid + 1;
        }
    }

    cout << ans;

    return 0;
}