#include<iostream>
#include<cmath>
using namespace std;

int main(){
    double x1=2 , y1=3, x2=8, y2=11;
    double dx=x2-x1, dy=y2-y1;
    double jarak= sqrt(pow(dx,2)+pow(dy,2));
    cout<< "jarak=" << jarak ;
    return 0;

}