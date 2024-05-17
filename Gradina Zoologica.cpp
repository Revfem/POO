#include <iostream>
#include <string>

class Pasare{
    protected:
        std::string nume;
        int dimensiune;
    public:
        virtual void display()=0;
        Pasare(std::string nume, int dimensiune): nume(nume), dimensiune(dimensiune){}
        virtual ~Pasare(){}
        int get_dimensiune(){
            return dimensiune;
        }
        std::string get_nume(){
            return nume;
        }
        virtual float suprafata()=0;
};

class Zburatoare: public Pasare{
    private:
        int batai_pe_minut;
    public:
        Zburatoare(std::string nume, int dimensiune, int batai_pe_minut): Pasare(nume, dimensiune), batai_pe_minut(batai_pe_minut){}
        void display(){
            std::cout<<nume<<" "<<dimensiune<<" "<<batai_pe_minut<<std::endl;
        }
        ~Zburatoare(){}
        float suprafata(){
            float S= dimensiune* 110* batai_pe_minut/100;
            return S;
        }
};
class Nezburatoare: public Pasare{
    private:
        std::string culoare;
    public:
        Nezburatoare(std::string nume, int dimensiune, std::string culoare):Pasare(nume,dimensiune), culoare(culoare){}
        void display(){
            std::cout<<nume<<" "<<dimensiune<<" "<<culoare<<std::endl;
        }
        ~Nezburatoare(){}
        float suprafata(){
            float S=dimensiune*30;
            return S;
        }
};


int main(){
    int nr, dimensiune, batai_pe_minut;
    std::cin>>nr;
    Pasare **vector=nullptr;
    vector = new Pasare*[nr];
   
    char c;
    std::string nume, culoare;
    for(int i=0; i<nr; i++){
        std::cin>>c>>nume>>dimensiune;
        if(c=='z'){
            std::cin>>batai_pe_minut;
            vector[i] = new Zburatoare(nume, dimensiune, batai_pe_minut);
        }
        else{
            std::cin>>culoare;
            vector[i] = new Nezburatoare(nume, dimensiune, culoare);
        }
    }
    int test;
    std::cin>>test;
  
    switch(test){
        case 1:{
            for(int i=0; i<nr; i++){
                vector[i]->display();
            }
            break;}
        case 2:{
            std::cin>>c>>dimensiune;
            for(int i=0; i<nr; i++){
                if(c == 'z'){
                    //dynamic casting ( verific ca pasare points  la o  zburatoare )
                    Zburatoare *check = dynamic_cast<Zburatoare*>(vector[i]);
                    if( check!= nullptr && check->get_dimensiune()>=dimensiune){
                        check->display();
                    }
                }
                else{
                    Nezburatoare *check = dynamic_cast<Nezburatoare*>(vector[i]);
                    if( check!= nullptr && check->get_dimensiune()>=dimensiune){
                        check->display();
                    }
                }
            }
            break;}  
        case 3:{
            for(int i=0; i<nr; i++){
                std::cout<<vector[i]->get_nume()<<" "<<vector[i]->suprafata()<<std::endl;
            }
            break;}
        case 4:{
            float suprafete[nr];
            for(int i =0; i<nr; i++){
                suprafete[i] = vector[i]->suprafata();
            }
            for(int i=0; i<nr; i++){
                for(int j=i+1; j<nr; j++){
                    if(suprafete[j]<suprafete[i]){
                        int temp = suprafete[j];
                        suprafete[j]=suprafete[i];
                        suprafete[i]=temp;
                    }
                }
            }
            for(int i=0; i<nr; i++){
                for(int j=0; j<nr; j++){
                    if(suprafete[i] == vector[j]->suprafata()){
                        vector[j]->display();   
                    }
                }
            }
            break;}
        case 5:{
            float Sz =0;
            float Sn=0;
            for(int i=0; i<nr; i++){
                Zburatoare *checkz = dynamic_cast<Zburatoare*>(vector[i]);
                if( checkz!= nullptr ){
                    Sz+= checkz->suprafata();
                }
                Nezburatoare *checkn = dynamic_cast<Nezburatoare*>(vector[i]);
                if( checkn!= nullptr ){
                    Sn+= checkn->suprafata();
                }
            }
            if(Sn>=Sz){
                std::cout<<Sn<<std::endl;
            }
            else{
                std::cout<<Sz<<std::endl;
            }
            break;}
    }
}
