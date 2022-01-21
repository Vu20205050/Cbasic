#include <stdio.h>
#include <stdlib.h>

#define NAME_LENGTH 31
#define PHONE_LENGTH 10
#define EMAIL_LENGTH 31

struct address {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char email[EMAIL_LENGTH];
};

struct _cstack {
    struct address addr;
    struct _cstack *next;
};

typedef struct address* address_t;
typedef struct _cstack* cstack;

cstack top;

void cstack_create(cstack s) {
    top = NULL;
}

address_t address_create(char name[], char phone[], char email[]) {
    address_t new1;
    new1 = (address_t) malloc(sizeof(struct address));
    
}
