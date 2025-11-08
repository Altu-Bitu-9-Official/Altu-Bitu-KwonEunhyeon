#include <iostream>
#include <deque>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    //덱 초기화
    deque<int> dodo_deck, suyeon_deck;

    for (int i = 0; i < N; i++) {
        int d, s;
        cin >> d >> s;
        dodo_deck.push_back(d);
        suyeon_deck.push_back(s);
    }

    //그라운드 초기화
    deque<int> dodo_ground, suyeon_ground;

    int turn = 0; // 0: 도도, 1: 수연

    for (int i = 0; i < M; i++) {
        // 턴 시작할 때 현재 플레이어의 덱이 비어있다면, 게임 종료
        if (turn == 0 && dodo_deck.empty()) {
            cout << "su" << endl;
            return 0;
        }
        if (turn == 1 && suyeon_deck.empty()) {
            cout << "do" << endl;
            return 0;
        }

        // 2번: 현재 턴의 플레이어가 덱의 맨 위 카드 냄
        if (turn == 0) { //도도 차례
            int card = dodo_deck.back();
            dodo_deck.pop_back();
            dodo_ground.push_back(card);

            //카드 낸 직후 덱이 비었는지 확인
            if (dodo_deck.empty()) {
                cout << "su" << endl;
                return 0;
            }
        }
        else { //수연 차례
            int card = suyeon_deck.back();
            suyeon_deck.pop_back();
            suyeon_ground.push_back(card);

            //카드 낸 직후 덱이 비었는지 확인
            if (suyeon_deck.empty()) {
                cout << "do" << endl;
                return 0;
            }
        }

        //3번: 종을 치는 조건
        int bell_ringer = -1;

        //도도가 종을 치는 조건: 어느 한쪽 최상단 카드가 5
        if (!dodo_ground.empty() && dodo_ground.back() == 5) {
            bell_ringer = 0;
        }
        else if (!suyeon_ground.empty() && suyeon_ground.back() == 5) {
            bell_ringer = 0;
        }

        //수연이 종을 치는 조건: 둘 다 비어있지 않음 && 양쪽 최상단 합이 5
        if (bell_ringer == -1) {
            if (!dodo_ground.empty() && !suyeon_ground.empty()) {
                if (dodo_ground.back() + suyeon_ground.back() == 5) {
                    bell_ringer = 1;
                }
            }
        }

        //4번: 종을 쳤으면 카드 가져감
        if (bell_ringer != -1) {
            if (bell_ringer == 0) { //도도가 종을 침
                //1. 수연 그라운드를 뒤집어서 도도 덱 아래로
                for (int j = 0; j < (int)suyeon_ground.size(); j++) {
                    dodo_deck.push_front(suyeon_ground[j]);  //그라운드를 아래부터 순서대로 덱 맨 아래에 추가
                }
                suyeon_ground.clear();

                // 2. 도도 그라운드를 뒤집어서 도도 덱 아래로
                for (int j = 0; j < (int)dodo_ground.size(); j++) {
                    dodo_deck.push_front(dodo_ground[j]);
                }
                dodo_ground.clear();

                //카드를 가져간 후 상대방 덱 확인
                if (suyeon_deck.empty()) {
                    cout << "do" << endl;
                    return 0;
                }
            }
            else { //수연이가 종을 침
                // 1. 도도 그라운드를 뒤집어서 수연 덱 아래로
                for (int j = 0; j < (int)dodo_ground.size(); j++) {
                    suyeon_deck.push_front(dodo_ground[j]);
                }
                dodo_ground.clear();

                //2. 수연 그라운드를 뒤집어서 수연 덱 아래로
                for (int j = 0; j < (int)suyeon_ground.size(); j++) {
                    suyeon_deck.push_front(suyeon_ground[j]);
                }
                suyeon_ground.clear();

                //카드를 가져간 후 상대방 덱 확인
                if (dodo_deck.empty()) {
                    cout << "su" << endl;
                    return 0;
                }
            }
        }

        // 다음 턴
        turn = 1 - turn;
    }

    //승패 결정
    int dodo_count = dodo_deck.size();
    int suyeon_count = suyeon_deck.size();

    if (dodo_count > suyeon_count) {
        cout << "do" << endl;
    }
    else if (suyeon_count > dodo_count) {
        cout << "su" << endl;
    }
    else {
        cout << "dosu" << endl;
    }

    return 0;

}