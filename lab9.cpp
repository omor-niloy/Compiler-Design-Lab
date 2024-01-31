#include<bits/stdc++.h>

using namespace std;

vector<string>PN_P = {"Sagor", "Selim", "Salma", "Nipu", "he", "she", "I", "we", "you", "they"};

vector<string>V = {"read", "eat", "take", "run", "write"};

vector<string>N = {"book", "cow", "dog", "home", "grass", "rice", "mango"};

bool checkSub(string s){
    for(int i = 0; i < (int)PN_P.size(); i++){
        if(s == PN_P[i]) return true;
    }
    return false;
}

bool checkVerb(string s){
    for(int i = 0; i < (int)V.size(); i++){
        if(s == V[i]) return true;
    }
    return false;
}

bool checkOBJ(string s){
    for(int i = 0; i < (int)N.size(); i++){
        if(s == N[i]) return true;
    }
    cout << s.size() << endl;
    return false;
}

int main()
{
    freopen("in.txt", "r", stdin);
    string s;

    // Sagor eat bool
    // Nipu dog run

    while (getline(cin, s)) {
        
        // split the sentance into words
        vector<string>words;
        string word;
        for (int i = 0; i < (int)s.size(); i++) {
            if ((s[i] <= 'Z' && s[i] >= 'A') || (s[i] <= 'z' && s[i] >= 'a')) {
                word.push_back(s[i]);
            } else {
                if (word.size()) {
                    words.push_back(word);
                }
                word.clear();
            }
        }
        if (word.size()) {
            words.push_back(word);
        }

        // according to the grammar, words size should be 2 or 3
        // if not, then the sentance is invalid
        if (words.size() < 2 || words.size() > 3) {
            cout << "Invalid sentance" << endl;
            continue;
        }
        // check if the first word is a PN | P and the second word is a V
        // if not, then the sentance is invalid
        if (!(checkSub(words[0]) && checkVerb(words[1]))) {
            cout << "Invalid sentance" << endl;
            continue;
        }
        // if the sentance is size 3, then the third word should be N
        // if not, then the sentance is invalid
        if (words.size() == 3 && (!checkOBJ(words[2]))) {
            cout << "Invalid sentance" << endl;
            continue;
        }

        cout << "Valid sentance" << endl;
    }
}
