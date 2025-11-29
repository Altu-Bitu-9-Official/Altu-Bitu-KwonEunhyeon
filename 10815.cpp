#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//key 값이 배열에 있는지 확인하는 함수
int binarySearch(int n, int key, vector<int>& cards) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (cards[mid] == key) {  //key 값 찾음
            return 1;
        }
        else if (cards[mid] > key) {  //key가 더 작으면, 왼쪽 탐색
            right = mid - 1;
        }
        else {  //key가 더 크면, 오른쪽 탐색
            left = mid + 1;
        }
    }

    return 0;  //key 못 찾음
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    //상근이 가진 카드 개수, 카드
    cin >> n;
    vector<int> cards(n);
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    //정렬
    sort(cards.begin(), cards.end());

    //확인할 숫자 개수
    cin >> m;

    //m개의 숫자에 대해 카드 존재 여부 확인
    for (int i = 0; i < m; i++) {
        int key;
        cin >> key;
        //연산 및 출력: 있으면 1, 없으면 0
        cout << binarySearch(n, key, cards) << ' ';
    }

    return 0;
}