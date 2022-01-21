#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct _stack {
    stack_t* arr;
    int size;
    int top;
};

static stack stack_create_maxsize(int max_size) {
    if(max_size <= 0) {
        fprintf(stderr, "Wrong stack size (%d).\n", max_size);
        abort();
    }

    stack s = (stack)malloc(sizeof(struct _stack));
    if(s == NULL) {
        fprintf(stderr, "Couldn't allocate memory.\n");
        abort();
    }

    stack_t *items;
    items = (stack_t *)malloc(sizeof(stack_t) * max_size);

    if(items == NULL) {
        fprintf(stderr, "Couldn't allocate memory.\n");
        abort();
    }

    s->arr = items;
    s->size = max_size;
    s->top = -1;

    return s;
}

stack stack_create() {
    return stack_create_maxsize(64);
}

void stack_destroy(stack s) {
    if (s == NULL) {
        fprintf(stderr, "Cannot destroy stack.\n");
        abort();
    }

    free(s->arr);
    free(s);
}

static void stack_resize(stack s) {
    if(s == NULL) {
        fprintf(stderr, "Cannot resize stack.\n");
        abort();
    }

    int new_size = 2 * s->size;
    stack_t* new_arr = (stack_t *)malloc(sizeof(stack_t) * new_size);
    if(new_arr == NULL) {
        fprintf(stderr, "Couldn't allocate memory to resize stack.\n");
        abort();
    }

    int i;
    for(int i = 0; i <= s->top; i++) {
        new_arr[i] = s->arr[i];
    }

    free(s->arr);
    s->arr = new_arr;
    s->size = new_size;
}

void stack_push(stack s, stack_t value) {
    if(s->top >= s->size-1) {
        stack_resize(s);
    }

    s->arr[++s->top] = value;
}

int stack_is_empty(stack s) {
    if(s == NULL) {
        fprintf(stderr, "Stack is (null).\n");
        abort();
    }

    return s->top < 0;
}

int stack_size(stack s) {
    if(s == NULL) {
        fprintf(stderr, "Cannot work with (null) stack.\n");
    }
    return s->top+1;
}

void stack_pop(stack s) {
    if(stack_is_empty(s)) {
        fprintf(stderr, "Cannot pop element from stack.\n");
        abort();
    }

    s->top--;
}

stack_t stack_top(stack s) {
    if(stack_is_empty(s)) {
        fprintf(stderr, "Stack is empty.\n");
        abort();
    }

    return s->arr[s->top];
}

void stack_clear(stack s) {
    if (s == NULL) {
        fprintf(stderr, "Cannot work with (null) stack.\n");
        abort();
    }

    s->top = -1;
}
