serial: serialSimpsons.c
	gcc -o serial.o serialSimpsons.c
runserial:
	./serial.o

mpi: MPISimpsons.c
	mpicc -o mpi.o MPISimpsons.c
runmpi:
	mpirun -np 8 mpi.o
