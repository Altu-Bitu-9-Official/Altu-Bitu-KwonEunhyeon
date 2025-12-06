#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//items: 물건 배열
//index: 현재 확인할 물건 인덱스,  end: 끝 인덱스
//current_sum: 현재까지 선택한 물건의 무게 합
//sums: 무게 합을 저장할 벡터
void makeSubset(vector<int>& items, int index, int end, long long current_sum, vector<long long>& sums) {
    if (index == end) {  //모든 물건을 확인했으면,
        sums.push_back(current_sum); //현재 합 저장
        return;
    }

    makeSubset(items, index + 1, end, current_sum, sums); //현재 물건 선택하지 않는 경우   
    makeSubset(items, index + 1, end, current_sum + items[index], sums);  //현재 물건 선택하는 경우
}
//sums: 정렬된 무게 합 배열,  target: 찾고자 하는 최대 값
int countUnderTarget(vector<long long>& sums, long long target) {
    int left = 0; //왼쪽 포인터
    int right = sums.size() - 1; //오른쪽 포인터
    int result = -1; //target 이하인 마지막 위치

    while (left <= right) {  //left가 right보다 작거나 같을 때까지
        int mid = (left + right) / 2; //중간 위치

        if (sums[mid] <= target) {  //mid 위치의 값이 target 이하면
            result = mid; //결과 갱신
            left = mid + 1; //더 큰 값 찾기
        }
        else { //mid 위치의 값이 target보다 크면
            right = mid - 1; //더 작은 값 찾기
        }
    }

    if (result == -1) {  //하나도 없으면
        return 0;
    }
    return result + 1; //인덱스 + 1 = 개수
}
//n: 물건 개수,  c: 가방 최대 무게
long long calcKnapsack(vector<int>& items, int n, long long c) {
    int mid = n / 2;  //물건을 두 그룹으로 나누기

    vector<long long> left_sums;  //첫번째 그룹: (0 ~ mid-1)의 모든 부분집합 무게 합
    makeSubset(items, 0, mid, 0, left_sums);

    vector<long long> right_sums;  //두번째 그룹: (mid ~ n-1)의 모든 부분집합 무게 합
    makeSubset(items, mid, n, 0, right_sums);
    sort(right_sums.begin(), right_sums.end());  //오른쪽 그룹 오름차순 정렬
    long long count = 0; //가방에 넣는 방법의 수

    for (int i = 0; i < left_sums.size(); i++) { //왼쪽 그룹 각 무게 합에 대해서,
        long long left_sum = left_sums[i];

        //가방에 넣을 수 있는 남은 무게
        long long remain = c - left_sum;

        if (remain < 0) { //남은 무게가 음수면 불가능
            continue;
        }
        //오른쪽 그룹에서 remain 이하인 무게 합의 개수 찾기
        count += countUnderTarget(right_sums, remain);
    }
    return count;
}
int main() {
    int n;
    long long c;

    cin >> n >> c;

    vector<int> items(n, 0); //물건 무게 배열
    for (int i = 0; i < n; i++) {
        cin >> items[i];
    }

    //가방에 넣는 방법의 수 계산
    long long answer = calcKnapsack(items, n, c);

    cout << answer << '\n';

    return 0;
}