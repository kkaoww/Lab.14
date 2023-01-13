#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double M[],int N, double T[]){
    for(int i=0; i < N;i++){
        T[0] += M[i];
    }
    T[0] = T[0]/N;
    double mean = T[0] ;
    for(int j = 0; j < N ; j++){
        T[1] += pow((M[j]-mean),2);
    }
    T[1] = sqrt(T[1]/(N));
    for(int k=0;k<N;k++){
        T[2] +=log10 (M[k]);
    }
    T[2] = T[2]/N;
    T[2] = pow(10,T[2]);
    for(int m=0;m<N;m++){
        T[3] += (1/M[m]) ;
    }
    T[3] = N/T[3];
    T[4]=M[0];
    T[5]=M[0];
    for(int n=0;n<N;n++){
        if(M[n]>T[4])T[4]=M[n];
        if(M[n]<T[5])T[5]=M[n];
    }
}
