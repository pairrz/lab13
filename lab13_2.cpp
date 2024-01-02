#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void updateImage(bool img[N][M],int s,int x , int y){
    for(int i = 0; i<70; i++){
        for(int j = 0; j<70; j++){
            if(sqrt(pow(x-i,2) + pow(y-j,2)) <= s-1) img[i][j] = 1;
        }
    }
}

void showImage(const bool img[N][M]){
    cout <<"------------------------------------------------------------------------\n";
    for(int i = 0; i<30; i++){
        for(int j = 0; j<70; j++){
            if(j == 0) cout << "|";
            if(img[i][j] == 0)cout << " ";
            else cout << "*";
            if(j == 69) cout << "|";
        }
        cout << endl;
    }
    cout <<"------------------------------------------------------------------------\n";
}