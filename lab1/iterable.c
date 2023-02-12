#include <stdio.h>
#include <math.h>

double iterable(unsigned int lim, double x, double elem) {
    double res = elem;

    for (unsigned int i = 1; i <= lim; i++) {
        unsigned int par = 2 * i;
        unsigned int numerator = (par - 1) * (par - 1);
        unsigned int denominator = par * par + par;
        elem *= x * x * numerator / denominator;
        res += elem;
        printf("\nCurrent iteration: %d;\n Element %d: %f, Result: %f", i, i + 1, elem, res);
    }
    return res;
}

int main() {
    int lim;
    double x;

    printf(" Input x from diapason (-1;1): ");
    scanf("%lf", &x);
    printf("Set the iterable limit: ");
    scanf("%d", &lim);

    if (x > -1 && x < 1 && lim > 0 && !(lim % 1)) {
        double standard = asin(x);

        printf("\nCall a cycle;\n Element %d: %f;\n", 1, x);
        x = iterable(lim, x, x);
        printf("\n\nClose a cycle;\n");

        double error = (1 - x / standard) * 100;
        printf("\n Result: %f\n Standard: %f\n Observational error: %f%%", x, standard, error);
    } else {
        printf("\nInvalid arguments were passed;\n");
    }
    return 0;
}