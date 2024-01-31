#include<bits/stdc++.h>

using namespace std;

bool isFloatVariable(string &s){
    if (!((s[0] >= 'a' && s[0] <= 'h') || (s[0] >= 'A' && s[0] <= 'H') ||
        (s[0] >= 'o' && s[0] <= 'z') || (s[0] >= 'O' && s[0] <= 'Z')))
            return false;
    for (int i = 1; i < s.size(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= '0' && s[i] <= '9'))
                continue;
        return false;
    }
    return true;
}

bool checkS1(string s){
    if (s.size() < 0) return false;
    if (s.size() == 1) return true;
    if (!(s[0]>= '1' && s[0] <= '9')) return false;
    for (int i = 1; i < s.size(); i++) {
        if (s[i]>= '0' && s[i] <= '9')
            continue;
        return false;
    }
    return true;
}

void what_is_s(string &s){
    if (isFloatVariable(s)) {
        cout << "Float variable\n";
        return;
    }
    int cnt = 0;
    string s1, s2;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') {
            cnt++;
            continue;
        }
        if (!(s[i] >= '0' && s[i] <= '9')) {
            cout << "Invalid input\n";
            return;
        }
        if (!cnt) s1.push_back(s[i]);
        else s2.push_back(s[i]);
    }
    if (cnt != 1 || (!checkS1(s1))) {
        cout << "Invalid input\n";
        return;
    }
    bool all_digit = true;
    for (int i = 0; i < s2.size(); i++) {
        all_digit &= (s2[i] >= '0' && s2[i] <= '9');
    }
    if (!all_digit) {
        cout << "Invalid input\n";
        return;
    }
    if (s2.size() == 2) {
        cout << "Float Number\n";
    } else if (s2.size() > 2) {
        cout << "Double Number\n";
    } else {
        cout << "Invalid input\n";
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    string s;
    while (cin >> s) {
        cout << s << " ";
        what_is_s(s);
    }
}
