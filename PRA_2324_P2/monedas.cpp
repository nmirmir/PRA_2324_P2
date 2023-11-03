#include<limits>
#include<iostream>
#include<algorithm>


int cambio(int N, int*v, int M){

        int infinito = std::numeric_limits<int>::max();

        // definimos la matriz y además la rellenamos de -1's

        int ** matrix = new int*[N];
        
        for(int i = 0, j = 0; i < N; i++){

                matrix[i][j] = 0;

        }


        for(int i = 0; i < N ; i++){

                matrix[i] = new int[M];

                for(int j = 0; j < M; j++){

                        if(i == 1 && v[i] > j){

                               matrix[i][j] = infinito;

                        }else if (i == 1 && v[i] <= j){

                                matrix[i][j] = 1 + matrix[i][j-v[i]];

                        }
                        if(i > 1 && v[i] > j){

                                matrix[i][j] = matrix[i-1][j];

                        }else{

                               matrix[i][j] = std::min((matrix[i-1][j]), 1 + matrix[i][M-j]);

                        }

                }

        }

        
        return matrix[N][M];


}

int main(void){

        int N = 3;
        int M = 9;

        int tipos[] = {1,4,6};

        std::cout<<cambio(N,tipos,M);



return 0;

}

