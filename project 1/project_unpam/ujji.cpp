#include <iostream>
using namespace std;

int main(){
    int nilai, hasil;

    cout<<"Masukan nilai  :";
    cin>> nilai;

    if (nilai <0||nilai>100){
        cout<<"nilai tidak valid"
        
    }else{

    switch(nilai/10){
        case 10:
        case 9:
        cout<< "NILAI = A";
        break;

        case 8:
        cout<< "NILAI = B";
        break;

        case 7:
        cout<< "NILAI = C";
        break;

        case 6:
        cout<< "NILAI = D";
        break;

    
    default:
    cout<<"NILAI = F";
 }
 }
    
return 0;    
}