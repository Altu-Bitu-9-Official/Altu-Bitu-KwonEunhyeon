#include <iostream>
#include <string>

using namespace std;

const int ALPHABET = 26;  //���ĺ� ����

//����� �ܾ� Ȯ�� �Լ�
bool isSimilar(string first, string word) {
    // �� ���ĺ� ���� ���� �迭
    int firstCnt[ALPHABET] = { 0 }; //ù��° �ܾ� - ���� �ܾ�
    int wordCnt[ALPHABET] = { 0 }; //���� �ܾ�

    // ù��° �ܾ� ���ĺ� ����
    for (int i = 0; i < first.length(); i++) {
        firstCnt[first[i] - 'A']++;
    }

    // �� �ܾ� ���ĺ� ����
    for (int i = 0; i < word.length(); i++) {
        wordCnt[word[i] - 'A']++;
    }

    // �� �ܾ� ���ĺ� ���̸� ���
    int diff = 0;  // ���� ���� ������ ��
    for (int i = 0; i < ALPHABET; i++) {
        diff += abs(firstCnt[i] - wordCnt[i]);
    }

    // ����� �ܾ� �Ǵ� ����
    // 1. �� �ܾ� ���� ����: diff == 0
    // 2. �� ���ڸ� �� ��/����: diff == 1
    // 3. ���� �� ������ �� ���ڸ� �ٸ�: diff == 2 
    if (diff <= 1) {
        return true;  // 1 or 2
    }
    else if (diff == 2) {
        // ���� �� ���� ���� ��ü ����
        if (first.length() == word.length()) {
            return true;
        }
    }

    return false;
}

int main()
{
    int N;
    cin >> N; //�ܾ� ����

    string first;
    cin >> first;  // ù��° �ܾ�

    int count = 0;  // ����� �ܾ� ����

    for (int i = 1; i < N; i++) {
        string word;
        cin >> word;

        if (isSimilar(first, word)) {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}