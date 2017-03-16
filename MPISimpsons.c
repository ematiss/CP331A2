#include<stdio.h>
#include<mpi.h>

double simpsons(double a, double b, int n); 
double f(double x);

int main(int argc, char *argv[]) {
	int n = 10;
	int rank;
	int world;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &world);

	int i, numblocks, base = 0;
	numblocks = n/world;
	base = numblocks;
	if(rank < n%world) {
		numblocks++;
	}
	
	if(rank-1 < n%world) {
		base++;
	}
	if(rank == 0) {
		base = 0;
	}

	int start, stop;
	
	

	
	for(i = 0; i < numblocks; i++)
		printf("%d processes %d.\n", rank, rank+base+i);

	MPI_Finalize();

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
