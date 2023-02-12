#include <stdio.h>
#include <math.h>

double prevElem;

double recursiveReturn(unsigned int depth, double x, double elem) {
    double res = 0;

    if (depth == 0) {
        res = x;
        prevElem = x;
        printf("\n\nSignal function was reached;\n Result: %f\n Element 1: %f\n", res, x);
    } else {
        printf("\nRecursive descent;\n Depth: %d, Element %d: %f, Result: %f", depth, depth + 1, elem, res);

        res = recursiveReturn(depth - 1, x, elem);

        unsigned int par = 2 * depth;
        unsigned int numerator = (par - 1) * (par - 1);
        unsigned int denominator = par * par + par;
        elem = prevElem * x * x * numerator / denominator;
        prevElem = elem;
        res += prevElem;

        printf("\nRecursive return;\n Depth: %d, Element %d: %f, Result: %f", depth, depth + 1, elem, res);
    }
    return res;
}

int main() {
    int depth;
    double x;

    printf(" Input x from diapason (-1;1): ");
    scanf("%lf", &x);
    printf("Set the recursion depth: ");
    scanf("%d", &depth);

    if (x > -1 && x < 1 && depth > 0 && !(depth % 1)) {
        double standard = asin(x);

        printf("\nCall a recursion;");
        x = recursiveReturn(depth, x, 0);
        printf("\nClose a recursion;\n");

        double error = (1 - x / standard) * 100;
        printf("\n Result: %f\n Standard: %f\n Observational error: %f%%", x, standard, error);
    } else {
        printf("\nInvalid arguments were passed;\n");
    }
    return 0;
}