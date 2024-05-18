#include<iostream>
#include <string>
class ProbaSportiva{
    protected:
        std::string nume;
    public:
        ProbaSportiva(std::string nume=" "): nume(nume){}
        virtual void display()=0;
        virtual ~ProbaSportiva(){}
        std::string get_nume(){
            return nume;
        }
        virtual void mediu()=0;
        virtual void record(float)=0;
        virtual void clasament()=0;
        virtual void runda2(std::string)=0;
    
};
class Participant{
     protected:
        std::string nume;
        float rezultat;
    public:
        void display(){
            std::cout<<nume<<" "<<rezultat<<std::endl;
        }
        Participant(std::string nume=" ", float rezultat=0): nume(nume), rezultat(rezultat){
            std::cin>>this->nume;
            std::cin>>this->rezultat;
        }
        std::string get_nume(){
            return nume;
        }
        float get_rezultat(){
            return rezultat;
        }
        ~Participant(){}
        
       
};
class ProbaTimp: public ProbaSportiva{
   protected:
        Participant **participant;
        int nr;
   public:
        ProbaTimp(std::string nume=" ",Participant **participant=nullptr,int nr=0):ProbaSportiva(nume), participant(participant), nr(nr){}
        void display(){
            std::cout<<nume<<std::endl;
            for(int i=0; i<nr; i++){
                std::cout<<participant[i]->get_nume()<<" "<<participant[i]->get_rezultat()<<std::endl;
            }
        }
         void mediu(){
            std::cout<<"Rezultat mediu la "<<nume<<": ";
            float value=0;
            for(int i=0; i<nr; i++){
                value+= participant[i]->get_rezultat();
            }
            std::cout<<value/nr<<std::endl;
        }
        void record(float max){
            
            for(int i=0; i<nr; i++){
                if(participant[i]->get_rezultat()<max){
                    // std::cout<<participant[i]->get_rezultat()<<" "<<max<<std::endl;
                    std::cout<<"Un nou record mondial la "<<nume<<"!"<<std::endl;
                    break;
                }
            }
        }
        void clasament(){
            float rezultate[nr];
            for(int i=0; i<nr; i++){
                rezultate[i]= participant[i]->get_rezultat();
            }
           
            for(int i=0; i<nr; i++){
                for(int j=0; j<nr; j++){
                    if(rezultate[j]>rezultate[i]){
                        float temp = rezultate[j];
                       rezultate[j]= rezultate[i];
                       rezultate[i]=temp;
                        
                    }
                }
            }
            for(int i=0; i<nr; i++){
                for(int j=0; j<nr; j++){
                    if(rezultate[i]==participant[j]->get_rezultat()){
                        participant[j]->display();
                    }
                }
            }
        }
        void runda2(std::string nume){
            float rezultate[nr];
            for(int i=0; i<nr; i++){
                rezultate[i]= 2*participant[i]->get_rezultat();
            }
            for(int i=0; i<nr; i++){
                for(int j=0; j<nr; j++){
                    if(rezultate[j]>rezultate[i]){
                        float temp = rezultate[j];
                       rezultate[j]= rezultate[i];
                       rezultate[i]=temp;
                        
                    }
                }
            }
            float val;
            for(int i=0; i<nr ; i++){
                if(participant[i]->get_nume()==nume){
                    val = participant[i]->get_rezultat();
                }
            }
            std::cout<<nume<<" "<< rezultate[0]-val<<std::endl;
        }
        ~ProbaTimp(){}
        
};
class ProbaScor: public ProbaSportiva{
    protected:
        Participant **participant;
        int nr;
    public:
        ProbaScor(std::string nume = "",Participant **participant=nullptr, int nr=0):ProbaSportiva(nume),participant(participant), nr(nr){}
        void display(){
            std::cout<<nume<<std::endl;
            for(int i=0; i<nr; i++){
                std::cout<<participant[i]->get_nume()<<" "<<participant[i]->get_rezultat()<<std::endl;
            }
        }
        void mediu(){
            std::cout<<"Rezultat mediu la "<<nume<<": ";
            float value=0;
            for(int i=0; i<nr; i++){
                value+= participant[i]->get_rezultat();
            }
            std::cout<<value/nr<<std::endl;
        }
         void record(float max){
            for(int i=0; i<nr; i++){
                if(participant[i]->get_rezultat()>max){
                    std::cout<<"Un nou record mondial la "<<nume<<"!"<<std::endl;
                    break;
                }
            }
        }
         void clasament(){
            float rezultate[nr];
            for(int i=0; i<nr; i++){
                rezultate[i]= participant[i]->get_rezultat();
            }
           
            for(int i=0; i<nr; i++){
                for(int j=0; j<nr; j++){
                    if(rezultate[j]<rezultate[i]){
                        float temp = rezultate[j];
                       rezultate[j]= rezultate[i];
                       rezultate[i]=temp;
                        
                    }
                }
            }
            for(int i=0; i<nr; i++){
                for(int j=0; j<nr; j++){
                    if(rezultate[i]==participant[j]->get_rezultat()){
                        participant[j]->display();
                    }
                }
            }
        }
        void runda2(std::string nume){
            float rezultate[nr];
            for(int i=0; i<nr; i++){
                rezultate[i]= 2*participant[i]->get_rezultat();
            }
            for(int i=0; i<nr; i++){
                for(int j=0; j<nr; j++){
                    if(rezultate[j]<rezultate[i]){
                        float temp = rezultate[j];
                       rezultate[j]= rezultate[i];
                       rezultate[i]=temp;
                        
                    }
                }
            }
            float val;
            for(int i=0; i<nr ; i++){
                if(participant[i]->get_nume()==nume){
                    val = participant[i]->get_rezultat();
                }
            }
            std::cout<<nume<<" "<< rezultate[0]-val<<std::endl;
        }
        ~ProbaScor(){}
};
int main(){
    int nr,p;
    char c;
    std::string nume;
    float rezultat;
    std::cin>>nr;
    ProbaSportiva **proba= nullptr;
    Participant **participanti=nullptr;
    proba = new ProbaSportiva*[nr];
    for(int i=0; i<nr; i++){
        std::cin>>c>>nume>>p;
        participanti=new Participant*[p];
        if(c=='s'){
            for(int j=0; j<p; j++){
                participanti[j] = new Participant();
            }
            proba[i] = new ProbaScor(nume,participanti,p);
        }
        else {
            for(int j=0; j<p; j++){
                participanti[j] = new Participant();
            }
            proba[i] = new ProbaTimp(nume,participanti,p);
        }
    }
    int test;
    std::cin>>test;
    switch(test){
        case 1:{
            for(int i=0; i<nr; i++){
                proba[i]->display();
            }
            break;
        }
        case 2:{
            std::string aux = proba[0]->get_nume();
            for(int i=0; i<nr; i++){
                    proba[i]->mediu();
            }
            break;
        }
        case 3:{
            float max;
            for(int i=0; i<nr; i++){
                std::cin>>max;
                proba[i]->record(max);
            }
            break;
        }
        case 4:{
            std::cin>>nume;
            for(int i=0; i<nr; i++){
                if(nume == proba[i]->get_nume()){
                    proba[i]->clasament();
                }
            }
            break;
        }
        case 5:{
            std::string sport;
            std::cin>>sport>>nume;
            for(int i=0; i<nr; i++){
                if(proba[i]->get_nume()==sport){
                    proba[i]->runda2(nume);
                    
                }
            }
            break;
        }
    }
       
    
    return 0;
}
