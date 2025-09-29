#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    // 길이 다르면 짧은거 먼저
    if (a.size() != b.size()) {
        return a.size() < b.size();
    }

    // 길이 같으면 숫자만 더해서 비교
    int suma = 0;
    int sumb = 0;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] >= '0' && a[i] <= '9') {
            suma += a[i] - '0';
        }
    }

    for (int i = 0; i < b.size(); i++) {
        if (b[i] >= '0' && b[i] <= '9') {
            sumb += b[i] - '0';
        }
    }

    if (suma != sumb) {
        return suma < sumb;
    }

    // 같으면 사전순
    return a < b;
}

int main() {
    int n;
    cin >> n;

    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << v[i] << "\n";
    }

    return 0;
}