#include<stdio.h>
#include<omp.h>

double simpsons(double a, double b, int n); 
double f(double x);

int main(int argc, char *argv[]) {
	printf("Simpsons Rule.\n");
	printf("%f\n", simpsons(1,10,4));
	return 0;
}

double simpsons(double a, double b, int n) {
	double h = (b - a) / n;
	double result, p;
	int i;
	p = 0;

    #pragma omp parallel for reduction (+:p)
	for(i = 1; i < n; i++) {
		if(i%2 == 0) {
			p += f(a + i * h) * 2;
		} else {
			p += f(a + i * h) * 4;
		}
	}
	#pragma omp single	
	result = (h/3) * (f(a) + f(b) + p);
	return result;
}


double f(double x) {
	return x*x;
}
