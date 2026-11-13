#include <iostream>
using namespace std;

int main(){
    int n, total =0;

    cout <<"masukan N: ";
    cin>>n;

    for(int i=1; i<=n;i++ ){
        total += i;
    }
    cout<< "Total: " << total;
    return 0;
}