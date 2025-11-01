#include <iostream>
#include <string>
#include <map>

using namespace std;

// 방향 이동 (행, 열)
map <string, pair<int, int>> direction = {
    {"R", {0, 1}},
    {"L", {0, -1}},
    {"B", {-1, 0}},
    {"T", {1, 0}},
    {"RT", {1, 1}},
    {"LT", {1, -1}},
    {"RB", {-1, 1}},
    {"LB", {-1, -1}}
};


int main(){
    string king, stone;
    int N; //움직이는 횟수
    cin >> king >> stone >> N;

    //킹, 돌의 위치 -> 숫자 변환
    int kingRow = king[1] - '1';
    int kingCol = king[0] - 'A';
    int stoneRow = stone[1] - '1';
    int stoneCol = stone[0] - 'A';

    // N번 이동
    for (int i = 0; i < N; i++) {
        string move;
        cin >> move;

        // 맵에서 이동 방향 가져옴
        int dRow = direction[move].first;   // 행
        int dCol = direction[move].second;  // 열

        // 킹 이동 위치
        int newKingRow = kingRow + dRow;
        int newKingCol = kingCol + dCol;

        // 킹이 체스판 바깥으로 나가는지 확인
        if (newKingRow < 0 || newKingRow > 7 || newKingCol < 0 || newKingCol > 7) {
            continue;
        }

        // 킹이 돌이 있는 곳으로 이동
        if (newKingRow == stoneRow && newKingCol == stoneCol) {
            // 돌을 같은 방향으로 이동
            int newStoneRow = stoneRow + dRow;
            int newStoneCol = stoneCol + dCol;

            // 돌이 체스판 바깥으로 나가는지 확인
            if (newStoneRow < 0 || newStoneRow > 7 || newStoneCol < 0 || newStoneCol > 7) {
                continue;
            }

            //돌 이동
            stoneRow = newStoneRow;
            stoneCol = newStoneCol;
        }

        //킹 이동
        kingRow = newKingRow;
        kingCol = newKingCol;
    }

    //마지막 위치 출력
    cout << (char)('A' + kingCol) << (char)('1' + kingRow) << "\n";
    cout << (char)('A' + stoneCol) << (char)('1' + stoneRow) << "\n";

    return 0;

}