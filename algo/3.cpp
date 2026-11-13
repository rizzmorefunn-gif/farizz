#include <iostream>
using namespace std;

int main(){
    int n;
    int i=1;
    int total=0;
    cout<<"masukan N:";
    cin >>n;
    while (i<=n){
        total+=i;
        i++;
    }
    cout << "total="<<total;
    return 0;

}