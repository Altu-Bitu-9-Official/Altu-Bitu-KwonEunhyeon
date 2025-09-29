#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    string s;
    cin >> s;

    set<string> result;

    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            string temp = "";
            for (int k = i; k <= j; k++) {
                temp += s[k];
            }
            result.insert(temp);
        }
    }

    cout << result.size() << "\n";

    return 0;
}