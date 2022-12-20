#include <stdlib.h>
#include <stdio.h>
#define HI(num)	(((num) & 0x0000FF00) << 8)
#define LO(num)	((num) & 0x000000FF)


typedef struct _PGMData {
    int row;
    int col;
    int max_gray;
    int **matrix;
} PGMData;

int **allocate_dynamic_matrix(int row, int col){
    int **ret_val;
    int i;
 
    ret_val = (int **)malloc(sizeof(int *) * row);

 
    for (i = 0; i < row; ++i) {
        ret_val[i] = (int *)malloc(sizeof(int) * col);

    }
 
    return ret_val;
}
 
void deallocate_dynamic_matrix(int **matrix, int row)
{
    int i;
 
    for (i = 0; i < row; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}


PGMData* readPGM(const char *file_name, PGMData *data)
{
    FILE *pgmFile;
    char version[3];
    int i, j;
    int lo, hi;
    pgmFile = fopen(file_name, "rb");   
    fscanf(pgmFile, "%d", &data->col);
    fscanf(pgmFile, "%d", &data->row);
    fscanf(pgmFile, "%d", &data->max_gray);
    fgetc(pgmFile);
 
    data->matrix = allocate_dynamic_matrix(data->row, data->col);
    if (data->max_gray > 255) {
        for (i = 0; i < data->row; ++i) {
            for (j = 0; j < data->col; ++j) {
                hi = fgetc(pgmFile);
                lo = fgetc(pgmFile);
                data->matrix[i][j] = (hi << 8) + lo;
            }
        }
    }
    else {
        for (i = 0; i < data->row; ++i) {
            for (j = 0; j < data->col; ++j) {
                lo = fgetc(pgmFile);
                data->matrix[i][j] = lo;
            }
        }
    }
 
    fclose(pgmFile);
    return data;
 
}

 
void writePGM(const char *filename, const PGMData *data){
    FILE *pgmFile;
    int i, j;
    int hi, lo;
 
    pgmFile = fopen(filename, "wb");
    if (pgmFile == NULL) {
        perror("cannot open file to write");
        exit(EXIT_FAILURE);
    }
 
    fprintf(pgmFile, "P5 ");
    fprintf(pgmFile, "%d %d ", data->col, data->row);
    fprintf(pgmFile, "%d ", data->max_gray);
 
    if (data->max_gray > 255) {
        for (i = 0; i < data->row; ++i) {
            for (j = 0; j < data->col; ++j) {
                hi = HI(data->matrix[i][j]);
                lo = LO(data->matrix[i][j]);
                fputc(hi, pgmFile);
                fputc(lo, pgmFile);
            }
 
        }
    }
    else {
        for (i = 0; i < data->row; ++i) {
            for (j = 0; j < data->col; ++j) {
                lo = LO(data->matrix[i][j]);
                fputc(lo, pgmFile);
            }
        }
    }
 
    fclose(pgmFile);
    deallocate_dynamic_matrix(data->matrix, data->row);
}


void save (PGMImage *img){
   FILE *iop;
int row,col;
int nr = (*img).height;
int nc = (*img).width;
   iop = fopen("image1.pgm", "w");
fprintf(iop, "P2\n");
fprintf(iop, "%d %d\n", nc, nr);
fprintf(iop, "255\n");
for (row=0; row < nr; row++){
for (col=0; col< nc; col++)
       {
fprintf(iop,"%d ",(*img).data[row][col]);
       } 
   }
fprintf(iop, "\n");
fclose(iop);
}

int main(){
 
    char nome[100] = "asas.pgm";
    PGMData **matriz;
    readPGM(nome, matriz);

    char novo[100] = "porfavor.pgm";
    writePGM(novo, matriz);


    return 0;
}
