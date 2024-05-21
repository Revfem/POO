#ifndef SALARIAT_H
#define SALARIAT_H
#include "Angajat.h"
#include<iomanip>

class Salariat: public Angajat{
private:
    int norma, vechime;
    float salariu_net;
public:
    Salariat(std::string nume, std::string departament, int norma, int vechime, float salariu):Angajat(nume,departament), norma(norma), vechime(vechime), salariu_net(salariu){}
    void afisare(){
        std::cout<<get_nume()<<" "<<norma<<" "<<vechime<<" "<<salariu_net<<std::endl;
    }
    
    float brut(){
        float brut=salariu_net*12;
        if(get_departament()=="IT"){
            brut /=(1-0.35);
        }
        else{
            brut /=(1-0.45);
        }
        return brut;
    }
    float rentabilitate_angajat(){
        
        int zile_extra=vechime/3;
        float br= brut();
        float rent = norma*(250+zile_extra)/br;
        return rent;
    }
    ~Salariat(){}
};

#endif
