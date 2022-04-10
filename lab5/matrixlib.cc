#include "matrixlib.hh"

bool matEqual(int A[][N], int B[][N]){
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(A[i][j] != B[i][j])  return 0;
        }
    }

    return 1;

    // TODO: Fill your code here.
   
}

void matAdd(int A[][N], int B[][N], int C[][N]){
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    // TODO: Fill your code here.
    
}

void matSub(int A[][N], int B[][N], int C[][N]){
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    // TODO: Fill your code here.
    
}

void matMul(int A[][N], int B[][N], int C[][N]){
    

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            C[i][j] = 0;
            for(int k=0;k<N;k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }           
        }
    }

    // TODO: Fill your code here.   
}

void transpose(int A[][N], int A_T[][N]){
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            A_T[i][j] = A[j][i];
    }

    // TODO: FiLL your code here
    
}

std::string matrixToString(int A[][N]){
    std::string str;

    for(int i=0;i<N;i++)
    {
        str = str + '{';
        for(int j=0;j<N;j++)
        {
            if(j == N-1)    str = str + std::to_string(A[i][j]);
            else            str = str + std::to_string(A[i][j]) + ',';
        }
        if(i == N-1)        str = str + '}' + '\n';
        else                str = str + '}' + ',' + '\n';
    }
    return str;
    //TODO: Fill your code here
    //Hint: Use function std::to_string 
}
