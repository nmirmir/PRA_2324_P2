#include <iostream>

int mochila(int M, int *p, int *b, int N){

        int **matrix = new int*[N];

        for(int i = 0; i < N; i++){

                matrix[i] = new int[M];
                matrix[i][0] = 0;

        }

        for(int i = 0; i < N; i++){

                for(int j = 1; j < M ; j++){

                        if()

                }

        }




}


int main(){

        int N = 4;
        int M = 5; // peso máximo
        int p[4] = {1,3,2,4}; // vector de pesos
        int b[4] = {10,20,15,20}; // vector de valores

        std::cout << mochila(M, p, b,N);


return 0;
}
