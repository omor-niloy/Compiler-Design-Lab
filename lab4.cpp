#include<bits/stdc++.h>

using namespace std;

bool isInt(string &s){
    if (!((s[0]>= 'i' && s[0] <= 'n') || (s[0]>= 'I' && s[0] <= 'N')))
        return false;
    for (int i = 1; i < s.size(); i++) {
        if ((s[i]>= 'a' && s[i] <= 'z') || (s[i]>= 'A' && s[i] <= 'Z') || (s[i]>= '0' && s[i] <= '9'))
            continue;
        return false;
    }
    return true;
}

bool contains_digits(string s){
    if (!(s[0]>= '1' && s[0] <= '9')) return false;
    for (int i = 1; i < s.size(); i++) {
        if (s[i]>= '0' && s[i] <= '9')
            continue;
        return false;
    }
    return true;
}

void give_verdict(string &s) {
    if (isInt(s)) {
        cout << "Integer variable\n";
    } else if (contains_digits(s)) {
        if (s.size() < 5) cout << "ShortInt number\n";
        else cout << "LongInt number\n";
    } else {
        cout << "Invalid input\n";
    }
}

int main()
{
    // input:
    // i23948fhcbyrgfb
    // 1349
    // 90038274
    // a83272
    freopen("in.txt", "r", stdin);
    string s;

    while (cin >> s) {
        cout << s << " ";
        give_verdict(s);
    }
    return 0;
}
