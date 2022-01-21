#include <stdio.h>
#include<string>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    double w, h;
    if(argc != 3) {
        printf("Sai !!!");
        return 1;
    }
	 w = atof(argv[1]);
    h =  atof(argv[2]);

    printf("Dien tich hinh chu nhat: %f\n", w * h);
    printf("Chu vi hinh chu nhat : %f", 2 * (w + h));
    return 0;
}
