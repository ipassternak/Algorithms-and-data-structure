#include <stdio.h>
#include <stdlib.h>

// Double Linked List

typedef struct DoubleLinkedList {
    double data;
    struct DoubleLinkedList * next;
    struct DoubleLinkedList * prev;
} dl_list;

dl_list * initList(double data) {
    dl_list *curr;
    curr = malloc(sizeof(struct DoubleLinkedList));
    curr -> data = data;
    curr -> prev = NULL;
    curr -> next = NULL;
    return curr;
}

dl_list * listPush(dl_list *last, double data) {
    dl_list *curr;
    curr = malloc(sizeof (struct DoubleLinkedList));
    curr -> data = data;
    curr -> next = NULL;
    curr -> prev = last;
    last -> next = curr;
    return curr;
}

dl_list * listPop(dl_list *last) {
    dl_list *curr = last;
    struct DoubleLinkedList *prev = curr -> prev;
    prev -> next = NULL;
    free(curr);
    return prev;
}

dl_list * listFind(dl_list *last, double data) {
    dl_list *curr = last;
    struct DoubleLinkedList *prev = curr -> prev;
    while (curr) {
        if (data == curr -> data) return curr;
        curr = prev;
        if (prev) prev = curr -> prev;
    }
    return NULL;
}

dl_list * listRemove(dl_list *last, double data) {
    dl_list *curr = last;
    struct DoubleLinkedList *next = curr -> next;
    struct DoubleLinkedList *prev = curr -> prev;
    while (curr) {
        if (data == curr -> data) {
            if (curr == last) {
                prev -> next = NULL;
                free(curr);
                return prev;
            } else {
                prev -> next = next;
                next -> prev = prev;
                free(curr);
                return last;
            }
        } else {
            next = curr;
            curr = prev;
            if (curr) prev = curr -> prev;
        }
    }
    return NULL;
}

dl_list * clearList(dl_list *last) {
    dl_list *curr = last;
    unsigned int counter = 0;
    struct DoubleLinkedList *prev = curr -> prev;
    while (curr) {
        counter++;
        free(curr);
        curr = prev;
        if (curr) prev = curr -> prev;
    }
    printf("\n%u nodes were released", counter);
    return NULL;
}

// Auxiliary functions

dl_list * addData(unsigned int lim, double x, double elem, dl_list *pointer) {
    double res = elem;
    for (unsigned int i = 1; i <= lim; i++) {
        printf("\nCurrent node: %d, Next: %d, Prev: %d, Data: %f",
               pointer, pointer -> next, pointer -> prev, pointer -> data);
        unsigned int par = 2 * i;
        unsigned int numerator = (par - 1) * (par - 1);
        unsigned int denominator = par * par + par;
        elem *= x * x * numerator / denominator;
        res += elem;
        pointer = listPush(pointer, res);
    }
    printf("\nLast node: %d, Next: %d, Prev: %d, Data: %f\n",
           pointer, pointer -> next, pointer -> prev, pointer -> data);
    return pointer;
}

dl_list * reflectList(dl_list *last) {
    dl_list * pointer = last;
    dl_list * node = last;
    while (node) {
        pointer = listPush(pointer, node -> data);
        node = node -> prev;
        if (node) {
            printf("\nCurrent node: %d, Next: %d, Prev: %d, Data: %f",
                   pointer, pointer -> next, pointer -> prev, pointer -> data);
        }
    }
    printf("\nLast node: %d, Next: %d, Prev: %d, Data: %f\n",
           pointer, pointer -> next, pointer -> prev, pointer -> data);
    return pointer;
}

int main() {
    int lim;
    double x;

    printf(" Input x from diapason (-1;1): ");
    scanf("%lf", &x);
    printf("Set the limit: ");
    scanf("%d", &lim);
    if (x > -1 && x < 1 && lim > 0 && !(lim % 1)) {
        printf("\nInitialising of double linked list...\n");
        dl_list * pointer = initList(x);

        printf("\nAdds nodes...\n");
        pointer = addData(lim, x, x, pointer);

        printf("\nReflects nodes...\n");
        pointer = reflectList(pointer);

        printf("\nClearing list...\n");
        pointer = clearList(pointer);
        printf("\nLast node: %d\n", pointer);
    } else {
        printf("\nInvalid arguments were passed;\n");
    }
    return 0;
}
