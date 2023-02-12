#include <stdio.h>
#include <math.h>

double recursiveDescent(unsigned int depth, unsigned int lim, double x, double elem, double res) {
    unsigned int par = 2 * depth;
    unsigned int numerator = (par - 1) * (par - 1);
    unsigned int denominator = par * par + par;
    elem *= x * x * numerator / denominator;
    res += elem;
    depth++;

    printf("\nRecursive descent;\n Depth: %d, Element %d: %f, Result: %f", depth - 1, depth, elem, res);
    if (lim >= depth) {

        res = recursiveDescent(depth, lim, x, elem, res);

    } else {
        printf("\n\nSignal function was reached;\n Result: %f\n", res);
    }
    printf("\nRecursive return;\n Depth: %d, Element %d: %f, Result: %f", depth - 1, depth, elem, res);
    return res;
}

int main() {
    int depth = 1, lim;
    double x;

    printf(" Input x from diapason (-1;1): ");
    scanf("%lf", &x);
    printf("Set the recursion depth: ");
    scanf("%d", &lim);

    if (x > -1 && x < 1 && lim > 0 && !(lim % 1)) {
        double standard = asin(x);

        printf("\nCall a recursion;\n Element %d: %f", depth, x);
        x = recursiveDescent(depth, lim, x, x, x);
        printf("\nClose a recursion;\n");

        double error = (1 - x / standard) * 100;
        printf("\n Result: %f\n Standard: %f\n Observational error: %f%%", x, standard, error);
    } else {
        printf("\nInvalid arguments were passed;\n");
    }
    return 0;
}