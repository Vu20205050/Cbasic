#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ID_LENGTH 9
#define NAME_LENGTH 30

int total = 0;

#define true 0
#define false 1

struct Student{
    char id[ID_LENGTH];
    char name[NAME_LENGTH];
    int grade;

    struct Student *next;
};

typedef struct Student* student_t;

int to_int(char s[]) {
    int res = 0;
    for(int i = 0; i < strlen(s); ++i) {
        res = res * 10 + s[i] - '0';
    }
    return res;
}

student_t create_student_t(char id[], char name[], int grade) {
    student_t new;
    new = (student_t)malloc(sizeof(struct Student));
    new->next = NULL;
    strcpy(new->id, id);
    strcpy(new->name, name);
    new->grade = grade;
    return new;
}

student_t add_student(student_t root, student_t to_add) {
    student_t cur_student, prev_student = NULL;
    if(root == NULL) {
        return to_add;
    }

    if(to_add->grade > root->grade) {
        to_add->next = root;
        return to_add;
    }

    cur_student = root;
    while(cur_student != NULL && to_add->grade <= cur_student->grade) {
        prev_student = cur_student;
        cur_student = cur_student->next;
    }

    prev_student->next = to_add;
    to_add->next = cur_student;
    return root;
}

student_t init() {
    student_t root;
    root = NULL;
    return root;
}

student_t input(FILE *f) {
    student_t to_add, root = init();
    int grade;
    char id[ID_LENGTH], name[NAME_LENGTH], s[1024];
    while(fgets(s, 1024, f)) {
        int c = 0;
        s[strlen(s) - 1] = '\0';
        char *token = strtok(s, ";");
        while(token != NULL) {
            if(c == 0) {
                strcpy(id, token);
                //printf("1. %s - %s\n", id, token);
            } else if (c == 1) {
                strcpy(name, token);
                //printf("2. %s - %s\n", name ,token);
            } else if(c == 2) {
                grade = to_int(token);
            }
            c++;
            token = strtok(NULL, ";");
        }
        to_add = create_student_t(id, name, grade);  
        ++total;      
        root = add_student(root, to_add);
    }

    return root;
}

void traversing(student_t root) {
    printf("Total = %d\n", total);
    printf("+----------+-----------------------------+--------+\n");
    printf("|ID        |Name                         |Grade   |\n");
    printf("+----------+-----------------------------+--------+\n");
    for(student_t st = root; st != NULL; st = st->next) {
        printf("|%-10s|%-29s|%-8d|\n", st->id, st->name, st->grade);
        printf("+----------+-----------------------------+--------+\n");
    }
}

void display_student(student_t st) {
    printf("Total = %d\n", 1);
    printf("+----------+-----------------------------+--------+\n");
    printf("|ID        |Name                         |Grade   |\n");
    printf("+----------+-----------------------------+--------+\n");
    printf("|%-10s|%-29s|%-8d|\n", st->id, st->name, st->grade);
    printf("+----------+-----------------------------+--------+\n");
}

student_t find_student(student_t root, char *id) {
    student_t cur = root;
    while(cur != NULL && strcmp(cur->id, id) != 0) {
        cur = cur->next;
    }
    return cur;
}

student_t remove_student(student_t root, char *id) {
    if(root == NULL) {
        return root;
    }
    student_t cur = root, prev;
    if(strcmp(cur->id, id) == 0) {
        root = root->next;
        free(cur);
        return root;
    }

    while(cur != NULL && strcmp(cur->id, id) != 0) {
        prev = cur;
        cur = cur->next;
    }

    if(cur != NULL) {
        prev->next = cur->next;
        free(cur);
    }
    return root;
}

student_t change_grade(student_t root, char *id, int new_grade) {
    student_t st = find_student(root, id);
    st = create_student_t(id, st->name, new_grade);
    root = remove_student(root, id);
    return add_student(root, st);
}


void main_search(student_t root) {
    char id[ID_LENGTH];
    printf("[SEARCH STUDENT] Type your ID : ");
    scanf("%s", id);
    student_t find = find_student(root, id);
    if(find != NULL) {
        display_student(find);
    } else {
        printf("[SEARCH STUDENT] Error: 404 Not Found\n");
    }
}

void main_change(student_t root) {
    char id[ID_LENGTH];
    printf("[CHANGE GRADE] Type your ID : ");
    scanf("%s", id);
    student_t find = find_student(root, id);
    
    if(find != NULL) {
        int new_grade;
        printf("[CHANGE GRADE] Type %s new grade : ", find->id);
        scanf("%d", &new_grade);
        display_student(change_grade(root, id, new_grade));
        printf("[CHANGE GRADE] Changed successfully.\n");
    } else {
        printf("[CHANGE GRADE] Error: 404 Not Found\n");
    }
}

int main() {
    FILE *f = fopen("student.csv", "r");
    student_t root = input(f);
    //main_search(root);
    //main_change(root);
    traversing(root);
    fclose(f);
}
