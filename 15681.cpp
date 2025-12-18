#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[100001]; //간선 정보
vector<int> child[100001]; //자식 노드들

int subtreeSize[100001]; //서브트리 크기

//트리: 부모 자식 관계 설정
void makeTree(int cur, int par) {
    for (int i = 0; i < tree[cur].size(); i++) {
        int next = tree[cur][i];
        if (next == par) { //부모는 제외
            continue;
        }
        child[cur].push_back(next); //자식 저장
        makeTree(next, cur);
    }
}

// 서브트리 크기 계산
void countSubtree(int cur) {
    subtreeSize[cur] = 1; //자기 자신
    for (int i = 0; i < child[cur].size(); i++) {
        int next = child[cur][i];
        countSubtree(next);
        subtreeSize[cur] += subtreeSize[next]; //자식들 크기 더하기
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, q;
    cin >> n >> r >> q;

    //간선 정보 입력
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    //트리 구성
    makeTree(r, -1); //루트 부모는 -1

    //서브트리 크기 계산
    countSubtree(r);

    for (int i = 0; i < q; i++) {
        int u;
        cin >> u;
        cout << subtreeSize[u] << '\n';
    }

    return 0;
}