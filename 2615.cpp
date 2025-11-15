#include <iostream>

using namespace std;

int board[20][20]; //바둑판
// 방향: 가로, 세로, 대각선 오른쪽 아래, 대각선 오른쪽 위
int dx[] = { 0, 1, 1, -1 };
int dy[] = { 1, 0, 1, 1 };

int main() {
    for (int i = 1; i <= 19; i++) {
        for (int j = 1; j <= 19; j++) {
            cin >> board[i][j]; //바둑판 입력받음
        }
    }

    for (int i = 1; i <= 19; i++) {
        for (int j = 1; j <= 19; j++) {
            //돌이 없으면 넘어감
            if (board[i][j] == 0) continue;

            int color = board[i][j]; //현재 돌 색깔

            //4가지 방향 체크
            for (int dir = 0; dir < 4; dir++) {
                int cnt = 1; //현재 돌 포함 개수

                //현재 위치에서 해당 방향으로 계속 가면서 세기
                for (int k = 1; k < 6; k++) {
                    int nx = i + dx[dir] * k;
                    int ny = j + dy[dir] * k;

                    //범위를 벗어나면 종료
                    if (nx < 1 || nx > 19 || ny < 1 || ny > 19) {
                        break;
                    }

                    //같은 색이면 카운트 +1
                    if (board[nx][ny] == color) {
                        cnt++;
                    }
                    else {
                        break; //다른 색이면 중단
                    }
                }


                if (cnt == 5) {  //정확히 5개인지 확인
                    //6개째 돌 있는지 확인
                    int next_x = i + dx[dir] * 5;
                    int next_y = j + dy[dir] * 5;
                    if (next_x >= 1 && next_x <= 19 && next_y >= 1 && next_y <= 19) {
                        if (board[next_x][next_y] == color) {
                            continue; // 6개 이상이면 넘어감
                        }
                    }

                    //반대 방향에 같은 색이 있는지 확인
                    int prev_x = i - dx[dir];
                    int prev_y = j - dy[dir];
                    if (prev_x >= 1 && prev_x <= 19 && prev_y >= 1 && prev_y <= 19) {
                        if (board[prev_x][prev_y] == color) {
                            continue;  //6개 이상이면 넘어감
                        }
                    }

                    cout << color << '\n';
                    cout << i << ' ' << j << '\n';
                    return 0;
                }
            }
        }
    }

    //아직 승부가 결정되지 않았다면
    cout << 0 << '\n';
    return 0;
}