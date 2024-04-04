/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <math.h>
#include <stdio.h>

/*int pop(int k, int pop0)
/*{
    int pop1 = ((k * pop0) * (1000 - pop0) / 1000);
    int pop2 = ((k * pop1) * (1000 - pop1) / 1000);
    return pop2;
}
*/

int cal (double k, int xi)
{
    double xn = ((k * xi) * ((1000 - xi) / 1000));
	      return xn;	      
}

int recur (double k, double xi)
{
    int n = 1;
    int h = 100;
    double xn;

    while (n < h) {
	xn = cal (k, xi);
	n++;
	xi = xn;
	printf("%d\n", xn);
    }
}

int main(int argc, char **argv)
{
    double k = 3.3;
    double xi = 10;
    double xn;
    recur(k, xi);
}
