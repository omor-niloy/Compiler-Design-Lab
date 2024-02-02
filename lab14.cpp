#include<bits/stdc++.h>
using namespace std;

map<char, vector<string>> grammar;

void define_grammar() {
    // E' = P; T' = Q
    // E -> TP
    // P -> +TP | ε
    // T -> FQ
    // Q -> *FQ | ε
    // F -> (E) | id
    grammar['E'] = {"TP"};
    grammar['P'] = {"+TP", ""};
    grammar['T'] = {"FQ"};
    grammar['Q'] = {"*FQ", ""};
    grammar['F'] = {"(E)", "id"};
}

map<char, set<char>> first, follow;
char start_symbol = 'E';

void add_first(){
    first['E'] = {'(', 'i'};
    first['P'] = {'+', 'e'};
    first['T'] = {'(', 'i'};
    first['Q'] = {'*', 'e'};
    first['F'] = {'(', 'i'};
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
                            // find_first(s[i+1]);
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

map<char,int>rowID, colID;

void assignID(){
    rowID['E'] = 0;
    rowID['P'] = 1;
    rowID['T'] = 2;
    rowID['Q'] = 3;
    rowID['F'] = 4;

    colID['i'] = 0;
    colID['+'] = 1;
    colID['*'] = 2;
    colID['('] = 3;
    colID[')'] = 4;
    colID['$'] = 5;
}

string make_in_size(string s){
    while (s.size() < 10) s.push_back(' ');
    return s;
}

int main() {

    define_grammar();
    add_first();

    for (auto it : grammar) {
        find_follow(it.first);
    }
    cout << "Follow : " << endl;
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

    assignID();
    vector<vector<string>>table(5, vector<string>(6, make_in_size("")));

    for (auto it : grammar) {
        for (auto f : first[it.first]) {
            if (f != 'e') {
                string tmp;
                tmp.push_back(it.first);
                tmp += " -> " + it.second[0];
                table[rowID[it.first]][colID[f]] = make_in_size(tmp);
            } else {
                for (auto i : follow[it.first]) {
                    string tmp;
                    tmp.push_back(it.first);
                    tmp += " -> e";
                    table[rowID[it.first]][colID[i]] = make_in_size(tmp);
                }
            }
        }
    }
    cout << "Parsing Table : " << endl;
    string gap = "          ";
    cout << "      ";
    for (int i = 0; i < 6; i++) {
        for (auto it : colID) if (it.second == i) 
            cout << it.first << "         ";
    }
    cout << endl;


    for (int i = 0; i < 5; i++) {
        for (auto it : rowID) if (it.second == i) 
            cout << it.first << "     ";
        for (int j = 0; j < 6; j++) {
            cout << table[i][j];
        }
        cout << endl;
    }
}