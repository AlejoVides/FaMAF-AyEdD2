#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"

struct _list {
    elem elem;
    struct _list* next;
};

list empty(void) {
    list l = NULL;
    return l;
}

list addl(elem e, list l) {
    list p = malloc(sizeof(struct _list));
    p->elem = e;
    p->next = l;
    return p;
}

void destroy_list(list l) {
    list k = l;
    while(k !=  NULL) {
        list next = k->next;
        free(k);
        k = next;
    }
}

bool is_empty(list l) {
    return l == NULL;
}

elem head(list l) {
    return l->elem;
}

list tail(list l) {
    list p = l;
    l = l->next;
    free(p); 
    return l;
}

list addr(list l, elem e) {
    list q = malloc(sizeof(struct _list));
    q->elem = e;
    q->next = NULL;
    if(!is_empty(l)){
        list p = l;
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = q;
    }
    else {
        l = q;
    }
    return l;
}

int length(list l) {
    int n = 0;
    list p = l;

    while(p != NULL) {
        n++;
        p = p->next;
    }
    return n;
}

list concat(list l, list l0) {
  list l0_copy = copy_list(l0);

  if (l == NULL) {
    return l0_copy;
  } else {
    list p = l;
    while (p->next != NULL) {
      p = p->next;
    }
    p->next = l0_copy;
    }
    return l;
}

elem index(list l, int n) {
    list p = l;
    for(int i = 0; i < n; i++) {
        p = p->next;
    }
    return p->elem;
}

list take(list l, int n) {
    if(n == 0) {
        destroy_list(l);
        l = NULL;
    } else if (n > length(l)) {
        return l;
    } else {
        list p = l;
        for(int i = 1; i < n; i++) {
            p = p->next;
        }
        list rest = p->next;
        p->next = NULL;
        destroy_list(rest);
    }
    return l;
}

list copy_list(list l) {    
    list l2;

    if(is_empty(l)) {
        l2 = NULL;
    } else {
        l2 = malloc(sizeof(struct _list));
        l2->value = l->value;
        l2->next = copy_list(l->next);
    }
    
    return l2;
}
