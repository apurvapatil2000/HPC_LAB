#include <omp.h>
#include <stdio.h>

int fib(int n)
{
        if (n < 2) {
                return 1;
        }
        return fib(n - 2) + fib(n - 1);
}

int main(int argc, char ** argv)
{
        int n = 0;

        #pragma omp parallel for schedule(guided, 1)
        for (n = 0; n <= 10; n++) {
                printf("Fib(%d): %d\n", n, fib(n));
        }
        return 0;
}
