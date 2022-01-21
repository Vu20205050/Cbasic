#include <stdio.h>

#define BUF 256

void run(FILE *in) {
    unsigned int line = 0;
    char tx[BUF];
    while(fgets(tx, BUF, in)) {
        printf("%d. %s", ++line, tx);
    } 
}

int main() {
    FILE *in = fopen("homework.in", "r");
    run(in);
    fclose(in);
}
