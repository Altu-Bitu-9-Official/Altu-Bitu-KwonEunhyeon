#include <iostream>

using namespace std;

int leftChild[1000001];
int rightChild[1000001]; 

//트리에 노드 추가
void insertNode(int parent, int value) {
    if (value < parent) { // 왼쪽으로
        if (leftChild[parent] == 0) {
            leftChild[parent] = value;
        }
        else {
            insertNode(leftChild[parent], value);
        }
    }
    else { //오른쪽으로
        if (rightChild[parent] == 0) {
            rightChild[parent] = value;
        }
        else {
            insertNode(rightChild[parent], value);
        }
    }
}

//후위 순회: L - R - V
void postorder(int v) {
    if (v == 0) {
        return;
    }
    postorder(leftChild[v]);  //왼쪽
    postorder(rightChild[v]); //오른쪽
    cout << v << '\n'; //루트
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int root, value;

    //첫 번째 값이 루트
    cin >> root;

    //나머지 노드들 트리에 추가
    while (cin >> value) {
        insertNode(root, value);
    }

    postorder(root);

    return 0;
}