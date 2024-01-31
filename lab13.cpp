#include<bits/stdc++.h>
using namespace std;

map<char, vector<string>>grammar;
char start_symbol = 'E';

void define_grammar(){
    // E' = P, T' = Q
    // E -> TP
    // P -> +TP | e
    // T -> FQ
    // Q -> *FQ | e
    // F -> (E) | i
    grammar['E'] = {"TP"};
    grammar['P'] = {"+TP", ""};
    grammar['T'] = {"FQ"};
    grammar['Q'] = {"*FQ", ""};
    grammar['F'] = {"(E)", "i"};
}

map<char, set<char>>first, follow;

void find_first(char ch){
    if (first.count(ch) != 0) {
        return;
    } 
    for (auto s : grammar[ch]) {
        if (s == "") {
            first[ch].insert('e');
            continue;
        }
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isupper(s[i])) {
                find_first(s[i]);
                for (auto it : first[s[i]]) {
                    if (it != 'e') first[ch].insert(it);
                    else cnt++;
                }
                if (first[s[i]].count('e') == 0) {
                    break;
                }
            } else {
                first[ch].insert(s[i]);
                break;
            }
        }
        if (cnt == s.size()) {
            first[ch].insert('e');
        }
    }
}

void find_follow(char ch){
    if (follow.count(ch) != 0) {
        return;
    }
    if (ch == start_symbol) {
        follow[ch].insert('$');
    }
    for (auto it : grammar) {
        for (auto s : it.second) {
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == ch) {
                    if (i == s.size()-1) {
                        if (it.first != ch) {
                            find_follow(it.first);
                            for (auto i : follow[it.first]) {
                                follow[ch].insert(i);
                            }
                        }
                    } else {
                        if (isupper(s[i+1])) {
                            find_first(s[i+1]);
                            for (auto i : first[s[i+1]]) {
                                if (i != 'e') {
                                    follow[ch].insert(i);
                                }
                            }
                            if (first[s[i+1]].count('e') != 0) {
                                if (it.first != ch) {
                                    find_follow(it.first);
                                    for (auto i : follow[it.first]) {
                                        follow[ch].insert(i);
                                    }
                                }
                            }
                        } else {
                            follow[ch].insert(s[i+1]);
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    define_grammar();
    for (auto it : grammar) {
        find_first(it.first);
    }

    for (auto it : grammar) {
        find_follow(it.first);
    }
    cout << "First: " << endl;
    for (auto it : first) {
        if (it.first == 'P') cout << "E' : ";
        else if (it.first == 'Q') cout << "T' : ";
        else cout << it.first << " : ";
        for (auto i : it.second) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Follow: " << endl;
    for (auto it : follow) {
        if (it.first == 'P') cout << "E' : ";
        else if (it.first == 'Q') cout << "T' : ";
        else cout << it.first << " : ";
        for (auto i : it.second) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}