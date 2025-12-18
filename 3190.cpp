#include <iostream>

using namespace std;

int n, k, l;
int board[101][101]; // 0: 빈칸, 1: 사과, 2: 뱀

int snakeR[10001], snakeC[10001]; //뱀 각 부분 위치
int head, tail;

int turnTime[101]; //방향 전환 시간
char turnDir[101]; //방향 전환 방향
int turnIdx; //현재 확인할 방향 전환한 인덱스

//방향: 우(0), 하(1), 좌(2), 상(3)
int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };

int rotate(int dir, char c) {
    if (c == 'L') { //왼쪽 회전
        return (dir + 3) % 4;
    }
    else { //오른쪽 회전
        return (dir + 1) % 4;
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        board[r][c] = 1; // 사과
    }

    cin >> l;
    for (int i = 0; i < l; i++) {
        int x;
        char c;
        cin >> x >> c;
        turnTime[i] = x;
        turnDir[i] = c;
    }

    //초기화
    head = 0;
    tail = 0;
    snakeR[0] = 1;
    snakeC[0] = 1;
    board[1][1] = 2; //뱀 위치 표시

    int dir = 0; // 처음엔 오른쪽
    int time = 0;
    turnIdx = 0;

    while (true) {
        time++;

        //머리를 다음 칸에 위치시킴
        int newR = snakeR[head] + dr[dir];
        int newC = snakeC[head] + dc[dir];

        //벽 충돌 체크
        if (newR < 1 || newR > n || newC < 1 || newC > n) {
            break;
        }

        //자기 몸 충돌 체크
        if (board[newR][newC] == 2) {
            break;
        }

        //머리 추가
        head++;
        snakeR[head] = newR;
        snakeC[head] = newC;

        //사과 확인
        if (board[newR][newC] == 1) { //사과가 있으면 
            //사과만 제거, 꼬리는 그대로
            board[newR][newC] = 2; //뱀으로 변경
        }
        else {  //사과가 없으면 꼬리 제거
            board[newR][newC] = 2; //뱀으로 변경
            board[snakeR[tail]][snakeC[tail]] = 0; //꼬리 칸 비우기
            tail++;
        }

        //방향 전환
        if (turnIdx < l && time == turnTime[turnIdx]) {
            dir = rotate(dir, turnDir[turnIdx]);
            turnIdx++;
        }
    }

    cout << time << '\n';

    return 0;
}