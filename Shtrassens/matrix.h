#ifndef MATRIX_H
#define MATRIX_H

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <QDebug>

    int max(int a,int b);
    unsigned int findSize(int size);    //return power of 2 : 64,128,256,512,1024...
    int **makeMatrix(unsigned size);
    int **fillMatrix(unsigned size,int x, int y);
    int **split(int ** father, int size ,int number);
    int **sum(int ** A, int ** B, int size);
    int **substruction(int ** A, int ** B, int size);
    int **multiplication1(int ** A, int ** B, int size);
    int **multiplication2(int ** A, int ** B, int size);
    int **multiplication3(int ** A, int ** B, int size);
    void removeArr(int **array, int size);


#endif // MATRIX_H
