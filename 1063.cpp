#include <iostream>
#include <string>
#include <map>

using namespace std;

// ���� �̵� (��, ��)
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
    int N; //�����̴� Ƚ��
    cin >> king >> stone >> N;

    //ŷ, ���� ��ġ -> ���� ��ȯ
    int kingRow = king[1] - '1';
    int kingCol = king[0] - 'A';
    int stoneRow = stone[1] - '1';
    int stoneCol = stone[0] - 'A';

    // N�� �̵�
    for (int i = 0; i < N; i++) {
        string move;
        cin >> move;

        // �ʿ��� �̵� ���� ������
        int dRow = direction[move].first;   // ��
        int dCol = direction[move].second;  // ��

        // ŷ �̵� ��ġ
        int newKingRow = kingRow + dRow;
        int newKingCol = kingCol + dCol;

        // ŷ�� ü���� �ٱ����� �������� Ȯ��
        if (newKingRow < 0 || newKingRow > 7 || newKingCol < 0 || newKingCol > 7) {
            continue;
        }

        // ŷ�� ���� �ִ� ������ �̵�
        if (newKingRow == stoneRow && newKingCol == stoneCol) {
            // ���� ���� �������� �̵�
            int newStoneRow = stoneRow + dRow;
            int newStoneCol = stoneCol + dCol;

            // ���� ü���� �ٱ����� �������� Ȯ��
            if (newStoneRow < 0 || newStoneRow > 7 || newStoneCol < 0 || newStoneCol > 7) {
                continue;
            }

            //�� �̵�
            stoneRow = newStoneRow;
            stoneCol = newStoneCol;
        }

        //ŷ �̵�
        kingRow = newKingRow;
        kingCol = newKingCol;
    }

    //������ ��ġ ���
    cout << (char)('A' + kingCol) << (char)('1' + kingRow) << "\n";
    cout << (char)('A' + stoneCol) << (char)('1' + stoneRow) << "\n";

    return 0;

}