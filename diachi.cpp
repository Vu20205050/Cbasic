#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {SUCCESS, FAIL, MAX_ELEMENT = 20};

typedef struct {
    char name[20];
    char tel[11];
    char email[25];
} PhoneAddress;

int main() {
    FILE *fp;
    PhoneAddress* phonearr;

    int n; 
    int reval = SUCCESS;

    printf("Read from 2nd data to 3rd data \n");
    if((fp = fopen("phonebook.dat", "r+b")) == NULL) {
        printf("Can not open %s.\n");
        reval = FAIL;
    } 
    
    phonearr = (PhoneAddress*) malloc(2*sizeof(PhoneAddress));

    if(phonearr == NULL) {
        printf("Memory allocation failed!\n");
        return FAIL;
    }

    if(fseek(fp, 1*sizeof(PhoneAddress), SEEK_SET) != 0) {
        printf("Fseek failed!\n");
        return FAIL;
    }

    int irc = fread(phonearr, sizeof(PhoneAddress), 2, fp);

    for(int i = 0; i < 2; ++i) {
        printf("%s-", phonearr[i].name);
        printf("%s-", phonearr[i].tel);
        printf("%s\n",phonearr[i].email);
    }

    strcpy(phonearr[1].name, "Lan Hoa");
    strcpy(phonearr[1].tel, "123456");
    strcpy(phonearr[1].email, "abc@mail.com");

    fseek(fp, 1*sizeof(PhoneAddress), SEEK_SET);
    irc = fwrite(phonearr, sizeof(PhoneAddress), 2, fp);
    printf("fwrite return code = %d\n", irc);
    fclose(fp); free(phonearr);
    
    return reval;
}
