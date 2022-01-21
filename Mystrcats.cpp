#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* my_strcat(char* s1, char* s2) {
    char* kq = (char*) malloc((strlen(s1) + strlen(s2) + 1)*sizeof(char));
    if(kq == NULL) {
        printf("NULL\n");
        return NULL;
    }

    strcpy(kq, s1);
    strcpy(kq + strlen(s1), s2);
    return kq;
}

int main() {
    char s1[101], s2[101];
    scanf("%100s", s1);
    scanf("%100s", s2);

    char* cat;
    cat = my_strcat(s1, s2);

    if(cat == NULL) {
        printf("NULL");
        return 1;
    }

    printf("Ket qua: %s", cat);
    free(cat);
    return 0;
}
