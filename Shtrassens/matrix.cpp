#include "matrix.h"

    int max(int a,int b){
        if (a > b)
            return a;
        else
            return b;
    }

    unsigned int findSize(int size){
        int n = 2;

        while (true){
            if (size <= n){
                return n;
            } else{
                n = 2 * n;
            }
        }
    }

    int ** makeMatrix(unsigned size){
        int **a = new int*[size];
        for (int i = 0; i < size; i++){
            a[i] = new int[size];

            for (int j = 0; j < size; j++){
                a[i][j] = 0;
            }
        }

        return a;
    }

    int ** fillMatrix(unsigned size, int x, int y){
        int **a = new int*[size];
        for (int i = 0; i < size; i++){
            a[i] = new int[size];

            for (int j = 0; j < size; j++){
                a[i][j] = 0;
            }
        }

        for (int i = 0; i < x; i++){
            for (int j = 0; j < y; j++){
                a[i][j] = rand() % 19 - 9;
            }
        }

        return a;
    }

    int ** split(int ** father, int size ,int number){
        int ** son = new int*[size/2];
        for (int i = 0; i < size/2; i++){
            son[i] = new int[size/2];
        }

        switch (number){
            case 1:{
                for (int i = 0; i < size / 2; i++){
                    for (int j = 0; j < size / 2; j++){
                        son[i][j] = father[i][j];
                    }
                }
                break;
            }
            case 2:{
                for (int i = 0; i < size / 2; i++){
                    for (int j = (size / 2); j < size; j++){
                        son[i][j - (size / 2)] = father[i][j];
                    }
                }
                break;
            }
            case 3:{
                for (int i = (size / 2); i < size; i++){
                    for (int j = 0; j < size / 2; j++){
                        son[i - (size / 2)][j] = father[i][j];
                    }
                }
                break;
            }
            case 4:{
                for (int i = (size / 2); i < size; i++){
                    for (int j = (size / 2); j < size; j++){
                        son[i - (size / 2)][j - (size / 2)] = father[i][j];
                    }
                }
                break;
            }
        }

        return son;
    }

    int ** sum(int ** A, int ** B, int size){
        int ** result = makeMatrix(size);

        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++) {
                result[i][j] = A[i][j] + B[i][j];
            }
        }

        return result;
    }

    int ** substruction(int ** A, int ** B, int size){
        int ** result = makeMatrix(size);

        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++) {
                result[i][j] = A[i][j] - B[i][j];
            }
        }

        return result;
    }

    int ** multiplication1(int ** A, int ** B, int size){
        int **result = makeMatrix(size);

        if (size > 64) {

            int ** A_1 = split(A,size,1);
            int ** A_2 = split(A,size,2);
            int ** A_3 = split(A,size,3);
            int ** A_4 = split(A,size,4);

            int ** B_1 = split(B,size,1);
            int ** B_2 = split(B,size,2);
            int ** B_3 = split(B,size,3);
            int ** B_4 = split(B,size,4);

            int **result_1;
            int **result_2;
            int **result_3;
            int **result_4;

            int **P1;
            int **P2;
            int **P3;
            int **P4;
            int **P5;
            int **P6;
            int **P7;

            int **sum_1 = sum(A_1,A_4,size/2);
            int **sum_2 = sum(B_1,B_4,size/2);
            P1 = multiplication1(sum_1,sum_2,size/2);

            sum_1 = sum(A_3, A_4, size/2);
            P2 = multiplication1(sum_1, B_1, size/2);

            sum_1 = substruction(B_2, B_4, size/2);
            P3 = multiplication1(A_1, sum_1, size/2);

            sum_1 = substruction(B_3, B_1, size/2);
            P4 = multiplication1(A_4, sum_1, size/2);

            sum_1 = sum(A_1, A_2, size/2);
            P5 = multiplication1(sum_1, B_4, size/2);

            sum_1 = substruction(A_3, A_1, size/2);
            sum_2 = sum(B_1, B_2, size/2);
            P6 = multiplication1(sum_1, sum_2, size/2);

            sum_1 = substruction(A_2, A_4, size/2);
            sum_2 = sum(B_3, B_4, size/2);
            P7 = multiplication1(sum_1, sum_2, size/2);

            removeArr(A_1,size/2);
            removeArr(A_2,size/2);
            removeArr(A_3,size/2);
            removeArr(A_4,size/2);

            removeArr(B_1,size/2);
            removeArr(B_2,size/2);
            removeArr(B_3,size/2);
            removeArr(B_4,size/2);

            removeArr(sum_1,size/2);
            removeArr(sum_2,size/2);

            //Result__1
            result_1 = sum(P1, P4, size/2);
            result_1 = substruction(result_1, P5, size/2);
            result_1 = sum(result_1, P7, size/2);

            //Result__2
            result_2 = sum(P3, P5, size/2);

            //Result__3
            result_3 = sum(P2, P4, size/2);

            //Result__4
            result_4 = substruction(P1, P2, size/2);
            result_4 = sum(result_4, P3, size/2);
            result_4 = sum(result_4, P6, size/2);

            removeArr(P1,size/2);
            removeArr(P2,size/2);
            removeArr(P3,size/2);
            removeArr(P4,size/2);
            removeArr(P5,size/2);
            removeArr(P6,size/2);
            removeArr(P7,size/2);

            for (int i = 0; i < size / 2; i++) {
                for (int j = 0; j < size / 2; j++) {
                    result[i][j] = result_1[i][j];
                }
            }

            for (int i = 0; i < size / 2; i++) {
                for (int j = (size / 2); j < size; j++) {
                    result[i][j] = result_2[i][j - (size / 2)];
                }
            }

            for (int i = (size / 2); i < size; i++) {
                for (int j = 0; j < (size / 2); j++) {
                    result[i][j] = result_3[i - (size / 2)][j];
                }
            }

            for (int i = (size / 2); i < size; i++) {
                for (int j = (size / 2); j < size; j++) {
                    result[i][j] = result_4[i - (size / 2)][j - (size / 2)];
                }
            }

            removeArr(result_1,size/2);
            removeArr(result_2,size/2);
            removeArr(result_3,size/2);
            removeArr(result_4,size/2);

            return result;
        } else{
            return multiplication3(A,B,size);
        }
    }

    int ** multiplication2(int ** A, int ** B, int size){
        int **result = makeMatrix(size);

        if (size > 64) {

            int ** A_1 = split(A,size,1);
            int ** A_2 = split(A,size,2);
            int ** A_3 = split(A,size,3);
            int ** A_4 = split(A,size,4);

            int ** B_1 = split(B,size,1);
            int ** B_2 = split(B,size,2);
            int ** B_3 = split(B,size,3);
            int ** B_4 = split(B,size,4);

            int **result_1;
            int **result_2;
            int **result_3;
            int **result_4;

            int **P1;
            int **P2;
            int **P3;
            int **P4;
            int **P5;
            int **P6;
            int **P7;

            int **S1;
            int **S2;
            int **S3;
            int **S4;
            int **S5;
            int **S6;
            int **S7;
            int **S8;

            S1 = sum(A_3,A_4,size/2);
            S2 = substruction(S1,A_1,size/2);
            S3 = substruction(A_1,A_3,size/2);
            S4 = substruction(A_2,S2,size/2);
            S5 = substruction(B_2,B_1,size/2);
            S6 = substruction(B_4,S5,size/2);
            S7 = substruction(B_4,B_2,size/2);
            S8 = substruction(S6,B_3,size/2);


            P1 = multiplication2(S2,S6,size/2);
            P2 = multiplication2(A_1,B_1,size/2);
            P3 = multiplication2(A_2,B_3,size/2);
            P4 = multiplication2(S3,S7,size/2);
            P5 = multiplication2(S1,S5,size/2);
            P6 = multiplication2(S4,B_4,size/2);
            P7 = multiplication2(A_4,S8,size/2);

            removeArr(A_1,size/2);
            removeArr(A_2,size/2);
            removeArr(A_3,size/2);
            removeArr(A_4,size/2);

            removeArr(B_1,size/2);
            removeArr(B_2,size/2);
            removeArr(B_3,size/2);
            removeArr(B_4,size/2);

            removeArr(S1,size/2);
            removeArr(S2,size/2);
            removeArr(S3,size/2);
            removeArr(S4,size/2);
            removeArr(S5,size/2);
            removeArr(S6,size/2);
            removeArr(S7,size/2);
            removeArr(S8,size/2);

            int **T1;
            int **T2;

            T1 = sum(P1,P2,size/2);
            T2 = sum(T1,P4,size/2);

            //Result__1
            result_1 = sum(P2,P3,size/2);

            //Result__2
            result_2 = sum(T1,P5,size/2);
            result_2 = sum(result_2,P6,size/2);

            //Result__3
            result_3 = substruction(T2,P7,size/2);

            //Result__4
            result_4 = sum(T2,P5,size/2);

            for (int i = 0; i < size / 2; i++) {
                for (int j = 0; j < size / 2; j++) {
                    result[i][j] = result_1[i][j];
                }
            }

            for (int i = 0; i < size / 2; i++) {
                for (int j = (size / 2); j < size; j++) {
                    result[i][j] = result_2[i][j - (size / 2)];
                }
            }

            for (int i = (size / 2); i < size; i++) {
                for (int j = 0; j < (size / 2); j++) {
                    result[i][j] = result_3[i - (size / 2)][j];
                }
            }

            for (int i = (size / 2); i < size; i++) {
                for (int j = (size / 2); j < size; j++) {
                    result[i][j] = result_4[i - (size / 2)][j - (size / 2)];
                }
            }

            removeArr(P1,size/2);
            removeArr(P2,size/2);
            removeArr(P3,size/2);
            removeArr(P4,size/2);
            removeArr(P5,size/2);
            removeArr(P6,size/2);
            removeArr(P7,size/2);

            removeArr(T1,size/2);
            removeArr(T2,size/2);

            removeArr(result_1,size/2);
            removeArr(result_2,size/2);
            removeArr(result_3,size/2);
            removeArr(result_4,size/2);

            return result;
        } else{
            return multiplication3(A,B,size);
        }
    }

    int ** multiplication3(int ** A, int ** B, int size){
        int **result = makeMatrix(size);

        for (int i = 0; i < size; i++) {
            for (int k = 0; k < size; k++) {
                int sum = 0;
                for (int j = 0; j < size; j++) {
                    sum += A[i][j] * B[j][k];
                }
                result[i][k] = sum;
            }
        }

        return result;
    }

    void removeArr(int **array, int size){
        for (int i = 0; i < size; i++){
            delete[] array[i];
        }

        delete[] array;
    }
