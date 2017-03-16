#include<stdio.h>

double simpsons(double a, double b, int n); 
double f(double x);

int main(int argc, char *argv[]) {
	printf("Simpsons Rule.\n");
	printf("%f\n", simpsons(1,10,4));
	return 0;
}

double simpsons(double a, double b, int n) {
	double h = (b - a) / n;
	double x, result, p;
	int i;
	p = 0;
	x = a + h;
	
	for(i = 1; i < n; i++) {
		if(i%2 == 0) {
			p += f(x) * 2;
		} else {
			p += f(x) * 4;
		}
		x += h;
	}
		
	result = (h/3) * (f(a) + f(b) + p);
	return result;
}


double f(double x) {
	return x*x;
}
