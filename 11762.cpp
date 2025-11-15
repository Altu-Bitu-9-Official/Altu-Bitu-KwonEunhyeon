#include <iostream>
#include <algorithm> 

using namespace std;

int main() {
    int box[6]; //6개 박스 높이 배열
    int tower1, tower2; // 두 개 탑 높이

    //입력받음
    for (int i = 0; i < 6; i++) {
        cin >> box[i];
    }
    cin >> tower1 >> tower2;

    // 6개 박스 중 3개를 선택 -> 첫 번째 탑
    for (int i = 0; i < 6; i++) {  //첫번째 박스
        for (int j = i + 1; j < 6; j++) { //두번째 박스
            for (int k = j + 1; k < 6; k++) { //세번째 박스

                // 선택한 3개 박스 합이 첫 번째 탑의 높이랑 같은지 확인
                if (box[i] + box[j] + box[k] == tower1) {

                    int first[3]; //첫번째 탑 3개 박스 저장 배열
                    first[0] = box[i];
                    first[1] = box[j];
                    first[2] = box[k];


                    int second[3];  // 두번째 탑 3개 박스 저장 배열
                    int idx = 0; //두번째 배열 인덱스

                    for (int m = 0; m < 6; m++) {
                        // i, j, k가 아닌 나머지 박스 -> 두 번째 탑으로 
                        if (m != i && m != j && m != k) {
                            second[idx] = box[m];
                            idx++;
                        }
                    }

                    //내립차순 정렬
                    sort(first, first + 3, greater<int>());
                    sort(second, second + 3, greater<int>());

                    //출력
                    for (int m = 0; m < 3; m++) {
                        cout << first[m] << " ";
                    }
                    for (int m = 0; m < 3; m++) {
                        cout << second[m] << " ";
                    }

                    return 0;

                }
            }
        }
    }

    return 0;

}