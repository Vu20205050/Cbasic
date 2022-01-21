#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stack.h>

int main(int argc, char *argv[]) {
    char *a = argv[1];
    stack s = stack_create();
    int i, n = strlen(a);
    for(int i = 0; i < n; ++i) {
        if(a[i] == ')') {
            printf("%c", (char)stack_top(s));
            stack_pop(s);
        } 
        if(a[i] == '+' || a[i] == '*') stack_push(s, a[i]);
        if(a[i] >= '0' && a[i] <= '9') printf("%c ", a[i]);
    }
    return 0;
}
