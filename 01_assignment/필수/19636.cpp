#include <iostream>

using namespace std;

int main() {
    int w, i, t;  //���̾�Ʈ �� ü��, ���� ������ ���뷮, ��ġ
    int d, di, a;  //���̾�Ʈ �Ⱓ, ���̾�Ʈ �� ���� ������ ���뷮, ���� Ȱ�� ���

    cin >> w >> i >> t;
    cin >> d >> di >> a;

    // ���� ���ʴ�緮 ��ȭ ������� ����
    int weight1 = w;
    bool dead1 = false;
    for (int day = 1; day <= d; day++) {
        int change = di - (i + a);  //���� ������ ���뷮 - ���� ������ �Һ�
        weight1 = weight1 + change;
        if (weight1 <= 0) {
            dead1 = true;
            break;
        }
    }

    //ù��°�� ���
    if (dead1 == true) {
        cout << "Danger Diet\n";
    }
    else {
        cout << weight1 << " " << i << "\n";
    }

    //���� ���ʴ�緮 ��ȭ �����
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

        // ���ʴ�緮 ��ȭ
        int abs_change = change;
        if (abs_change < 0) {
            abs_change = -abs_change;
        }

        if (abs_change > t) {
            // ���� ������ ó�� 
            if (change >= 0) {
                bmr = bmr + change / 2;
            }
            else {
                if (change % 2 == 0) {
                    bmr = bmr + change / 2;
                }
                else {
                    bmr = bmr + change / 2 - 1; // -5/2 = -2�ε� -3�̾����
                }
            }

            if (bmr <= 0) {
                dead2 = true;
                break;
            }
        }
    }

    //�ι�°�� ���
    if (dead2 == true) {
        cout << "Danger Diet\n";
    }
    else {
        cout << weight2 << " " << bmr << " ";

        // ��� �Ǵ�
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