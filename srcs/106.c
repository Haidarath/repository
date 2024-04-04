/*
** EPITECH PROJECT, 2024
** 106.c
** File description:
** 106 project
*/
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void my_description(void)
{
    printf("USAGE\n    ./106bombyx n [k | i0 i1]\n\nDESCRIPTION\n");
    printf("    n      number of first generation individuals\n");
    printf("    k      growth rate from 1 to 4\n");
    printf("    i0     initial generation (included)\n");
    printf("    i1     final generation (included)\n");
}

int error_case(int ac, char **av)
{
    int i = 0;
    int j = 0;
    if (ac < 3 || ac > 4)
        return 84;
    for (i = 0; av[1][i] != '\0'; i++)
        if (av[1][i] < '0' || av[1][i] > '9')
            return 84;
    for (i = 2; av[i] != NULL; i++)
        for (j = 0; av[i][j] != '\0'; j++)
            if (av[i][j] == '.' || av[i][j] >= '0' && av[i][j] <= '9')
                continue;
            else
                return 84;    
}

void function(int n, double k)
{
    double r = n;
    int i = 1;

    printf("%d %.2f\n", i, r);
    for (; i < 100; i++) {
        r = ((k * r) * (1000 - r)) / 1000;
        printf("%d %.2f\n", i + 1, r);
    }
}

void function2(int n, int i0, int i1)
{
    double t = n;
    double k = 1;
    int i = 0;

    for (k = 1;k <= 4; k = k + 0.01) {
        for (i = 0; i <= i1; i++) {
            t = ((k * t) * (1000 - t)) / 1000;
            if (i >= i0 && i <= i1)
                printf("%.2f %.2f\n", k, t);
        }
    }
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_description();
        return 0;
    }
    if (error_case(ac, av) == 84)
        return 84;
    if (ac == 3) {
        int n = atoi(av[1]);
        double k = atof(av[2]);
            if (k < 1 || k > 4) {
                return 84;
            }
        function(n, k);
    }
    else if (ac == 4) {
        int n = atoi(av[1]);
        int i0 = atoi(av[2]);
        int i1 = atoi(av[3]);
        if(i0 >= i1) {
            return 84;
        }
        function2(n, i0, i1);
    }
}
