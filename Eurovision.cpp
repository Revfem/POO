#include <iostream>
#include <string>


class Participant{
    private:
        std::string nume, piesa;
        int punctaj;
        std::string voturi[4];
    public:
        ~Participant(){}
        Participant(std::string nume ="", std::string piesa = "", int punctaj = 0): nume(nume), piesa(piesa), punctaj(punctaj){
            for(int i =0; i<4; i++){
                voturi[i]=" ";
            }
        }
        void display(){
            std::cout<<nume<<" "<<piesa<<" "<<punctaj<<std::endl;
        }
        void set_voturi(){
            for(int i=0; i<4; i++){
                std::cin>>voturi[i];
            }
        }
        std::string get_voturi(int nr){
            return voturi[nr];
        }
        std::string get_nume(){
            return nume;
        }
        void set_punctaj( int nr){
            punctaj += nr;
        }
        int get_punctaj(){
            return punctaj;
        }
};
class Eurovision{
    private:
        Participant **vector;
        int capacity, size;
    public:
        Eurovision(int capacity =1): capacity(capacity), size(0){
            vector = new Participant*[capacity];
        }
        ~Eurovision(){
            for(int i=0; i<size; i++){
                delete vector[i];
            }
            delete []vector;
        }
        void adauga_participant(std::string nume, std::string piesa){
            if(capacity == size){
                    capacity *=2;
                    Participant** new_vector = new Participant*[capacity];
                    for(int i=0; i<size; i++){
                        new_vector[i]=vector[i];
                    }
                    delete []vector;
                    vector = new_vector;
            }
         vector[size++] = new  Participant(nume, piesa);
        }
        void afisare(){
            for(int i=0; i<size; i++){
                vector[i]->display();
            }
        }
        void adaugare_voturi(){
            for(int i=0; i< size; i++){
                vector[i]->set_voturi();
            }
            for(int i=0; i<size; i++){
                    for(int k=0; k<size; k++){
                        if( vector[k]->get_nume()==vector[i]->get_voturi(0)){
                            vector[k]->set_punctaj(7);
                        }
                        if( vector[k]->get_nume()==vector[i]->get_voturi(1)){
                            vector[k]->set_punctaj(5);
                        }
                        if( vector[k]->get_nume()==vector[i]->get_voturi(2)){
                            vector[k]->set_punctaj(3);
                        }
                        if( vector[k]->get_nume()==vector[i]->get_voturi(3)){
                            vector[k]->set_punctaj(1);
                        }
                    }
                }
        }
        void popular(){
            int aux = 0;
            int nr=0;
            std::string temp;
            for( int i=0; i<size; i++){
                for(int k =0; k<size; k++){
                    for(int j =0; j<4; j++){
                        if( vector[i]->get_nume()==vector[k]->get_voturi(j)){
                            nr++;
                        }
                    }
                }
                if(nr>aux){
                    aux=nr;
                    temp=vector[i]->get_nume();
                }
                nr=0;
            }
            for(int i=0; i<size; i++){
                if(vector[i]->get_nume()==temp){
                    vector[i]->display();
                }
            }
    }
    int comp(int i){
        int nr =0;
        for ( int k=0; k<size; k++){
            if(vector[i]->get_nume() == vector[k]->get_voturi(0)){
                nr++;
            }
        }
        return nr;
    }
    void clasament(){
        int temp =0;
        int punctaje[size];
        for(int i=0; i<size; i++){
            punctaje[i] = vector[i]->get_punctaj();
        }
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                if(punctaje[i]>punctaje[j]){
                    temp = punctaje[i];
                    punctaje[i]=punctaje[j];
                    punctaje[j]=temp;
                }
        
            }
        }
        //  for(int i=0; i<size; i++){
        //     std::cout<<punctaje[i]<<" ";
        // }
        for(int i=0; i<size; i++){
            for(int j=0; j<size;j++){
                if(punctaje[i] == vector[j]->get_punctaj() ){
                    if(punctaje[i] == punctaje[i+1]){
                        std::string nume1 = vector[j]->get_nume();
                        // std::string nume2;
                        int n;
                        for(int k=0; k<size; k++){
                            if( punctaje[i]==vector[k]->get_punctaj() && nume1 != vector[k]->get_nume()){
                                // nume2 = vector[k]->get_nume();
                                n=k;
                            }
                        }
                        if(comp(n)>comp(j)){
                            vector[n]->display();
                        }
                        else{
                            vector[j]->display();
                        }
                         i++;
                        // std::cout<<nume1<<" "<<nume2<<std::endl;
                    }
                    else{
                      vector[j]->display();  
                    }
                    
                }
                
            }
         
        }
       
    }
};
int main(){
    int test;
    Eurovision eurovision;
   
    do{
        std::string nume, piesa;
        std::cin>>test;
        switch (test){
            case 1:{
                std::cin>>nume>>piesa;
                eurovision.adauga_participant(nume,piesa);
                std::cin.ignore();
                break;
            }
            case 2:{
                eurovision.afisare();
                break;
            }
            case 3:{
                eurovision.adaugare_voturi();
                break;
            }
            case 4:{
                eurovision.popular();
                break;
            }
            case 5:{
                eurovision.clasament();
                break;
            }
        }
        
        
    } while(test!=6);
    return 0;
}
