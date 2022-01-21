#include <stdio.h>
#include <string.h>


int main() {
    char in_name[25], out_name[25];
    FILE *in_file, *out_file;

    printf("File can copy: ");
    scanf("%24s", in_name);
    printf("Ten file output (Co the NULL): ");
    scanf("%24s", out_name);

    in_file = fopen(in_name, "r");
    if(strcmp(in_name, out_name) == 0) {
        char new1[30] = "Copy_";
        strcat(new1,out_name);
        strcpy(out_name,new1);
    }

    if(in_name == NULL) {
        printf("Khong the doc file %s\n", in_name);
    } else {
        out_file = fopen(out_name, "w");
        if(out_name == NULL) {
            printf("Khong the doc file %s\n", in_name);
        } else {
            char c;
            while(fscanf(in_file,"%c", &c) != EOF) {
                fprintf(out_file, "%c", c);
            }
            printf("File da duoc copy!\n");
            fclose(out_file);
        }
        fclose(in_file);
    }
}
