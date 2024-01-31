#include<bits/stdc++.h>

using namespace std;

vector<char>vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

bool isLetter(char ch){
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
}

bool isVowel(char ch){
    for (auto it : vowels) {
        if (it == ch)
            return true;
    }
    return false;
}

int main()
{
    freopen("in.txt", "r", stdin);

    string s; //Munmun is the student of computer Science & Engineering
    getline(cin, s);
    cout << s << endl;

    vector<char>str_v, str_c;
    int number_of_vowels = 0, number_of_consonants = 0;
    for (int i = 0; i < s.size(); i++) {
        if (isLetter(s[i])) {
            if (isVowel(s[i])) {
                number_of_vowels++;
                str_v.push_back(s[i]);
            } else {
                number_of_consonants++;
                str_c.push_back(s[i]);
            }
        }
    }

    cout << "number of vowels: " << number_of_vowels << endl;
    cout << "number of consonants: " << number_of_consonants << endl;
    cout << "Vowels are: ";
    for (auto it : str_v)
        cout << it << " ";
    cout << endl;
    cout << "Consonants are: ";
    for (auto it : str_c)
        cout << it << " ";
    cout << endl;

    vector<string>word1, word2;
    string tmp;
    for (int i = 0; i < s.size(); i++) {
        if (isLetter(s[i])) tmp.push_back(s[i]);
        else if (tmp.size()) {
            if (isVowel(tmp[0])) word1.push_back(tmp);
            else word2.push_back(tmp);
            tmp.clear();
        }
    }
    if (tmp.size()) {
        if (isVowel(tmp[0])) word1.push_back(tmp);
        else word2.push_back(tmp);
    }
    cout << "Words started with vowel: ";
    for (auto it : word1)
        cout << it << " ";
    cout << endl;
    cout << "Words started with consonant: ";
    for (auto it : word2)
        cout << it << " ";
    cout << endl;
}
