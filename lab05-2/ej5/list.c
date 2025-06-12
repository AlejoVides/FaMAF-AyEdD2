#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

#define MAX_LENGTH 100

struct _list {
    elem elems[MAX_LENGTH];
    int size;
};

list empty() {
    list l = malloc(sizeof(struct _list));
    l->size = 0;
    return l;
}

list addl(elem e, list l) {
    l->elems[(MAX_LENGTH - 1) - l->size] = e;
    l->size += 1;
    return l;  
}

bool is_empty(list l) {
    return l->size == 0;
}

elem head(list l) {
    assert(!is_empty(l));
    return l->elems[MAX_LENGTH - l->size];
}

list tail(list l) {
    assert(!is_empty(l));
    l->size -= 1;
    return l;
}

list addr(list l, elem e) {
    for(int i = MAX_LENGTH - l->size; i < MAX_LENGTH; i++) {
        l->elems[i-1] = l->elems[i]; 
    }
    l->elems[MAX_LENGTH-1] = e;
    l->size += 1;
    return l;
}

int length(list l) {
    return l->size;
}

list concat(list l, list l0) {
    assert(l->size + l0->size <= MAX_LENGTH);
    
    int primer_elem_l = (MAX_LENGTH - l->size);
    int primer_elem_l0 = (MAX_LENGTH - l0->size);

    for(int i = 0; i < l->size; i++) {
        l->elems[primer_elem_l + i - l0->size] = l->elems[primer_elem_l + i];
    }

    for(int j = 0; j < l0->size; j++) {
        l->elems[primer_elem_l0 + j] = l0->elems[primer_elem_l0 + j];
    }

    l->size = l->size + l0->size;
    return l;
}

elem index(list l, int n) {
    assert(n < length(l));
    return l->elems[MAX_LENGTH - l->size + n];
}

list take(list l, int n) {
    if (n <= 0) l->size = 0;
    else if (n >= l->size) return l;

    for (int i = 0; i < n; i++) {
        addr(l, l->elems[MAX_LENGTH - l->size + i]);
    }
    l->size = n;
    return l;
}

list drop(list l, int n) {
    if(l->size < n) l->size = 0;
    else l->size = l->size - n;
    return l;
}

list copy_list(list l) {
    list new_list = empty();
    int primer_elem = MAX_LENGTH - l->size;
    for(int i = 0; i < l->size; i++) {
        new_list->elems[primer_elem + i] = l->elems[primer_elem + i];
    }
    new_list->size = l->size;
    return new_list;
}

void destroy_list(list l) {
    free(l);
}