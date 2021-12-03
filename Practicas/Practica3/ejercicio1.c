#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <string.h>
	
int main(int argc, char **argv)
	{
	    int size, rank, value;
	    
	    MPI_Status status;
	    MPI_Init(&argc, &argv);
	    
	    MPI_Comm_size(MPI_COMM_WORLD, &size);
	    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	    
	    int num = rand() % 100; //Elegir un numero random
	    int cuadrado = num * num; //Calcular su cuadrado
	
	    if (rank == 0)
	    {
	        printf("--Comunicación punto a punto--\n");
	        for (int i = 1; i < size; i++) {
	        MPI_Send(&cuadrado, 1, MPI_INT, i , 0, MPI_COMM_WORLD);
	        }
	        printf("Proceso 0 ha calculado el cuadrado de %d = %d y enviado al resto de nodos\n", num, cuadrado);
	        
	        printf("--Comunicación colectiva--\n");
	        MPI_Bcast(&cuadrado, 1 , MPI_INT, 0, MPI_COMM_WORLD);
	        printf("Proceso 0 ha calculado el cuadrado de %d = %d y enviado al resto de nodos\n", num, cuadrado);
	    }
	    
	    MPI_Finalize();
	    
	}
