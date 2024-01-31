#include<bits/stdc++.h>

using namespace std;

bool isKeyword(string s){
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

bool isOperator(string s){
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

bool isDigit(char c){
    return (c >= '0' && c <= '9');
} 

bool isIntegerConstant(const string s) {
    int i = 0;
    if (s[i] == '-' || s[i] == '+') {
        i++;
    }
    bool hasDigits = false;
    for ( ; i < s.size(); i++) {
        if (!isdigit(s[i]))
            return false;
        hasDigits = true;
    }
    return hasDigits;
}

bool isFloatingPointConstant(string s) {
    int i = 0;
    if (s[i] == '-' || s[i] == '+') {
        i++;
    }
    for (; i < s.size(); i++) {
        if (!isdigit(s[i]))
            break;
    }
    if (i < s.size() && s[i] == '.') {
        i++;
        bool hasDigitsAfterDecimal = false;
        for (; i < s.size(); i++) {
            if (!isdigit(s[i]))
                return false;
            hasDigitsAfterDecimal = true;
        }
        return hasDigitsAfterDecimal;
    }
    return false;
}

bool isCharacterLiteral(string s) {
    return s.size() == 3 && s[0] == '\'' && s[2] == '\'';
}


bool isConstant(string &s){
    if (isIntegerConstant(s)) {
        cout << "Integer constant detected: " << s << endl;
        return true;
    } else if (isFloatingPointConstant(s)) {
        cout << "Floating-point constant detected: " << s << endl;
        return true;
    } else if (isCharacterLiteral(s)) {
        cout << "Character constant detected: " << s << endl;
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
        if (isKeyword(s)) {
            cout << s << " is a keyword of c++\n";
        }  else if (isOperator(s)) {
            cout << s << " is a operator of c++\n";
        } else if (isConstant(s)) {
            continue;
        } else if (isIdentifier(s)) {
            cout << s << " is a identifier\n";
        } else {
            cout << s << " is other\n";
        }
    }
}