#include <iostream>
#include<string>

class Angajat{
    protected:
        std::string nume,tip;
        float salariu;
        int concediu;
    public:
    Angajat(std::string nume,std::string tip, float salariu, int concediu):nume(nume), tip(tip), salariu(salariu), concediu(concediu){}
    virtual ~Angajat(){}
    void display(){
        std::cout<<tip<<std::endl;
        std::cout<<nume<<":"<<salariu<<std::endl;
        std::cout<<std::endl;
    }
    std::string get_nume(){
        return nume;
    }
    float get_salariu(){
        return salariu;
    }
    std::string get_tip(){
        return tip;
    }
    virtual int salariu_brut()=0;
    virtual int salariu_net()=0;
    
};
class PersoanaFizica: public Angajat{
    private:
        int ore;
    public:
        PersoanaFizica(std::string nume,std::string tip, float salariu, int concediu,int ore): Angajat(nume,tip, salariu, concediu), ore(ore){}
        ~PersoanaFizica(){}
        int salariu_brut(){
            // std::cout<<"zile: "<<zile<<std::endl;
            return (salariu)/(ore*4);
        }
        int salariu_net(){
            float net= salariu*0.58;
            return net;
        }
        
    
};
class PersoanaJuridica : public Angajat{
    private:
        int zile;
    public:
        PersoanaJuridica(std::string nume, std::string tip, float salariu, int concediu, int zile): Angajat(nume,tip, salariu, concediu), zile(zile){}
        ~PersoanaJuridica(){}
        int salariu_brut(){
          
            return (salariu)/(zile*32);
        }
        int salariu_net(){
            float net= salariu*0.9;
            return net;
        }
        
};
class AdministrareAngajat{
    private:
        Angajat **vector;
        int nr;
    public:
        AdministrareAngajat(Angajat **vector, int nr): vector(vector), nr(nr){}
        void display(){
            for (int i=0; i<nr; i++){
                vector[i]->display();
            }
        }
        void salariu_brut(){
            for(int i=0; i<nr; i++){
                std::cout<<vector[i]->get_nume()<<":"<<vector[i]->salariu_brut()<<" lei/h"<<std::endl;
            }
            
        }
        void salariu_net(){
            for(int i=0; i<nr; i++){
                std::cout<<vector[i]->get_nume()<<":"<<vector[i]->get_salariu()<<"-"<<vector[i]->salariu_net()<<std::endl;
            }
        }
        void ordonare(){
            int net[nr];
            for(int i=0; i<nr; i++){
                net[i]=vector[i]->salariu_net();
            }
            for(int i=0; i<nr; i++){
                for(int j =0;j<nr; j++){
                    if(net[j]<net[i]){
                        int temp = net[j];
                        net[j]=net[i];
                        net[i]=temp;
                    }
                }
            }
            for(int i=0; i<nr; i++){
                for(int j=0; j<nr; j++){
                    if(net[i]==vector[j]->salariu_net() && vector[j]->get_tip() == "Persoana fizica"){
                        std::cout<<vector[j]->get_nume()<<":"<<vector[j]->get_salariu()<<std::endl;
                    }
                }
            }
            for(int i=0; i<nr; i++){
                for(int j=0; j<nr; j++){
                    if(net[i]==vector[j]->salariu_net() && vector[j]->get_tip() == "Persoana juridica"){
                        std::cout<<vector[j]->get_nume()<<":"<<vector[j]->get_salariu()<<std::endl;
                    }
                }
            }
        }
};

int main(){
    int test, nr, concediu, ore_zile;
    std::cin>>test>>nr;
    std::cin.ignore();
    Angajat **vector = nullptr;
    vector = new Angajat*[nr];
    std::string nume, tip;
    float salariu;
    for(int i=0; i<nr; i++){
        getline(std::cin, tip);
        getline(std::cin, nume);
        std::cin>>salariu>>concediu>>ore_zile;
        std::cin.ignore();
        if(tip == "Persoana fizica"){
            vector[i] = new PersoanaFizica(nume,tip, salariu, concediu, ore_zile);
        }
        else {
            vector[i] = new PersoanaJuridica(nume,tip, salariu, concediu, ore_zile);
        }
    }
    AdministrareAngajat a(vector, nr);
    
    switch(test){
        case 1:{
            a.display();
            break;
        }
        case 2:{
            a.salariu_brut();
            break;
        }
        case 3:{
            a.salariu_net();
            break;
        }
        case 4:{
            a.ordonare();
            break;
        }
    }
    return 0;
}
