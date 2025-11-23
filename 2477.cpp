#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 1m²당 참외 개수
    int k;
    cin >> k;

    // 6개 변의 방향, 길이
    vector<int> dir(6);  // 방향 (1:동, 2:서, 3:남, 4:북)
    vector<int> len(6);  // 길이

    for (int i = 0; i < 6; i++) {
        cin >> dir[i] >> len[i];
    }

    int max_width = 0;       //최대 가로 길이
    int max_height = 0;      //최대 세로 길이
    int max_width_idx = -1;  //최대 가로의 인덱스
    int max_height_idx = -1; //최대 세로의 인덱스

    //최대값 찾기
    for (int i = 0; i < 6; i++) {
        if (dir[i] == 1 || dir[i] == 2) {  // 동쪽(1) 또는 서쪽(2) = 가로
            if (len[i] > max_width) {
                max_width = len[i];      //최대 가로 길이 업데이트
                max_width_idx = i;
            }
        }
        else {  // 남쪽(3) 또는 북쪽(4) = 세로
            if (len[i] > max_height) {
                max_height = len[i];     // 최대 세로 길이 업데이트
                max_height_idx = i;
            }
        }
    }

    // 작은 사각형의 두 변
    // 육각형에서 한 변의 맞은편 = 3칸 떨어진 곳
    // 최대 세로의 맞은편 = 작은 사각형의 가로
    int small_width = len[(max_height_idx + 3) % 6];

    // 최대 가로의 맞은편 = 작은 사각형의 세로
    int small_height = len[(max_width_idx + 3) % 6];

    //참외밭 넓이 계산
    int area = (max_width * max_height) - (small_width * small_height);

    //전체 참외 개수 = 참외밭 넓이 × 1m²당 참외 개수
    cout << area * k << '\n';

    return 0;
}