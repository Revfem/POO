#ifndef CARD_CALATORIE_H
#define CARD_CALATORIE_H

class Card_calatorie{
private:
    int id;
    char tip;
public:
    Card_calatorie(int id, char tip): id(id), tip(tip){}
    virtual void validare_calatorie(int)=0;
    virtual void incarcare(int)=0;
    virtual void display()=0;

    int get_id(){
        return this->id;
    }
    char get_tip(){
        return this->tip;
    }
    virtual int get_nr()=0;
};

#endif
