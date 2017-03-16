#include<stdio.h>
#include<mpi.h>
#include<math.h>

double f(double x);

int main(int argc, char *argv[]) {
	int rank, world;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &world);

	int i, bpp, remainder, start, end;//, n;
	double a, b, h, procsum, sum, t1, t2;
	long n;

	t1 = MPI_Wtime();

	n = 1000000000;
	a = 1;
	b = 10;
	

	h = (b - a) / n;
	bpp = (n)/world;
	remainder = (n - 1)%world;
	
	if(rank > remainder || remainder == 0) {
		start = remainder + rank * bpp;
		end = start + bpp;
	} else {
		start = rank*(bpp + 1);
		end = start + bpp;
		if(rank < remainder) {
			end++;
		}
	}
	
	for(i = start; i < end; i++) {
		int x = i +1;
		if(x%2 == 0) {
			procsum += f(a + h * x) * 2;
			//printf("%d Yields: %f\n", x, f(a + h * x) * 2);
		} else {
			procsum += f(a + h * x) * 4;
			//printf("%d Yields: %f\n", x, f(a + h * x) * 4);
		}		

	}

	MPI_Reduce(&procsum, &sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	
	if(rank == 0){
		sum += f(a);
		//printf("0 Yields: %f\n", f(a));
		sum += f(b);
		//printf("0 Yields: %f\n", f(b));
		printf("%f\n", (h/3)*sum);
		t2 = MPI_Wtime();
		printf( "Elapsed time is %f\n", t2 - t1 );
	}


	MPI_Finalize();

	return 0;
}



double f(double x) {
	return cos(x);
}
