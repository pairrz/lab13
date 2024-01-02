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

void stat(const double a[],int n ,double b[]){
    double sum1 = 0,sum2 = 1,sum3 = 0 , mn = 1e6,mx = 0,sd = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > mx) mx = a[i];
        if(a[i] < mn) mn = a[i];
        sum1 += a[i];
        sum2 *= a[i];
        sum3 += 1/a[i];
    }
    b[0] = sum1 / n;
    for(int i = 0; i < n; i++){
        sd += pow((a[i] - b[0]),2);
    }
    b[1] = sqrt(sd/n);
    b[2] = pow(sum2,1.0/n);
    b[3] = n / sum3;
    b[4] = mx;
    b[5] = mn;
    
}