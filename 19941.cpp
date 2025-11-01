#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int answer = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'P') { // ����̶��,
            // ���� �� �ִ� ���� ���
            int start = max(0, i - k);
            int end = min(n - 1, i + k);

            //���ʺ��� ����� �ܹ��� ã��
            for (int j = start; j <= end; j++) {
                if (s[j] == 'H') { //�ܹ��� �߰��Ѵٸ�,
                    s[j] = 'X'; //�ܹ��� ���� ǥ��
                    answer++; //���� �ܹ��� �� ����
                    break; //���� ���
                }
            }
        }
    }

    cout << answer;
    return 0;

}