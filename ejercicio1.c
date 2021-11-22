#include <stdio.h>
#include <mpi.h>

int main (int argc, char* argv []) {

int nproc; //numero de proceso
int total_procesos; //numero total de procesos
double MPI_Wtime();
double start, finish, time;

MPI_Init (&argc, &argv);  //Inicio
MPI_Barrier(MPI_COMM_WORLD);
start = MPI_Wtime(); 
MPI_Comm_size (MPI_COMM_WORLD, &total_procesos);
MPI_Comm_rank (MPI_COMM_WORLD, &nproc);
MPI_Barrier(MPI_COMM_WORLD);
finish = MPI_Wtime(); 

time = finish - start;

printf ("Hola soy el proceso %d de %d\n", nproc, total_procesos); 
printf ("Tiempo de ejecucion del proceso %d es %f\n", nproc, time); 

MPI_Finalize;  //Fin


return 0; 
}
