#include<string>
#include<iostream>
class Angajat{
    protected: 
        std::string nume,functie;
        float salariu,procent_taxe_salariu = 40;
    public:
        Angajat( std::string nume, float salariu, std::string functie):nume(nume), salariu(salariu), functie(functie){}
        // virtual float get_salariu_net(float ) = 0;
            
        // virtual float get_salariu_brut() = 0;
        std::string get_nume(){
            return this->nume;
        }
        std::string get_functie(){
            return this->functie;
        }
        float get_salariu(){
            return this->salariu;
        }
        void marire_salariu(float marire){
           float s = salariu *(100+marire)/100;
           this->salariu= s;
        }
        void display(){
            std::cout<<nume<<std::endl;
            std::cout<<functie<<std::endl;
        }
         virtual float brut()=0;
         virtual float net()=0;
         virtual ~Angajat(){
             std::cout<<"Destructor Angajat"<<std::endl;
         }
             
         
    
    
};
class Analist: public Angajat {
    public:
        Analist(std::string nume,float salariu, std::string functie): Angajat(nume, salariu, functie){}
        float brut(){
            float brut = this->salariu;
            return brut;
        }
        float net(){
            float net = brut() * (100 - procent_taxe_salariu)/100;
            return net;
        }
        void marire_salariu(float){
            
        }
        ~Analist(){std::cout<<"Destructor Analist"<<std::endl;}
        
        
};
class Programator: public Analist{
    protected:
        float procent_deducere_salariu_it=10;
    public:
        Programator(std::string nume,float salariu, std::string functie): Analist(nume, salariu, functie){}
        float brut(){
            float brut = this->salariu;
            return brut;
        }
        float net(){
            float net = brut() * (100+procent_deducere_salariu_it- procent_taxe_salariu)/100;
            return net;
        }
        ~Programator(){
            std::cout<<"Destructor Programator"<<std::endl;
            
        }
        
};
class LiderEchipaProgramare: public Programator{
    protected:
        float bonus_vechime_functie=500;
        int vechime_functie;
    public:
        LiderEchipaProgramare(std::string nume,float salariu, std::string functie,int vechime_functie ): Programator(nume, salariu, functie), vechime_functie(vechime_functie){}
        float brut(){
            float brut =(salariu )+ (vechime_functie * bonus_vechime_functie);
            return brut;
        }
        float net(){
            float net = brut() * (100+procent_deducere_salariu_it- procent_taxe_salariu)/100;
            return net;
        }
        ~LiderEchipaProgramare(){
            std::cout<<"Destructor LiderEchipaProgramare"<<std::endl;
            
        }
};      




class FirmaProgramare{
  private: Angajat **vector;
        int nr;
  public:
    FirmaProgramare(Angajat **vector, int nr):vector(vector), nr(nr){}
    void afiseaza_angajati(){
    for(int i=0; i<nr; i++){
        vector[i]->display();
    }
    }
     
    void mareste_salarii(float a, float p, float l){
     for(int i=0; i<nr; i++){
         std::string f = vector[i]->get_functie();
         if( f=="Analist"){
            std::cout<<vector[i]->get_nume()<<std::endl;
            std::cout<<"Salariu de baza vechi: "<<vector[i]->get_salariu()<<std::endl;
             vector[i]->marire_salariu(a);
            std::cout<<"Salariu de baza nou: "<<vector[i]->get_salariu()<<std::endl;
         }
         else if(f == "Programator"){
            std::cout<<vector[i]->get_nume()<<std::endl;
            std::cout<<"Salariu de baza vechi: "<<vector[i]->get_salariu()<<std::endl;
             vector[i]->marire_salariu(p);
            std::cout<<"Salariu de baza nou: "<<vector[i]->get_salariu()<<std::endl;
         }
         else{
            std::cout<<vector[i]->get_nume()<<std::endl;
            std::cout<<"Salariu de baza vechi: "<<vector[i]->get_salariu()<<std::endl;
             vector[i]->marire_salariu(l);
            std::cout<<"Salariu de baza nou: "<<vector[i]->get_salariu()<<std::endl;
         }
     }
    }
    void promoveaza(std::string functie_t,std::string nume_t){
          for(int i=0; i<nr; i++){
                if(vector[i]->get_nume() == nume_t){
              
                    float salariu_t= vector[i]->get_salariu();
                    delete vector[i];
                    if(functie_t == "Analist" ){
                        vector[i]=new Analist(nume_t, salariu_t,functie_t);
                    }
                    else if(functie_t == "Programator"){
                        vector[i]= new Programator(nume_t,salariu_t,functie_t);
                    }
                    else{
                        vector[i]=new LiderEchipaProgramare(nume_t,salariu_t,functie_t,0);
                    }
                    
                    break;
                }
            }
    }
    void Calcularea_Salariilor(){
        for(int i=0; i<nr; i++){
            std::cout<<vector[i]->get_nume()<<std::endl;
            std::cout<<"Salariu brut: "<<vector[i]->brut()<<std::endl;
            std::cout<<"Salariu Net: "<<vector[i]->net()<<std::endl;
        }
    }
};


int main(){
    int nr;
    std::cin>>nr;
    std::cin.ignore();
    Angajat **vector = nullptr;
    vector = new Angajat*[nr];
    std::string nume_t, functie_t;
    int vechime_t;
    float salariu_t;
   
    for(int i=0; i<nr; i++){
        getline(std::cin, nume_t);
        getline(std::cin,functie_t);
        std::cin>>salariu_t;
        if(functie_t == "LiderEchipaProgramare"){
            
            std::cin>>vechime_t;
            
            vector[i]= new LiderEchipaProgramare(nume_t, salariu_t, functie_t, vechime_t );
        }
        else if(functie_t == "Analist"){
            vector[i] = new Analist(nume_t,salariu_t,functie_t);
        }
        else{
            vector[i]= new Programator(nume_t,salariu_t,functie_t);
        }
        std::cin.ignore();
       
    }
    int test;
    std::cin>>test;
    FirmaProgramare p(vector,nr);
    
    switch(test){
        case 1:{
            p.afiseaza_angajati();
            break;
        }
        case 2:{
           
            p.Calcularea_Salariilor();
            break;
        }case 3:{
            float marire_a, marire_p, marire_l;
            for(int i=0; i<3; i++){
                std::cin>>functie_t;
                if( functie_t == "Analist"){
                    std::cin>>marire_a;
                }
                else if(functie_t =="Programator"){
                    std::cin>>marire_p;
                }
                else{
                    std::cin>>marire_l;
                }
            }
            
            p.mareste_salarii(marire_a,marire_p,marire_l);
            break;
        }case 4:{
            std::cin.ignore();
            getline(std::cin, nume_t);
            // std::cout<<nume_t<<std::endl;
            std::cin>>functie_t;
            p.promoveaza(functie_t, nume_t);
            p.afiseaza_angajati();
            break;
        }
    }
    return 0;
}
