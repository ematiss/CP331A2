serial: serialSimpsons.c
	gcc -o serial.o serialSimpsons.c
runserial:
	./serial.o

mpi: MPISimpsons.c
	mpicc -o mpi.o MPISimpsons.c
runmpi:
	mpirun -np 8 mpi.o
omp: OMPSimpsons.c
	gcc -o omp.o OMPSimpsons.c
runomp:
	./omp.o
