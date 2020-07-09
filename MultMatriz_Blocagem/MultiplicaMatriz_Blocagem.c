#include <stdio.h>
#include <stdlib.h>

#define BLK_FACTOR 32
#define MATRIX_SIZE 128

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

void multMatriz(int** matriz, int** matriz2, int** matFinal){

    // Normal:
    int i, j, k, kk;
    
    for (kk = 0; kk < (MATRIX_SIZE - BLK_FACTOR); kk+=BLK_FACTOR){
        for (i = 0; i < MATRIX_SIZE; i++){
            for (j = 0; j < MATRIX_SIZE; j++){
                for (k = kk; k < (kk + BLK_FACTOR); k++){
                    matFinal[i][j] = matFinal[i][j] + matriz[i][k] * matriz2[k][j];
                }
            }
        }    
    }

    for (int i = 0; i < MATRIX_SIZE; i++){
        for (int j = 0; j < MATRIX_SIZE; j++){
            for (int k = kk; k < MATRIX_SIZE; k++){
                matFinal[i][j] = matFinal[i][j] + matriz[i][k] * matriz2[k][j];
            }
        }
    }

    // Loop Unrolling:
    
    // for (int i = 0; i < MATRIX_SIZE; i++){
    //     for (int j = 0; j < MATRIX_SIZE; j++){
    //         for (int k = 0; k < MATRIX_SIZE; k+=2){
    //             mat[i][j] += matriz[i][k] * matriz2[k][j];
    //             mat[i][j] += matriz[i][k+1] * matriz2[k+1][j];
    //         }
    //     }
    // }
}

int main(){

    ////////////////////////////////////////////////

    int** mat = (int**)malloc(MATRIX_SIZE*sizeof(int*));
    for (int i = 0; i < MATRIX_SIZE; i++)
        mat[i] = (int*)malloc(MATRIX_SIZE*sizeof(int));

    for (int j = 0; j < MATRIX_SIZE; j++){
        for (int i = 0; i < MATRIX_SIZE; i++)
            mat[j][i] = rand() % 10;
    }

    //////////////////////////////////////////////

    int** mat2 = (int**)malloc(MATRIX_SIZE*sizeof(int*));
    for (int i = 0; i < MATRIX_SIZE; i++)
        mat2[i] = (int*)malloc(MATRIX_SIZE*sizeof(int));

    for (int j = 0; j < MATRIX_SIZE; j++){
        for (int i = 0; i < MATRIX_SIZE; i++)
            mat2[j][i] = rand() % 10;
    }

    ///////////////////////////////////////////////

    int** mat3 = (int**)malloc(MATRIX_SIZE*sizeof(int*));
    for (int i = 0; i < MATRIX_SIZE; i++){
        mat3[i] = (int*)malloc(MATRIX_SIZE*sizeof(int));
    }    

    cleanCache();
    multMatriz(mat, mat2, mat3);

    // printf("\nMatriz 3:\n");
    // for (int j = 0; j < MATRIX_SIZE; j++){
    //     for (int i = 0; i < MATRIX_SIZE; i++){
    //         printf("%d ", mat3[j][i]);
    //     }
    //     printf("\n");
    // }

    for (int i = 0; i < MATRIX_SIZE; i++){
        free(mat[i]);
        free(mat2[i]);
        free(mat3[i]);
    }    

    free(mat);
    free(mat2);
    free(mat3);

    return 0;
}