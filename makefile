serial: serialSimpsons.c
	gcc -o serial.o serialSimpsons.c -lm
runserial:
	./serial.o

mpi: MPISimpsons.c
	mpicc -o mpi.o MPISimpsons.c -lm
runmpi-1:
	mpirun -np 1 mpi.o
runmpi-2:
	mpirun -np 2 mpi.o
runmpi-4:
	mpirun -np 4 mpi.o
runmpi-8:
	mpirun -np 8 mpi.o
omp: OMPSimpsons.c
	gcc -o omp.o -fopenmp OMPSimpsons.c -lm
runomp:
	./omp.o
