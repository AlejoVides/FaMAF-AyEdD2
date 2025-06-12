#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

#define MAX_LENGTH 100

struct _list {
    elem a[MAX_LENGTH];
    int start;
    int size;
};

list empty(){
    list l = calloc(1, sizeof(struct _list));
    return l;
}

list addl(elem e, list l){
    int pos = (l->start - 1 + MAX_LENGTH) % MAX_LENGTH;
    l->a[pos] = e;
    l->start = pos;
    l->size ++;
    return l;
}

bool is_empty(list l){
    return l->size == 0;
}

elem head(list l){
    assert(!is_empty(l));
    return l->a[l->start];
}

list tail(list l){
    assert(!is_empty(l));
    l->start = (l->start + 1) % MAX_LENGTH;
    l->size -= 1;
    return l;
}

list addr(list l, elem e){
    assert(l != NULL);
    int pos = (l->start + l->size) % MAX_LENGTH;
    l->a[pos] = e;
    l->size ++;
    return l;
}

int length(list l){
    assert(l != NULL);
    return l->size;
}

list concat(list l, list l0){
    int size_l0 = length(l0);
    for (int i = 0; i < size_l0; i++){
        l = addr(l, index(l0, i));
    }
    return l;
}

elem index(list l, int n){
    int pos = (l->start + n) % MAX_LENGTH;
    elem indx = l->a[pos];
    return indx;
}

list take(list l, int n){
    if (n < l ->size) {
        n = l->size - n;
        l->size = l->size - n;
    }
    return l;
}

list drop(list l, int n){
    if (n >= l->size){
        destroy_list(l);
        return NULL;
    }
    else {
        for (int i = 0; i < n; i++){
            l = tail(l);
        }
    }
    return l;
}

list copy_list(list l){
    list new = empty();
    for (int i = 0; i < l->size; i++){
        new = addr(new, index(l, i));
    }
    return new;
}

void destroy_list(list l){
    free(l);
}