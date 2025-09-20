#include <iostream>

using namespace std;

int main() {
    int w, i, t;  //다이어트 전 체중, 일일 에너지 섭취량, 역치
    int d, di, a;  //다이어트 기간, 다이어트 중 일일 에너지 섭취량, 일일 활동 대사

    cin >> w >> i >> t;
    cin >> d >> di >> a;

    // 일일 기초대사량 변화 고려하지 않음
    int weight1 = w;
    bool dead1 = false;
    for (int day = 1; day <= d; day++) {
        int change = di - (i + a);  //일일 에너지 섭취량 - 일일 에너지 소비량
        weight1 = weight1 + change;
        if (weight1 <= 0) {
            dead1 = true;
            break;
        }
    }

    //첫번째줄 출력
    if (dead1 == true) {
        cout << "Danger Diet\n";
    }
    else {
        cout << weight1 << " " << i << "\n";
    }

    //일일 기초대사량 변화 고려함
    int weight2 = w;
    int bmr = i;
    bool dead2 = false;

    for (int day = 1; day <= d; day++) {
        int change = di - (bmr + a);
        weight2 = weight2 + change;

        if (weight2 <= 0) {
            dead2 = true;
            break;
        }

        // 기초대사량 변화
        int abs_change = change;
        if (abs_change < 0) {
            abs_change = -abs_change;
        }

        if (abs_change > t) {
            // 음수 나눗셈 처리 
            if (change >= 0) {
                bmr = bmr + change / 2;
            }
            else {
                if (change % 2 == 0) {
                    bmr = bmr + change / 2;
                }
                else {
                    bmr = bmr + change / 2 - 1; // -5/2 = -2인데 -3이어야함
                }
            }

            if (bmr <= 0) {
                dead2 = true;
                break;
            }
        }
    }

    //두번째줄 출력
    if (dead2 == true) {
        cout << "Danger Diet\n";
    }
    else {
        cout << weight2 << " " << bmr << " ";

        // 요요 판단
        int check = i - bmr;
        if (check > 0) {
            cout << "YOYO\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;

}