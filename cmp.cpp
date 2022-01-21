#include <stdio.h>

#define MX 10000

int cmp(int a[], int n1, int b[], int n2) {
    if(n1 != n2) return 0;
    for(int i = 0; i < n1; i++) {
        if(a[i] != b[i]) return 0;
    }
    return 1;
}

int nhap(int a[]) {
    int n; 
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    return n;
}

int main() {
    int a[MX], b[MX], n1, n2;
    printf("Nhap so phan tu mang 1:");
    n1 = nhap(a);
    printf("Nhap so phan tu mang 2:");
    n2 = nhap(b);
    printf("%d", cmp(a, n1, b, n2)); 
}
