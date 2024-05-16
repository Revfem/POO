#ifndef CARD_AUTOBUZ_H
#define CARD_AUTOBUZ_H

#include "Card_calatorie.h"
#include<iostream>
#include<string>

class Card_autobuz: public Card_calatorie{
    private:
        int sold, moment_validare=0;
    public:
        Card_autobuz(int id, char tip, int sold):Card_calatorie(id,tip), sold(sold){}
        void display(){
            std::cout<<get_id()<<" "<<get_tip()<<" "<<sold<<" "<<moment_validare<<std::endl;
        }
        void incarcare(int sold){
            this->sold +=sold; 
        }
        void validare_calatorie(int moment){
            if(sold-3 < 0 ){
                std::cout<<"Sold insuficient"<<std::endl;
            }
            else if(moment-moment_validare>=90){
                this->sold-=3;
                this->moment_validare=moment;
            }
        }
        int get_nr(){
            return this->sold;
        }
};

#endif
