#include "./zeta.h"
#include <iostream>
using namespace std;
int main(){
    complex test_number;
    test_number.re=0.5;
    complex zeta_val;
    Zeta zeta;
    for (double t=10; t<50.0; t+=0.01 ){
        test_number.im=t;
        zeta.init(test_number);
        zeta.make();
        zeta_val=zeta.get_value();
        cout<<zeta_val.re<<'\t'<<zeta_val.im<<endl;
    }
    return 0;
}