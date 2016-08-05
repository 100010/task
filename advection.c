#include<stdio.h>
#include<stdlib.h>

int main(int ac, char **av)
{
    double dt = 0.02;
    double dx = 0.1;
    double c = 2.8;
    int n = (int)(20.0 / dx) +1;
    int i,k;
    double end_t=atof(av[1]);
    double u[n],unew[n];
 
    for (i= 0; i < n; i++){
        double x = (double)i * dx;

        if(x>=1.0 && x <=2.0){
	    u[i] =1.0;
        } else{
            u[i]=0.0;
        }

    }

    for (k = 0; k < 1000; k++){
	double t = (double)k *dt;

        if (t >=end_t) {
	    break;
	}

        for (i = 1; i< n; i++) {
            unew[i] = u[i] - c * (u[i] - u[i -1]) /dx *dt;
	}
	u[0]=0.0;

	      for (i = 0; i < n; i++) {
                  u[i] = unew[i];
              }
    }

    for (i = 0;i < n; i++) {
	double x=(double)i*dx;
           printf("%f %f\n", x,u[i]);
    }

    return 0;
}   

