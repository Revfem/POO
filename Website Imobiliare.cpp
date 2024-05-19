#include<iostream>
#include<string>
#include<iomanip>
class Proprietate{
    protected:
        int pret, suprafata;
        std::string locatie;
        
    public:
        Proprietate(int pret=0, std::string locatie=" ", int suprafata=0): pret(pret), suprafata(suprafata), locatie(locatie){
            std::cin>>this->pret>>this->locatie>>this->suprafata;
        }
        int get_pret(){
            return pret;
        }
        virtual void display()=0;
        virtual float surface()=0;
        virtual float price()=0;
        virtual bool filtreaza(int pret_min, std::string locatie_filtru, int suprafata_min){
           if(pret_min!=0 && pret<pret_min){
               return false;
           }
           if(locatie_filtru !="0" && locatie_filtru!= locatie){
               return false;
           }
           if(suprafata_min!=0 && suprafata < suprafata_min){
               return false;
           }
           return true;
       }
        virtual ~Proprietate(){}
};
class Casa: public Proprietate{
    private:
        int etaje;
    public:
        Casa(int pret=0, std::string locatie=" ", int suprafata=0, int etaje=0):Proprietate(pret,locatie,suprafata), etaje(etaje){
            std::cin>>this->etaje;
        }
         void display(){
            std::cout<<"Casa "<<pret<<" "<<locatie<<" "<<suprafata<<" "<<etaje<<std::endl;
        }
        float surface(){
            return suprafata*etaje;
        }
        float price(){
            return pret/surface();
        }
       bool filtreaza(int pret_min, std::string locatie_filtru, int suprafata_min, int etaje_min=0){
           if(!Proprietate::filtreaza(pret_min,locatie_filtru,suprafata_min)){
               return false;
           }
           if(etaje_min!=0 && etaje<etaje_min){
               return false;
           }
           return true;
       }
        ~Casa(){}
};
class Apartament: public Proprietate{
    private:
        int terasa;
    public:
        Apartament(int pret=0, std::string locatie=" ", int suprafata=0, int terasa=0):Proprietate(pret,locatie,suprafata), terasa(terasa){
            std::cin>>this->terasa;
        }
        void display(){
            std::cout<<"Apartament "<<pret<<" "<<locatie<<" "<<suprafata<<" "<<terasa<<std::endl;
        }
        float surface(){
            return suprafata+terasa;
        }
        float price(){
            return pret/surface();
        }
        bool filtreaza(int pret_min, std::string locatie_filtru, int suprafata_min, int terasa_min=0){
           if(!Proprietate::filtreaza(pret_min,locatie_filtru,suprafata_min)){
               return false;
           }
           if(terasa_min!=0 && terasa<terasa_min){
               return false;
           }
           return true;
       }
        ~Apartament(){}
};

int main(){
    int nr;
    std::cin>>nr;
    Proprietate** vector = nullptr;
    vector = new Proprietate*[nr];
    char c;
    for(int i=0; i<nr; i++){
        std::cin>>c;
        if(c=='c'){
            vector[i]=new Casa();
        }
        else{
            vector[i]=new Apartament();
        }
    }
    int test;
    std::cin>>test;
    switch(test){
        case 1:{
            for(int i=0; i<nr; i++){
                vector[i]->display();
            }
            break;
        }
        case 2:{
            for(int i=0; i<nr; i++){
                std::cout<<vector[i]->surface()<<std::endl;
            }
            break;
        }
        case 3:{
            for(int i=0; i<nr; i++){
                std::cout<<vector[i]->price()<<std::endl;
            }
            break;
        }
        case 4:{
           for(int i=0; i<nr; i++){
               for(int j=i+1;j<nr;j++){
                   if( (vector[i]->price()>vector[j]->price()) || (vector[i]->price()==vector[j]->price() && vector[i]->get_pret()>vector[j]->get_pret())){
                       std::swap(vector[i],vector[j]);
                   }
               }
           } 
           for(int i=0; i<nr; i++){
                   vector[i]->display();
                   std::cout<<std::fixed<<std::setprecision(2)<<vector[i]->price()<<std::endl;
               }
            
            
            break;
        }
        case 5:{
            int pret,suprafata,terasa;
            std::string locatie;
            std::cin>>c>>pret>>locatie>>suprafata>>terasa;
            for(int i=0; i<nr; i++){
                
                if(c =='c') {
                    Casa *check = dynamic_cast<Casa*>(vector[i]);
                    if(check!= nullptr && check->filtreaza(pret,locatie,suprafata,terasa) ){
                        check->display();
                    }
                    
                }
                else{
                    Apartament *check = dynamic_cast<Apartament*>(vector[i]);
                      if(check!= nullptr && check->filtreaza(pret,locatie,suprafata,terasa) ){
                        check->display();
                    }
                }
            }
            break;
        }
    }
    for(int i=0; i<nr; i++){
        delete vector[i];
    }
    return 0;
}
