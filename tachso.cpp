#include <stdio.h>

void split(double d, int *i, double *f) {
    *i = (int)d;
    *f = d - (*i);
}

int main() {
    double d, f;
    int i;
    printf("Nhap so thuc: ");
    scanf("%lf", &d);

    split(d, &i , &f);
    printf("Phan nguyen: %d\nPhan thuc: %f", i, f);
}
