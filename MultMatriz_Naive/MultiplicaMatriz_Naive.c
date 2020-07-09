#include <stdio.h>
#include <stdlib.h>

#define KB (1024)
#define MB (1024 * KB)
#define GB (1024 * MB)
#define LARGEST_CACHE_SZ (8 * MB)

static unsigned char dummy_buffer[LARGEST_CACHE_SZ];

void cleanCache(){
	unsigned long long i;

	for(i = 0; i < LARGEST_CACHE_SZ; i++){
		dummy_buffer[i] += 1;
	}
}

void multMatriz(int** matriz, int** matriz2, int** matFinal, int M){

    // Normal:
    
    for (int i = 0; i < M; i++){
        for (int j = 0; j < M; j++){
            for (int k = 0; k < M; k++){
                matFinal[i][j] = matFinal[i][j] + matriz[i][k] * matriz2[k][j];
            }
        }
    }

    // Loop Unrolling:
    
    // for (int i = 0; i < M; i++){
    //     for (int j = 0; j < M; j++){
    //         for (int k = 0; k < M; k+=2){
    //             matFinal[i][j] += matriz[i][k] * matriz2[k][j];
    //             matFinal[i][j] += matriz[i][k+1] * matriz2[k+1][j];
    //         }
    //     }
    // }

}

int main(){
    int M;
    printf("tamanho da matriz: ");
    scanf("%d", &M);

    ////////////////////////////////////////////////

    int** mat = (int**)malloc(M*sizeof(int*));

    for (int i = 0; i < M; i++)
        mat[i] = (int*)malloc(M*sizeof(int));

    for (int j = 0; j < M; j++){
        for (int i = 0; i < M; i++) 
            mat[j][i] = rand() % 10;
    }

    //////////////////////////////////////////////

    int** mat2 = (int**)malloc(M*sizeof(int*));
    for (int i = 0; i < M; i++)
        mat2[i] = (int*)malloc(M*sizeof(int));

    for (int j = 0; j < M; j++){
        for (int i = 0; i < M; i++) 
            mat2[j][i] = rand() % 10;
    }

    ///////////////////////////////////////////////

    int** mat3 = (int**)malloc(M*sizeof(int*));
    for (int i = 0; i < M; i++)
        mat3[i] = (int*)malloc(M*sizeof(int)); 

    cleanCache();
    multMatriz(mat, mat2, mat3, M);

    // printf("\nMatriz 3:\n");
    // for (int j = 0; j < M; j++){
    //     for (int i = 0; i < M; i++){
    //         printf("%d ", mat3[j][i]);
    //     }
    //     printf("\n");
    // }

    for (int i = 0; i < M; i++){
        free(mat[i]);
        free(mat2[i]);
        free(mat3[i]);
    }    

    free(mat);
    free(mat2);
    free(mat3);

    return 0;
}