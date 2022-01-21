#include <stdio.h>
#include <string.h>

#define MX 101

void replace(char s[], char c1, char c2) {
    for(int i = 0; i < strlen(s); ++i) {
        if(s[i] == c1) {
            s[i] = c2;
        }
    }
}

void replace_char(char *str, char c1, char c2) {
    if(str == NULL) {
        return ;
    }
    int f = 0;
    while(*str != '\0') {
        if(*str == c1) {
            f = 1;
            *str = c2;
        }
        ++str;
    }
}
int main() {
    char s[MX + 1];
    char c1, c2;
    printf("Nhap xau ki tu:\n");
    scanf("%100s", s);
    fflush(stdin);

    printf("Nhap ki tu can thay the: ");
    scanf("%c", &c1);
    char tmp;
    
    do{ tmp = getchar();} while(tmp != '\n');

    printf("Nhap ki tu sau khi thay the: ");
    scanf("%c", &c2);
    
    replace_char(s, c1, c2);
    printf("Ket qua: %s", s);
    return 0;
}
