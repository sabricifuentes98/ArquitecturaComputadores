#include <stdio.h> 
#include <mpi.h>  


int main (int argc, char* argv []) {

MPI_Status status; 
int value, myrank, size, tag, next, from; 

MPI_Init (&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &myrank); 
MPI_Comm_size(MPI_COMM_WORLD, &size);

/*Tenemos que calcular el rango del siguiente y el anterior, suponiendo un anillo.
Para eso utilizaremos una etiqueta de valor 201*/

tag = 201;
next = (myrank +1) %size; 
from = (myrank + size -1) %size;

//En el proceso 0 preguntamos cuantas vueltas queremos dar 
if (myrank == 0) {
printf("Num de vueltas al anillo\n");
scanf("%d", &value); 

printf ("Proceso %d envia %d a proceso %d\n", myrank, value, next);
MPI_Send(&value, 1, MPI_INT, next, tag, MPI_COMM_WORLD);
}

//Cuando el mensaje llega al proceso 0 se descuenta una vuelta
//Cuando un proceso reciba un cero, lo pasa y termina

do {
MPI_Recv(&value, 1, MPI_INT, from, tag, MPI_COMM_WORLD, &status);
printf("Proceso %d ha recibido %d\n", myrank, value);

if (myrank == 0) {
--value; 
 } if (value >0) {
MPI_Send(&value, 1, MPI_INT, next, tag, MPI_COMM_WORLD);
printf("Proceso %d envia %d al proceso %d\n", myrank, value, next);
 }
} while (value > 0);

printf ("Proceso %d termina %i\n", myrank, value);

MPI_Finalize;
return 0;

}
