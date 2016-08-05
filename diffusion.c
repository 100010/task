#include<stdio.h>
#include<stdlib.h>

int main(int ac, char **av)
{
    double dt = 0.05;
    double dx =0.2;
    double end_t =atof (av[1]);
    int n = (int)(10.0 / dx) +1;
    int i,k;
    double u[n],unew[n];

    for (i= 0; i < n; i++){
        double x = (double)i * dx;

        if(x==10.0){
	    u[i] =1.0;
        } else{
            u[i]=0.0;
        }

    }

    for (k = 0; k < 100000; k++){
	double t = (double)k *dt;

        if (t >= end_t) {
	    break;
	}

        for (i = 0; i< n; i++) {
            unew[i] = u[i] + (u[i+1] - 2.0*u[i] + u[i-1]) / (dx*dx) * dt;
	}

        unew[0] = 0.0;
        unew[n-1] = 1.0;

	for (i = 0; i < n; i++) {
	    u[i] = unew[i];
	}
    }

    for (i = 0;i < n; i++) {
        double x = (double)i * dx;
        printf("%f %f\n", x,u[i]);
    }

    return 0;
}
