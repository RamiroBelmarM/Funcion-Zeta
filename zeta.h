#ifndef __ZETA__
#define __ZETA__
#include <cmath>
typedef struct complex{
    double re;
    double im;
}complex;
class Zeta{
    public:
        Zeta(){
            temp.im=0;
            temp.re=0;
            temp2.im=0;
            temp.re=0;
            zeta_output.re=0;
            zeta_output.im=0;
        }
        Zeta(complex input){
            zeta_input=input;
            temp.im=0;
            temp.re=0;
            temp2.im=0;
            temp.re=0;
            zeta_output.re=0;
            zeta_output.im=0;
        }
        void init(complex input){
            zeta_input=input;
            temp.im=0;
            temp.re=0;
            temp2.im=0;
            temp.re=0;
            zeta_output.re=0;
            zeta_output.im=0;
        }
        void make(){
            make_zeta();
            return;
        }
        complex get_value(){
            return zeta_output;
        }
    private:
        complex zeta_input;
        complex temp;
        complex temp2;
        complex zeta_output;
        int n=5000; //5000 terminos
        void make_zeta(){
            temp=factor(zeta_input);
            temp2=eta_sum(zeta_input);
            zeta_output.im= temp.re*temp2.re-temp.im*temp2.im;
            zeta_output.re= temp.re*temp2.im+temp.im*temp2.re;
            return;
        }
        complex factor(complex input){
            complex out;
            double den=cos(input.im * log(2.0));
            den*=pow(2.0, 1.0-input.re);
            den=1.0-den;
            den*=den;
            double den2=sin(input.im*log(2.0));
            den2*=den2;
            den2*=pow(2.0,2.0-2.0*input.re);
            out.re=(1.0-pow(2.0,1.0-input.re)*cos(input.im*log(2.0)))/(den+den2);
            out.im=-(pow(2.0,1.0-input.re)*sin(input.im*log(2.0)))/(den+den2);
            return out;
        }
        double cast_d(unsigned int i){
            return static_cast<double>(i);
        }
        complex eta_sum(complex input){
            double temp=0.0;
            double temp2=0.0;
            double uno_t=1.0;
            double theta;
            double bottom;
            for (size_t i=1; i<=n; i++){
                theta=input.im*log(cast_d(i));
                bottom=pow(cast_d(i),input.re);
                temp+=(uno_t*cos( theta ))/bottom;
                temp2+=(uno_t*sin( theta ))/bottom;
                uno_t*=(-1.0);
            }
            complex out;
            out.re=temp;
            out.im=-temp2;
            return out;
        }
};
#endif