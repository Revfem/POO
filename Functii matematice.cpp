#include<string>
#include<iostream>
#include<cmath>
#include<iomanip>

class MathFunction{
    protected: std::string function_name;
    public:
        MathFunction(std::string f):function_name(f){}
        int get_value(float a){
            return a;
        }
        float get_max_value(int a, int b){
            float c=0;
            return c;
        }
        virtual void display()=0;
        std::string get_name(){
            return this->function_name;
        }
        virtual void radacina()=0;
        virtual void maxim(int, int)=0;
        virtual float calculeaza(int)=0;
       
    
};
class Polynomial : public MathFunction{
    protected: int nr ;
               float *coeficients = new float[nr] ;
    public:
        Polynomial(std::string nume, int nr, float *coef): MathFunction(nume), nr(nr), coeficients(coef){}
        void display(){
           
            std::cout<<"f(x) = ";
            if(coeficients[0]>0){
                std::cout<<coeficients[0];
            }
            else if(coeficients[0]<0){
                std::cout<<coeficients[0];
            }
            if(coeficients[1]>0){
                std::cout<<" + "<<coeficients[1]<<"x";
            }
            else if(coeficients[1]<0){
                std::cout<<" - "<<abs(coeficients[1])<<"x";
            }
            for(int i=2; i<nr; i++){
                if(coeficients[i]>0 && coeficients[i]!=1){
                    std::cout<<" + "<<coeficients[i]<<"x^"<<i;
                }
                else if(coeficients[i]<0 && coeficients[i]!= -1){
                    std::cout<<" - "<<abs(coeficients[i])<<"x^"<<i;
                }
                else if(coeficients[i]==1){
                    std::cout<<" + "<<"x^"<<i;
                }
                else if(coeficients[i]== -1){
                    std::cout<<" - "<<"x^"<<i;
                }
                
            }
            std::cout<<std::endl;
        }
        void radacina(){}
        void maxim(int a, int b){
            float value;
            float aux=-99999;
            for(int i= a; i<=b; i++){
                for(int j=0; j<nr; j++){
                    value +=coeficients[j]*pow(i,j);
                    // std::cout<<coeficients[j]<<std::endl;
                    // std::cout<<value<<std::endl;
                }
                if( value>aux){
                    aux=value;
                }
                value=0;
            }
            std::cout<<std::fixed<<std::setprecision(2)<<aux<<std::endl;
            
        }
        float calculeaza(int a){
            float value=0;
            // std::cout<<"x= "<<a<<" Values: ";
            for(int i=0; i<nr; i++){
                value+=coeficients[i]*pow(a,i);
                // std::cout<<coeficients[i]*pow(a,i)<<" ";
            }
            // std::cout<<"Value finala: "<< value<<std::endl;
            // std::cout<<std::endl;
            return value;
        }
        
    
};
class Quadratic: public Polynomial{
    
    public:
        Quadratic(std::string nume, float *coef):Polynomial(nume,3,coef){}
        void print_roots(){
            
        }
        void display(){
         
            std::cout<<"f(x) = ";
            if(coeficients[0]>0){
                std::cout<<coeficients[0];
            }
            else if(coeficients[0]<0){
                std::cout<<coeficients[0];
            }
            if(coeficients[1]>0){
                std::cout<<" + "<<coeficients[1]<<"x";
            }
            else if(coeficients[1]<0){
                std::cout<<" - "<<abs(coeficients[1])<<"x";
            }
            if(coeficients[2]>0){
                std::cout<<" + "<<coeficients[2]<<"x^"<<2;
            }
            else if(coeficients[2]<0){
                std::cout<<" - "<<abs(coeficients[2])<<"x^"<<2;
            }
            std::cout<<std::endl;
        }
        void radacina(){
            float delta = (coeficients[1]*coeficients[1] )- 4*coeficients[0]*coeficients[2];
            // std::cout<<delta<<std::endl;
            float x1 = (-coeficients[1] + sqrt(delta))/(2*coeficients[2]);
            float x2 = (-coeficients[1] - sqrt(delta))/(2*coeficients[2]);
            if(x1!=x2){
                std::cout<<"X1 = "<<std::fixed<<std::setprecision(2)<<x1<<std::endl;
                std::cout<<"X2 = "<<std::fixed<<std::setprecision(2)<<x2<<std::endl;
            }
            else{
                std::cout<<"X1 = X2 = "<<std::fixed<<std::setprecision(2)<<x1<<std::endl;
            }
        }
            void maxim(int a, int b){
            float value;
            float aux=0;
            for(int i= a; i<=b; i++){
               value+= coeficients[0]+ coeficients[1]*i +coeficients[2]*i*i;
               if(value>aux){
                   aux=value;
               }
               value=0;
            }
            std::cout<<std::fixed<<std::setprecision(2)<<aux<<std::endl;
            
        }
        float calculeaza(int a){
            float value= coeficients[0]+ coeficients[1]*a + coeficients[2]*a*a;
            return value;
        }
        
};
    class Exponential:public MathFunction{
        private:
            const float e = 2.71;
            float constant;
            float exp_coeff;
        public:
            Exponential(std::string nume, float constant, float exp_coeff): MathFunction(nume), constant(constant), exp_coeff(exp_coeff){}
            void display(){
               
                std::cout<<"f(x) = ";
                if(constant<0){
                    std::cout<<" - "<<constant;
                }
                else if(constant>0){
                    std::cout<<constant;
                }
                if(exp_coeff <0){
                    std::cout<<" - "<<exp_coeff<<"e^x";
                }
                else if(exp_coeff>0){
                    std::cout<<" + "<<exp_coeff<<"e^x";
                }
                std::cout<<std::endl;
            }
            void radacina(){}
            void maxim(int a, int b){
            float value;
            float aux=-99999;
            for(int i= a; i<=b; i++){
               value+=constant + exp_coeff*pow(e,i);
               if(value>aux){
                   aux=value;
               }
               value=0;
            }
            std::cout<<std::fixed<<std::setprecision(2)<<aux<<std::endl;
            
        }
        float calculeaza(int a){
            float value =constant + exp_coeff*pow(e,a);
            return value;
        }
    };
    class DiscreteFunction:public  MathFunction {
        private:    float *x_values = new float[3];
                    float *y_values = new float[3];
                    MathFunction **vector;
                    int nr;
        public:
            DiscreteFunction(std::string nume,float *x, float *y, MathFunction **vector, int nr ):MathFunction(nume), x_values(x), y_values(y), vector(vector), nr(nr){}
            void find_best_aproximation(){
                float aux =99999999;
                int n;
                for(int i=0; i<nr; i++){
                    float value1= vector[i]->calculeaza(x_values[0]);
                    float value2=vector[i]->calculeaza(x_values[1]);
                    float value3= vector[i]->calculeaza(x_values[2]);
                    float V = abs(value1-y_values[0]) + abs(value2 - y_values[1]) + abs(value3-y_values[2]);
                    // std::cout<<value1<< " "<<value2<<" "<<value3<<std::endl;
                    // std::cout<<V<<std::endl;
                    if(V< aux){
                        aux=V;
                        n=i;
                    }
                    V=0;
                }
                vector[n]->display();
                std::cout<<aux<<std::endl;
              
            }
            void display(){
            }
            void maxim(int a, int b){}
            
            float calculeaza(int a){ return 3;}
            void radacina(){}
            
    };


int main(){
    int nr;
    std::cin>>nr;
    MathFunction **vector = nullptr;
    vector = new MathFunction*[nr];
    std::string nume;
    int nr_termeni;
    float coeficienti;
    float constant;
    for(int i=0; i<nr; i++){
        std::cin>>nume;
        if(nume == "Polynomial"){
            std::cin>>nr_termeni;
            float *coeficients= new float[nr_termeni];
            for(int j=0; j<nr_termeni; j++){
                std::cin>>coeficients[j];
            }
            vector[i]= new Polynomial(nume,nr_termeni, coeficients);
        }
        else if(nume == "Quadratic"){
            float *coeficients = new float[3];
            for(int j=0; j<3;j++){
                std::cin>>coeficients[j];
            }
            vector[i]= new Quadratic(nume,coeficients);
        }
        else{
            std::cin>>constant>>coeficienti;
            vector[i]= new Exponential(nume,constant, coeficienti);
            
        }
    }
   
    int test;
    std::cin>>test;
  
    switch(test){
        case 1:{
            
            for(int i=0; i<nr; i++){
                std::cout<<vector[i]->get_name()<<std::endl;
                vector[i]->display();
            }
            break;
        }
        case 2:{
            for(int i=0; i<nr; i++){
                if( vector[i]->get_name() == "Quadratic"){
                    vector[i]->radacina();
                }
            }
            break;
        }
        case 3:{
            int lim_jos, lim_sus;
            std::cin>>lim_jos>>lim_sus;
            for(int i =0; i<nr; i++){
                vector[i]->maxim(lim_jos, lim_sus);
            }
            break;
        }
        case 4:{
            float x_values[3], y_values[3];
            for(int i=0; i<3; i++){
                std::cin>>x_values[i];
            }
            for(int i=0; i<3; i++){
                std::cin>>y_values[i];
            }
            DiscreteFunction d("Discrete_function",x_values, y_values, vector, nr);
            d.find_best_aproximation();
        }
        
    }
    
    return 0;
}
