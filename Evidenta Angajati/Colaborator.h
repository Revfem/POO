#ifndef COLABORATOR_H
#define COLABORATOR_H
#include "Angajat.h"
#include<iomanip>

class Colaborator: public Angajat{
private:
    float onorariu, nr_prestari_anuale;
public:
    Colaborator(std::string nume, std::string departament, float onorariu, float nr):Angajat(nume,departament), onorariu(onorariu), nr_prestari_anuale(nr){}
    void afisare(){
        std::cout<<get_nume()<<" "<<onorariu<<" "<<nr_prestari_anuale<<std::endl;
    }
    float brut(){
        float brut=  onorariu*nr_prestari_anuale;
          if(get_departament()=="IT"){
            brut /=(1-0.35);
        }
        else{
            brut /=(1-0.45);
        }
       return brut;
    }
    float rentabilitate_angajat(){
        
        return 0;
    }
    ~Colaborator(){}
};

#endif
