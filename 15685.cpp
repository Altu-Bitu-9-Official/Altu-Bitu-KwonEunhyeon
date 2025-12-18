#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//방향: 0(오른쪽), 1(위), 2(왼쪽), 3(아래)
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

bool grid[101][101]; //드래곤 커브가 지나간 점 표시

void makeDragonCurve(int x, int y, int d, int g) {
    vector<int> directions; //방향 저장
    directions.push_back(d); //0세대 방향

    //세대별 방향
    for (int gen = 0; gen < g; gen++) {
        int size = directions.size();
        //기존 방향들을 거꾸로 돌면서, 시계방향 90도 회전
        for (int i = size - 1; i >= 0; i--) {
            int next_dir = (directions[i] + 1) % 4; //시계방향 90도 = +1
            directions.push_back(next_dir);
        }
    }

    //시작점
    grid[x][y] = true;

    //방향대로 이동하면서, 점 표시
    for (int i = 0; i < directions.size(); i++) {
        x += dx[directions[i]];
        y += dy[directions[i]];
        grid[x][y] = true;
    }
}

int main() {
    int n, x, y, d, g;

    cin >> n;

    while (n--) {
        cin >> x >> y >> d >> g;
        makeDragonCurve(x, y, d, g);
    }

    //연산 - 1x1 정사각형 개수 세기
    int answer = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {

            // 네 꼭짓점이 모두 드래곤 커브의 일부인지 확인
            if (grid[i][j] && grid[i + 1][j] && grid[i][j + 1] && grid[i + 1][j + 1]) {
                answer++;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}