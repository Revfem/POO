#include<iostream>
#include<string>
#include<cmath>
class Jucarie{
    protected: std::string tematica, nume;
    public:
        void afisare(){
            std::cout<<tematica<<std::endl;
            std::cout<<nume<<std::endl;
        }
        Jucarie( std::string tematica=" ", std::string nume=" "):nume(nume), tematica(tematica){
            std::cin>>this->tematica;
            std::cin>>this->nume;
        }
        virtual void display()=0;
        std::string get_tematica(){
           return this->tematica; 
        }
        int virtual varsta_minima()=0;
        virtual void display_varsta()=0;
};
class Action_figure: public Jucarie{
    private: int inaltime, latime, lungime;
    public: 
        Action_figure(std::string tematica=" ", std::string nume= " ", int inaltime=0, int latime=0, int lungime=0): Jucarie(tematica,nume), inaltime(inaltime),latime(latime),lungime(lungime) {
            std::cin>>this->inaltime>>this->latime>>this->lungime;
        }
        void display(){
            std::cout<<"Action_figure "<<tematica<<" "<<nume<<" "<<inaltime<<" "<< latime<<" "<<lungime<<std::endl;
        }
        int varsta_minima(){
            int dimensiune;
            if(inaltime<=latime){
                if(inaltime<=lungime){
                    dimensiune= inaltime;
                }
                else{
                    dimensiune=lungime;
                }
            }
            else if(latime<=lungime){
                dimensiune=latime;
            }
            else{
                dimensiune=lungime;
            }
            int varsta= 10/dimensiune;
            return varsta;
        }
        void display_varsta(){
            std::cout<<"Action_figure "<<nume<<" "<<varsta_minima()<<std::endl;
        }
        
};
class Puzzle : public Jucarie{
    private: int nr_piese, latime, lungime;
    public:
       Puzzle(std::string tematica=" ", std::string nume= " ", int nr_piese=0, int latime=0, int lungime=0): Jucarie(tematica,nume), nr_piese(nr_piese),latime(latime),lungime(lungime) {
            std::cin>>this->nr_piese>>this->latime>>this->lungime;
       }
       void display(){
           std::cout<<"Puzzle "<<tematica<<" "<<nume<<" "<<nr_piese<<" "<< latime<<" "<<lungime<<std::endl;
       }
       int varsta_minima(){
            float dimensiune;
            float p_latime = latime/sqrt(nr_piese);
            float p_lungime = lungime/sqrt(nr_piese);
            if(p_latime<=p_lungime){
                dimensiune=p_latime;
            }
            else{
                dimensiune=p_lungime;
            }
            int varsta= 10/dimensiune;
            return varsta;
            
        }
        void display_varsta(){
            std::cout<<"Puzzle "<<nume<<" "<<varsta_minima()<<std::endl;
        }
};


int main(){
    int n;
    std::cin>>n;
    char temp_c;
    Jucarie **jucarie = new Jucarie*[n];
    for(int i=0; i <n; i++){
        std::cin>>temp_c;
        if( temp_c == 'a'){
            jucarie[i] = new Action_figure();
        }
        else if(temp_c == 'p'){
            jucarie[i]= new Puzzle();
        }
        else{
            std::cout<<"INVALID"<<std::endl;
        }
    }
    int test;
    std::cin>>test;
    switch(test){
        case 1 :{
            for(int i=0; i<n; i++){
               jucarie[i]->display();
            }
           
            break;
        }
        case 2 :{
            std::string tematica;
            std::cin>>tematica;
            for(int i=0; i<n; i++){
                if(jucarie[i]->get_tematica()==tematica){
                    jucarie[i]->display();
                }
            }
            break;
        }
        case 3: {
            for(int i=0; i<n; i++){
                jucarie[i]->display_varsta();
            }
            break;
        }
        case 4 : {
            int varste[n];
            for(int i=0; i<n; i++){
                varste[i]=jucarie[i]->varsta_minima();
            }
         
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(varste[i]<varste[j]){
                        int temp= varste[j];
                        varste[j]=varste[i];
                        varste[i]=temp;
                    }
                }
            }
         
            for(int i=0; i<n; i++){
                for(int j=0; j<n ; j++){
                    if(varste[i]==jucarie[j]->varsta_minima()){
                        jucarie[j]->display();
                    }
                }
            }
            break;
        }
    }
    return 0;
    }
