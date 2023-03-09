#include <stdio.h>
#include <stdlib.h>

// Linked List

typedef struct LinkedList {
    double data;
    struct LinkedList * prev;
} l_list;

l_list * initList(double data) {
    l_list *curr;
    curr = malloc(sizeof(struct LinkedList));
    curr -> data = data;
    curr -> prev = NULL;
    return curr;
}

l_list * listPush(l_list *last, double data) {
    l_list *curr;
    curr = malloc(sizeof (struct LinkedList));
    curr -> data = data;
    curr -> prev = last;
    return curr;
}

l_list * listPop(l_list *last) {
    l_list *curr = last;
    struct LinkedList *prev = curr -> prev;
    free(curr);
    return prev;
}

l_list * clearList(l_list *last) {
    l_list *curr = last;
    unsigned int counter = 0;
    while (curr) {
        curr = listPop(curr);
        counter++;
    }
    printf("\n%u nodes were released", counter);
    return NULL;
}

// Auxiliary functions

l_list * addData(unsigned int lim, double x, double elem, l_list *pointer) {
    double res = elem;
    unsigned int counter = 0;
    for (unsigned int i = 1; i <= lim; i++) {
        unsigned int par = 2 * i;
        unsigned int numerator = (par - 1) * (par - 1);
        unsigned int denominator = par * par + par;
        elem *= x * x * numerator / denominator;
        res += elem;
        pointer = listPush(pointer, res);
        printf("\nCurrent node: %d, Prev: %d, Data: %f",
               pointer, pointer -> prev, pointer -> data);
        counter++;
    }
    printf("\n%u nodes were added\n", counter);
    return pointer;
}

l_list * reflectList(l_list *last) {
    l_list * pointer = last;
    l_list * node = last;
    unsigned int counter = 0;
    while (node) {
        pointer = listPush(pointer, node -> data);
        node = node -> prev;
        printf("\nCurrent node: %d, Prev: %d, Data: %f",
               pointer, pointer -> prev, pointer -> data);
        counter++;
    }
    printf("\n%u nodes were added\n", counter);
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
        l_list * pointer = initList(x);
        printf("\nCurrent node: %d, Prev: %d, Data: %f\n",
               pointer, pointer -> prev, pointer -> data);

        printf("\nAdds nodes...\n");
        pointer = addData(lim, x, x, pointer);

        printf("\nReflects nodes...\n");
        pointer = reflectList(pointer);

        printf("\nClearing list...\n");
        pointer = clearList(pointer);
    } else {
        printf("\nInvalid arguments were passed;\n");
    }
    return 0;
}
