#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define size 4

double lab4(double x_const,double *x,double *y)
{
    double sum = 0.0;
	for(int i = 0; i < size; i++){
		double mul = y[i];
		for(int j = 0; j < size; j++){
			if(i!=j) 
                mul *= (x_const - x[j])/(x[i]-x[j]); 
		}
		sum += mul;
	}
    return sum;
}

void sort(double *x,double *y)
{
    double swap;
    int size2 = size;
    while(1)
    {
        if(x[size2] < x[size2-1])
        {
            swap = x[size2-1];
            x[size2-1] = x[size2];
            x[size2] = swap;
            swap = y[size2-1];
            y[size2-1] = y[size2];
            y[size2] = swap;
            size2--;
        }
        else
            break;

    }
}

int main()
{
    FILE* in;
    FILE* out;
    double x[size];
    double y[size];
    double x_const = 2.56;

    in = fopen("1.txt", "r");
    out = fopen("2.txt", "w");

    for (int i = 0; i < size; i++)
    {
            fscanf(in, "%lf", &x[i]);
    }
    for (int i = 0; i < size; i++)
    {
            fscanf(in, "%lf", &y[i]);
    }
    double y_const = lab4(x_const,&x[0],&y[0]);
    x[size] = x_const;
    y[size] = y_const;
    sort(x,y);
    for(int i = 0;i <= size;i++)
    {   
        fprintf(out, "%lf\t",x[i]);
        fprintf(out, "%lf\n",y[i]);
    }
    fclose(in);
    fclose(out);
    return 0;
}