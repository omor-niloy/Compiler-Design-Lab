#include<stdio.h>
#include<string.h>

int check_char(char ch){
    // 1 -> letter
    // 2 -> digit
    // 3 -> space
    // 4 -> others

    if (ch >= 'a' && ch <= 'z') return 1;
    if (ch >= 'A' && ch <= 'Z') return 1;
    if (ch >= '0' && ch <= '9') return 2;
    if (ch == ' ') return 3;
    return 4;
}

int count_words(char s[]){
    int result = 0, tmp = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        int x = check_char(s[i]);
        if (x == 3) {
            result += tmp;
            tmp = 0;
        } else {
            tmp = 1;
        }
    }
    result += tmp;
    return result;
}

int count_letters(char s[]){
    int result = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
        result += (check_char(s[i]) == 1);
    return result;
}

int count_digits(char s[]){
    int result = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
        result += check_char(s[i]) == 2;
    return result;
}

int count_others(char s[]){
    int result = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
        result += check_char(s[i]) == 4;
    return result;
}

void print_all_letters(char s[]){
    int n = strlen(s);
    printf("All letters : ");
    for (int i = 0; i < n; i++) {
        if (check_char(s[i]) == 1)
            printf("%c ", s[i]);
    }
    printf("\n");
}

void print_all_digits(char s[]){
    int n = strlen(s);
    printf("All digits : ");
    for (int i = 0; i < n; i++) {
        if (check_char(s[i]) == 2)
            printf("%c ", s[i]);
    }
    printf("\n");
}

void print_all_others(char s[]){
    int n = strlen(s);
    printf("All others : ");
    for (int i = 0; i < n; i++) {
        if (check_char(s[i]) == 4)
            printf("%c ", s[i]);
    }
    printf("\n");
}

int main()
{
    // input : MD. TaReQ ZaMaN, Part-3, 2011
    freopen("in.txt", "r", stdin);
    char s[100];
    scanf("%[^\n]", s);
    printf("%s\n", s);

    // (a)
    printf("Number of words : %d\n", count_words(s));
    printf("Number of letters : %d\n", count_letters(s));
    printf("Number of digits : %d\n", count_digits(s));
    printf("Number of others : %d\n", count_others(s));

    // (b)
    print_all_letters(s);
    print_all_digits(s);
    print_all_others(s);

    return 0;
}
