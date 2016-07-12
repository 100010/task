#include<stdio.h>
#include<math.h>
int main(void)
{
    double alpha = 3.0;
    double a[3][3] = {{alpha,2.0,        3.0},
                      {2.0,  3.0 *alpha,1.0},
                      {3.0,  1.0,       2.0 *alpha}};
    double b[3] = {81.0,90.0,117.0};
    double x[3] ={0.0,0.0,0.0};
    double xnew[3];
    int n = 3;
    double epsilon = 1.0E-6;
    double error;
    int maxnu = 1000;
    int nu, i, j;
    double omega=0.0;
    int  k;
    for (k = 0; k < 19; k++) {
        omega = omega + 0.1;
        for(j=0; j<n; j++){
            x[j] = 0.0;
        }
        for(nu = 0; nu < maxnu; nu++) {

            for(j=0; j<n; j++){
                xnew[j]=b[j];
                for(i=0; i<j; i++){
                    xnew[j]=xnew[j]-a[j][i]*xnew[i];
                }
                for(i=j+1; i<n; i++){
                    xnew[j]=xnew[j]-a[j][i]*x[i];
                }
                //xnew[j]=b[j]-xnew[j];
                xnew[j]=omega*xnew[j]/a[j][j];
                xnew[j]=(1-omega)*x[j]+xnew[j];
            }


            error = 0.0;
            for(j=0; j<n; j++){
                if (error<fabs(xnew[j]-x[j])/fabs(x[j])){
                    error=fabs(xnew[j]-x[j])/fabs(x[j]);
                }
            }


            printf("%d %E\n", omega,nu);
            if(error < epsilon) {
                break;
            }

            for (j = 0; j < n; j++) {
                x[j] = xnew[j];
                xnew[j]=0.0;
            }
        }
    }
    printf("x =\n");
    for (j = 0; j < n; j++) {
        printf("%f\n",xnew[j]);
    }
    return 0;
}
