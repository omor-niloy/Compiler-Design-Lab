#include<bits/stdc++.h> 
using namespace std;

map<char, vector<string>>grammar;

char start_symbol = 'E';

void define_grammar(){
    // E -> EAE | (E) | i
    // A -> + | - | * | /
    grammar['E'] = {"EAE", "(E)", "i"};
    grammar['A'] = {"+", "-", "*", "/"};
}

class ShiftReducingParsing{
    public:
    void can_reduce(stack<char>&st, string substr){
        int N = st.size();
        for (int i = N-1; i > 0; i--) {
            string s;
            for (int j = 0; j < i; j++) {
                s.push_back(st.top());
                st.pop();
            }
            string t = s;
            reverse(t.begin(), t.end());
            for (auto it : grammar) {
                for (auto l : it.second) {
                    if (t == l) {
                        st.push(it.first);
                        can_reduce(st, substr);
                        return;
                    }
                }
            }
            for (int i = s.size()-1; i >= 0; i--) {
                st.push(s[i]);
            }
        }
    }
    bool srParser(string s){
        s.push_back('$');
        stack<char>st;
        st.push('$');
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '$' && st.size() == 2 && st.top() == start_symbol) {
                return true;
            }
            st.push(s[i]);
            can_reduce(st, s.substr(i+1, s.size()));
        }
        return false;
    }
};

bool isPureInt(string s){
    if (!(s[0] >= '1' && s[0] <= '9'))
        return false;
    for (int i = 1; i < s.size(); i++) {
        if (!(s[i] >= '0' && s[i] <= '9'))
            return false;
    }
    return true;
}

bool check_identifier(string s){
    if (isPureInt(s)) return true;
    if (!(s[0] == '_' || (s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z')))
        return false;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '_' || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
            continue;
        return false;
    }
    return true;
}

int main()
{
    define_grammar();
    ShiftReducingParsing srp;

    freopen("in.txt", "r", stdin);
    string s;
    while (cin >> s){
        cout << "Input: ";
        cout << s << endl;
        string t, tmp;
        bool identifier_varifier = true;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '(' || s[i] == ')') {
                if (tmp.size()) {
                    if (check_identifier(tmp)) {
                        t.push_back('i');
                    } else {
                        identifier_varifier = false;
                        break;
                    }
                    tmp.clear();
                }
                t.push_back(s[i]);
            } else {
                tmp.push_back(s[i]); 
            }
        }

        if (tmp.size()) {
            if (check_identifier(tmp)) {
                t.push_back('i');
            } else {
                identifier_varifier = false;
            }
        }

        cout << "Output: ";
        if (!identifier_varifier) {
            cout << "INVALID\n";
            continue;
        }
        if (srp.srParser(t)) {
            cout << "VALID\n";
        } else {
            cout << "INVALID\n";
        }
    }
}