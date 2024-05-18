#include<iostream>
#include<string>
#include "Angajat.h"
#include "Salariat.h"
#include "Colaborator.h"

int main(){
    int nr;
    std::cin>>nr;
    Angajat** vector= nullptr;
    vector = new Angajat*[nr];
    std::string tip,nume,departament;
    int norma,vechime;
    float salariu_net,onorariu,nr_prestari_anuale;
    for(int i=0; i<nr; i++){
        std::cin>>tip>>nume>>departament;
        if(tip=="salariat"){
            std::cin>>norma>>vechime>>salariu_net;
            vector[i]=new Salariat(nume,departament,norma,vechime,salariu_net);
        }
        else{
            std::cin>>onorariu>>nr_prestari_anuale;
            vector[i]=new Colaborator(nume,departament,onorariu,nr_prestari_anuale); 
        }
    }
    int test;
    std::cin>>test;
    switch(test){
        case 1:{
            std::cin>>departament;
            for(int i=0; i<nr; i++){
                if(departament==vector[i]->get_departament()){
                    vector[i]->afisare();
                }
                
            }
            break;
        }
        case 2:{
            std::cin>>nume;
            for(int i=0; i<nr; i++){
                if(vector[i]->get_nume()==nume){
                   std::cout<<std::fixed<<std::setprecision(2)<<vector[i]->brut()<<std::endl; 
                }
            }
            break;
        }
        case 3:{
            float aux=1;
            float val;
            for(int i=0; i<nr; i++){
                Salariat *check = dynamic_cast<Salariat*>(vector[i]);
                if(check!=nullptr){
                    val =check->rentabilitate_angajat();
                    if(val<aux){
                        aux=val;
                    }
                }
            }
            for(int i=0; i<nr; i++){
                Salariat *check = dynamic_cast<Salariat*>(vector[i]);
                if(check!=nullptr){
                   if(check->rentabilitate_angajat()==val){
                       std::cout<<check->get_nume();
                   }
                }
            }
            break;
        }
        case 4:{
            float brut =0;
            int aux =0;
            std::cin>>departament;
            for(int i=0; i<nr; i++){
              
                if((vector[i]->get_departament())==departament){
                    
                    brut+= vector[i]->brut();
                    aux++;
                }
            }
            std::cout<<brut/aux<<std::endl;
            break;
        }
    }
    
}   
