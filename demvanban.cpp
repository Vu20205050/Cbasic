#include <stdio.h>

#define MX 26

void run() {
    char ch;
    int count[MX] = {0};
    while((ch = getchar()) != '\n') {
        if('a' <= ch && ch <= 'z') {
            ++count[ch - 'a'];
        }
        if('A' <= ch && ch <= 'Z') {
            ++count[ch - 'A'];
        }
    }
    int num_diff = 0;
    for(int i = 0; i < MX; i++) {
        if(count[i] > 0) {
            printf("Chu '%c' xuat hien %d lan.\n", 'a' + i, count[i]);
            ++num_diff;
        }
    }
    printf("So ki tu khac nhau la: %d", num_diff);
    return ;
}
int main() {
    run();
}
