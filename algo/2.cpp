#include <iostream>
#include <string>
using namespace std;

int main(){
    string password;
    cout<<"masukan password:";
    cin>>password;
    while(password != "informatika123"){
        cout<< "password salah"<<endl;
        cout<<"masukan password lagi:";
        cin>>password;

    }
    cout<<"login berhasil";
    return 0;
}