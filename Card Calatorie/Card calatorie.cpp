#include<string>
#include<iostream>
#include"Card_calatorie.h"
#include"card_autobuz.h"
#include"card_metrou.h"


int main(){
    int nr;
    std::cin>>nr;
    char tip;
    int id,sold, calatorii,moment;
    Card_calatorie **vector = nullptr;
    vector = new Card_calatorie*[nr];
    for(int i =0; i<nr; i++){
        std::cin>>tip>>id;
        if(tip == 'a'){
            std::cin>>calatorii;
            vector[i]= new Card_autobuz(id,tip,calatorii);
        }
        else{
            std::cin>>sold;
            vector[i]=new Card_metrou(id,tip,sold);
        }
    }
  
    int test=0;
    while(test!=5){
        std::cin>>test;
        switch(test){
            case 1:{
                for(int i=0; i<nr; i++){
                    vector[i]->display();
                }
                break;
            }
            case 2:{
                std::cin>>id>>sold;
                for(int i=0; i<nr; i++){
                    if(vector[i]->get_id() == id){
                        vector[i]->incarcare(sold);
                        break;
                    }
                }
                break;
            }
            case 3:{
                
                std::cin>>id>>moment;
                for(int i=0; i<nr; i++){
                    if(vector[i]->get_id()== id){
                        vector[i]->validare_calatorie(moment);
                       
                    } 
                }
                break;
            }
            case 4:{
                int id_transfer;
                std::cin>>id>>id_transfer>>sold;
                for(int i=0; i<nr; i++){
                    if(vector[i]->get_id() == id){
                        for(int j=0; j<nr; j++){
                            if(vector[j]->get_id()==id_transfer){
                                if((vector[j]->get_tip() != vector[i]->get_tip()) || (vector[i]->get_nr() - sold<0)){
                                    std::cout<<"Transfer nereusit"<<std::endl;
                                }
                                else{
                                    vector[i]->incarcare(-sold);
                                    vector[j]->incarcare(sold);
                    
                                }
                            }
                        }
                    }
                }
                break;
            }
        }
    }
    return 0;
}
