# Funcion-Zeta
Función Zeta de Riemann programado en c++

![Alt text](https://raw.githubusercontent.com/RamiroBelmarM/Funcion-Zeta/main/zeta_test.png)

```cpp
#include "zeta.h"
int main(){
    //numero de prueba
    complex test_number;
    test_number.re=0.5;
    
    //donde se guardará el resultado de la función
    complex zeta_val;
    
    //Se crea objeto Zeta
    //5000 terminos a calcular
    Zeta zeta;
    
    for (double t=10; t<50.0; t+=0.01 ){
        test_number.im=t;
        
        //valor de zeta a calcular
        zeta.init(test_number);
        
        //se inicia el cálculo
        zeta.make();
        
        //se obtiene el resultado
        zeta_val=zeta.get_value();
        
        //imprime en pantalla
        cout<<zeta_val.re<<'\t'<<zeta_val.im<<endl;
    }
    return 0;
}
```