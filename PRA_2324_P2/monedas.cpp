#include<limits>
#include<iostream>
#include<algorithm>

int cambio(int N, int*v, int M){

        int infinito = std::numeric_limits<int>::max();

        int ** matrix = new int*[N];
        
        for(int i = 0; i < N; i++){

                matrix[i] = new int[M+1];
                matrix[i][0] = 0;

        }

        for(int i = 0; i < N ; i++){

                for(int j = 1; j < M+1; j++){

                        if(i == 0 && v[0] > j){

                               return infinito;

                        }else if (i == 0 && v[i] <= j){

                                matrix[i][j] = 1 + matrix[i][j-v[i]];

                        }
                        else if(i > 0 && v[i] > j){

                                matrix[i][j] = matrix[i-1][j];

                        }else{

                                matrix[i][j] = std::min((matrix[i-1][j]), 1 + matrix[i][j-v[i]]);

                        }
                }

         }
                for(int i = 0; i < N; i++){
        
                        for(int j = 0; j < M+1; j++){

                                std::cout<<matrix[i][j]<<" "; 

                        }
                        
                        std::cout<<std::endl;
                }

                //reconstrucción deductiva 

                int resultante[N];

                for(int i = 0; i < N; i++){

                        resultante[i] = 0;

                }

                int i = N-1;
                int j = M;

                while(i >= 0 && j >= 0){

                        if(matrix[i][j] == (1 + matrix[i][j-v[i]])){
                                resultante[i] += 1;
                                j = j - v[i];

                        }else{

                                i--;

                        }
                        
                }

                for(int i = 0; i < N ; i ++){

                        std::cout<<" x: "<<resultante[i];

                }

        
        
        
        return matrix[N-1][M];
}

int main(void){

        int N = 3;
        int M = 8;

        int tipos[] = {1,4,6};

        std::cout<<cambio(N,tipos,M);

return 0;

}

