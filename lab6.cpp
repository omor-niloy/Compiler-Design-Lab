#include<bits/stdc++.h>

using namespace std;

bool Other_okay(string &s){
    if (!((s[3] >= 'a' && s[3] <= 'z') || (s[3] >= 'A' && s[3] <= 'Z') ||
            (s[3] >= '0' && s[3] <= '9')))
            return false;
    for (int i = 4; i < s.size(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= '0' && s[i] <= '9'))
                continue;
        return false;
    }
    return true;
}

void what_is_s(string &s){
    if (s.size() >= 4) {
        if (s[0] == 'c' && s[1] == 'h' && s[2] == '_') {
            if (Other_okay(s)) {
                cout <<  "Character Variable\n";
                return;
            }
        }
        if (s[0] == 'b' && s[1] == 'n' && s[2] == '_') {
            if (Other_okay(s)) {
                cout <<  "Binary Variable\n";
                return;
            }
        }
    }
    if (s.size() < 2) {
        cout << "Invalid input\n";
        return;
    }
    if (s[0] != '0'){
        cout << "Invalid input\n";
        return;
    }
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '0' || s[i] == '1') continue;
        cout << "Invalid input\n";
        return;
    }
    cout << "Binary Number\n";
}

int main()
{
    // input : 
    // ch_adhcaisydvbc
    // bn_7skdabu
    // 011010010
    // odifhedo
    freopen("in.txt", "r", stdin);
    string s;
    while (cin >> s) {
        cout << s << " ";
        what_is_s(s);
    }
}

