#include <iostream>
#include <string>

using namespace std;

const int ALPHABET = 26;  //알파벳 개수

//비슷한 단어 확인 함수
bool isSimilar(string first, string word) {
    // 각 알파벳 개수 저장 배열
    int firstCnt[ALPHABET] = { 0 }; //첫번째 단어 - 기준 단어
    int wordCnt[ALPHABET] = { 0 }; //비교할 단어

    // 첫번째 단어 알파벳 개수
    for (int i = 0; i < first.length(); i++) {
        firstCnt[first[i] - 'A']++;
    }

    // 비교 단어 알파벳 갯수
    for (int i = 0; i < word.length(); i++) {
        wordCnt[word[i] - 'A']++;
    }

    // 두 단어 알파벳 차이를 계산
    int diff = 0;  // 문자 개수 차이의 합
    for (int i = 0; i < ALPHABET; i++) {
        diff += abs(firstCnt[i] - wordCnt[i]);
    }

    // 비슷한 단어 판단 조건
    // 1. 두 단어 구성 같음: diff == 0
    // 2. 한 글자만 더 많/적음: diff == 1
    // 3. 글자 수 같으나 한 글자만 다름: diff == 2 
    if (diff <= 1) {
        return true;  // 1 or 2
    }
    else if (diff == 2) {
        // 글자 수 같을 때만 교체 가능
        if (first.length() == word.length()) {
            return true;
        }
    }

    return false;
}

int main()
{
    int N;
    cin >> N; //단어 개수

    string first;
    cin >> first;  // 첫번째 단어

    int count = 0;  // 비슷한 단어 개수

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