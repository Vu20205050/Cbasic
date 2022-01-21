#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *p;

    printf("Nhap so luong: ");
    scanf("%d", &n);

    //p = (int*) calloc(n * sizeof(int), sizeof(int));
    p = (int*) malloc(n * sizeof(int));


    if(p == NULL) {
        printf("Fail~~~"); 
        return 1;
    }

    for(int i = 0; i <n; ++i) {
        scanf("%d", &p[i]);
    }

    for(int i = 0; i < n; ++i) {
        printf("%d ", p[i]);
    }
    free(p);
    return 0;
}
