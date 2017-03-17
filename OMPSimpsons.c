#include<stdio.h>
#include<time.h>
#include<omp.h>
#include<math.h>

double simpsons(double a, double b, long n);
double f(double x);

int main(int argc, char *argv[]) {
	clock_t start, end;
	int msec;

	start = clock();
	printf("OpenMP Simpsons Rule.\nf(x) = cos(x)\nn = 1000000000\ninterval: [1, 10]\n");
	printf("Result:  %f\n", simpsons(1,10,1000000000));
	end = clock();
	msec = (double)(end - start)/CLOCKS_PER_SEC*1000;
	printf("Time taken: %d seconds %d milliseconds.\n", msec/1000, msec%1000);
	return 0;
}

double simpsons(double a, double b, long n) {
	double h = (b - a) / n;
	double result, p;
	int i;
	p = 0;

	#pragma omp parallel
	{
		printf("%d\n", omp_get_num_threads());
	}

    #pragma omp parallel for reduction (+:p) private(i)
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
	return cos(x);
}
