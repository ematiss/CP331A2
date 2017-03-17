#include<stdio.h>
#include<time.h>
#include<math.h>

double simpsons(double a, double b, long n);
double f(double x);

int main(int argc, char *argv[]) {
	clock_t start, end;
	printf("Serial Simpsons Rule.\nIntegral of cos(x) on interval: [1, 10], n = 1000000000\n");
	start = clock();
	printf("Result: %f\n", simpsons(1,10,1000000000));
	end = clock();
	int msec = (double)(end - start)/CLOCKS_PER_SEC*1000;
	printf("Time taken: %d seconds %d milliseconds.\n", msec/1000, msec%1000);
	return 0;
}

double simpsons(double a, double b, long n) {
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
	return cos(x);
}
