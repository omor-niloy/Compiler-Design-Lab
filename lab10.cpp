#include<bits/stdc++.h>

using namespace std;

// Assume every terminal & non-terminal is a single character
map<char, vector<string>>grammar;
string gap = "     ";

void define_grammar(){
    // S -> (L) | a
    // L -> L.S | S
    // grammar['L'] = {"L.S", "S"};
    // grammar['S'] = {"(L)", "a"};

    // E -> E+E 
    // E -> E*E 
    // E -> (E)  
    // E -> i
    grammar['E'] = {"E+E", "E*E", "(E)", "i"};
}

void print_stack(stack<char>st){
    stack<char>temp;
    while (!st.empty()) {
        temp.push(st.top());
        st.pop();
    }
    while (!temp.empty()) {
        cout << temp.top();
        temp.pop();
    }
    // cout << endl;
}

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
                    print_stack(st);
                    cout << "     " << substr << "    ";
                    cout << it.first << " -> " << l << endl;
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

int main()
{
    freopen("in.txt", "r", stdin);
    
    define_grammar();

    string s;
    while (cin >> s) {
        s.push_back('$');
        stack<char>st;
        st.push('$');

        cout << "Stack" << gap << "Input" << gap << "Action\n";

        print_stack(st);
        cout << "     " << s << "    " << endl;
        
        bool AC = false;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '$' && st.size() == 2) {
                cout << "Accepted" << endl;
                AC = true;
                break;
            }
            
            st.push(s[i]);
            print_stack(st);
            cout << "     " << s.substr(i+1, s.size()) << "    shift" << endl;

            can_reduce(st, s.substr(i+1, s.size()));
        }
        if (!AC) {
            cout << "Invalid\n";
        }
    }
}
