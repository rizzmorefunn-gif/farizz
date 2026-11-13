#include <iostream>
using namespace std;
int main(){
int hari;

cout << "masukan nomor hari (1-7):";
cin>>hari;


switch(hari){
    case 1:
    cout<<"hari senin";
    break;

    case 2:
    cout<<"hari selasa";
    break;

    case 3:
    cout<<"hari rabu";
    break;

    case 4:
    cout<<"hari kamis";
    break;

    case 5:
    cout<<"hari jumat";
    break;

    case 6:
    cout<<"hari sabtu";
    break;
    
    case 7:
    cout<<"hari minggu";
    break;

    default:
    cout<< "nomor hari tidak valid";
}

return 0;
}
