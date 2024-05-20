#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
class Automobil{
    protected:
        std::string nume;
        int capacitate, viteza;
    public:
        Automobil(std::string nume, int capacitate, int viteza):nume(nume), capacitate(capacitate), viteza(viteza){}
        virtual ~Automobil(){}
        std::string get_nume(){
            return nume;
        }
        int get_capacitate(){
            return capacitate;
        }
        int get_viteza(){
            return viteza;
        }
        void display(){
            std::cout<<nume<<std::endl;
            std::cout<<capacitate<<std::endl;
            std::cout<<viteza<<std::endl;
        }
        float poluare(int persoane){
                float poluare =0;
                if( persoane>capacitate){
                    int aux = persoane / capacitate;
                    int rest = persoane%capacitate;
                  
                    for(int j=0; j<aux; j++){
                        poluare += calc_poluare(capacitate);
                    }
                    if(rest!=0){
                         poluare +=calc_poluare(rest);
                    }
                }
                else{
                    poluare +=calc_poluare(persoane);
                }
                
            return poluare;
        }
        virtual float calc_poluare(int nr_pasageri)=0;
};
class Masina: public Automobil{
    protected:
        
    public:
        Masina(std::string nume, int capacitate, int viteza):Automobil(nume,capacitate,viteza){}
        float calc_poluare(int nr_pasageri){
            
            float poluare = ((double)viteza/100) + (double)nr_pasageri/(double)capacitate;
            return poluare;
        }
};
class Autocar: public Automobil{
    protected:
        
    public:
         Autocar(std::string nume, int capacitate, int viteza):Automobil(nume,capacitate,viteza){}
         float calc_poluare(int nr_pasageri){
            float poluare = (double)viteza/20 + pow(2.71,(2*(double)nr_pasageri/(double)capacitate));
            return poluare;
        }
};

class FirmaInchirieri{
    private:
        Automobil **vector;
        int nr;
    public:
        FirmaInchirieri(Automobil **vector, int nr) : vector(vector), nr(nr){}
        ~FirmaInchirieri(){}
        void display(){
            for(int i=0;i <nr; i++){
                vector[i]->display();
            }
        }
        void grup(int persoane){
            for(int i=0; i<nr; i++){
                float aux = persoane / vector[i]->get_capacitate();
                std::cout<<vector[i]->get_nume()<<std::endl;
                if( persoane %vector[i]->get_capacitate() == 0) {
                    std::cout<<aux<<std::endl;
                }
                else{
                    std::cout<<aux+1<<std::endl;
                }
                
            }
        }
        void drum(float lungime, int ore){
            for(int i =0; i<nr; i++){
                float durata = lungime/vector[i]->get_viteza();
                if(durata<ore){
                    std::cout<<vector[i]->get_nume()<<std::endl;
                    std::cout<<std::fixed<<std::setprecision(2)<<durata<<std::endl;
                }
            }
        }
       
        void poluare(int persoane){
            float pol[nr];
            for(int i=0; i<nr; i++){
                pol[i] = vector[i]->poluare(persoane);
            }
            for(int i =0; i<nr; i++){
                for(int j =i+1; j<nr; j++){
                    if(pol[i] > pol[j]){
                        float temp = pol[j];
                        pol[j]=pol[i];
                        pol[i]=temp;
                    }
                }
            }
            for( int i=0; i<nr; i++){
                for(int j=0; j<nr; j++){
                    if(pol[i]== vector[j]->poluare(persoane)){
                        std::cout<<vector[j]->get_nume()<<std::endl;
                    }
                }
            }
        }
};

int main(){
    int test, nr,capacitate,viteza;
    std::cin>>test>>nr;
    std::string tip,nume;
    Automobil **vector = nullptr;
    vector= new Automobil*[nr];
    for(int i=0; i<nr; i++){
        std::cin>>tip;
        std::cin.ignore();
        getline(std::cin,nume);
        std::cin>>capacitate>>viteza;
        if(tip =="Autocar"){
            vector[i] =  new Autocar (nume,capacitate,viteza);
        }
        else{
            vector[i] = new Masina(nume, capacitate,viteza);
        }
    }
    FirmaInchirieri firma(vector,nr);
    switch(test){
        case 1:{
            firma.display();
            break;
        }
        case 2:{
            int persoane;
            std::cin>>persoane;
            firma.grup(persoane);
            break;
        }
        case 3:{
            int lungime, timp;
            std::cin>>lungime>>timp;
            firma.drum(lungime,timp);
            break;
        }
        case 4:{
            int persoane;
            std::cin>>persoane;
            firma.poluare(persoane);
            break;
        }
    }
    return 0;
}
