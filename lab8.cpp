#include<bits/stdc++.h>

using namespace std;

bool isKeyword(string &s){
    ifstream keywords("keywords.txt");
    string key;
    while(getline(keywords, key)){
        if(s == key){
            keywords.close();
            return true;
        }
    }
    keywords.close();
    return false;
}

bool isOperator(string &s){
    ifstream operators("operators.txt");
    string key;
    while(getline(operators, key)){
        if(s == key){
            operators.close();
            return true;
        }
    }
    operators.close();
    return false;
}

bool isIntegerConstant(const string& s) {
    int i = 0;
    if (s[i] == '-' || s[i] == '+') {
        i++;
    }
    bool hasDigits = false;
    while (i < s.size() && isdigit(s[i])) {
        i++;
        hasDigits = true;
    }
    return hasDigits && i == s.size();
}

bool isFloatingPointConstant(const string& s) {
    int i = 0;
    if (s[i] == '-' || s[i] == '+') {
        i++;
    }
    bool hasDigitsBeforeDecimal = false;
    while (i < s.size() && isdigit(s[i])) {
        i++;
        hasDigitsBeforeDecimal = true;
    }
    if (i < s.size() && s[i] == '.') {
        i++;
        bool hasDigitsAfterDecimal = false;
        while (i < s.size() && isdigit(s[i])) {
            i++;
            hasDigitsAfterDecimal = true;
        }
        return (hasDigitsBeforeDecimal || hasDigitsAfterDecimal) && i == s.size();
    }
    return false;
}

bool isCharacterLiteral(const string& s) {
    return s.size() == 3 && s[0] == '\'' && s[2] == '\'';
}


bool isConstant(string &s){
    if (isIntegerConstant(s)) {
        cout << "Integer" << endl;
        return true;
    } else if (isFloatingPointConstant(s)) {
        cout << "Float" << endl;
        return true;
    } else if (isCharacterLiteral(s)) {
        cout << "Character" << endl;
        return true;
    }
    return false;
}

bool isIdentifier(string &s){
    if (!(s[0] == '_' || (s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z')))
        return false;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '_' || (s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z') || (s[i] >='0' && s[i] <= '9'))
            continue;
        return false;
    }
    return true;
}


int main()
{
    freopen("in.txt", "r", stdin);
    string s;
    while (getline(cin, s)) {
        cout << "Input : " << s << endl;
        cout << "Output : ";
        if (isKeyword(s)) {
            cout << "Keyword\n";
        } else if (isOperator(s)) {
            cout << "Operator\n";
        }else if (isConstant(s)) {
            continue;
        } else if (isIdentifier(s)) {
            cout << "Identifier\n";
        } else {
            cout << "other\n";
        }
    }
}
