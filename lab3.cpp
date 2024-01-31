#include<bits/stdc++.h>

using namespace std;

map<string, string>full_form;
vector<string>courses[5][3];

void pre_define(){
    full_form["CSE"] = "Computer Science and Engineering";
    full_form["EEE"] = "Electrical and Electronic Engineering";
    full_form["ICE"] = "Information and Communication Engineering";
    courses[3][1].push_back(" ");
    courses[3][1].push_back("SWE");
    courses[3][1].push_back("DBMS");
    courses[3][1].push_back("Web Engineering");
    courses[3][1].push_back("Compiler Design");
    courses[3][1].push_back("Mobile app");
}

void print(char ch){
    if (ch == '1') cout << "1st";
    else if (ch == '2') cout << "2nd";
    else if (ch == '3') cout << "3rd";
    else {
        cout << ch << "th";
    }
}

int main()
{
    pre_define();

    // input : CSE-3141
    string c_code;
    cin >> c_code;

    int n = c_code.size();
    string dept = "";
    for (int i = 0; c_code[i] != '-'; i++) {
        dept.push_back(c_code[i]);
    }

    int year = c_code[n-4] - '0';
    int semester = c_code[n-3] - '0';

    cout << full_form[dept] << ",";
    print(c_code[n-4]); cout << " year,";
    print(c_code[n-3]);
    cout << " semester, ";

    cout << courses[year][semester][c_code[n-2] - '0'];
    if (c_code[n-1] == '1') cout << ", Theory.";
    else cout << ", Lab.";

    return 0;
}
