#ifndef CARD_METROU_H
#define CARD_METROU_H

#include "Card_calatorie.h"
#include<iostream>
#include<string>

class Card_metrou: public Card_calatorie{
    private: int calatorii, moment_validare =0;
    public:
        Card_metrou(int id, char tip, int calatorii):Card_calatorie(id,tip), calatorii(calatorii){}
        void display(){
            std::cout<<get_id()<<" "<<get_tip()<<" "<<calatorii<<" "<<moment_validare<<std::endl;
        }
        void incarcare(int calatorii){
            this->calatorii += calatorii;
        }
        void validare_calatorie(int moment){
            if((calatorii-1)<0){
                std::cout<<"Numar calatorii insuficient"<<std::endl;
            }
            else if(moment-moment_validare>=90){
                this->calatorii -=1;
                this->moment_validare= moment;
            }
        }
        int get_nr(){
            return this->calatorii;
        }
        
};

#endif
