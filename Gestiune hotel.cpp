
#include<iostream>
#include<string>
#include<iomanip>

int get_capacity(std::string tip){
    if(tip =="single"){
        return 1;
    }
    if(tip== "double" || tip =="twin"){
        return 2;
    }
    if(tip=="triple"){
        return 3;
    }
    return 0;
}

class Hotel{
    protected :
        int nr,persoane;
        std::string tip;
        float pret;
    public:
        Hotel(int nr, std::string tip, int persoane, float pret): nr(nr), tip(tip), persoane(persoane), pret(pret){}
        ~Hotel(){}
        void display(){
            std::cout<<nr<<" "<<tip<<" "<<persoane<<" "<<pret<<std::endl;
        }
        int get_persoane(){
            return persoane;
        }
        std::string get_tip(){
            return tip;
        }
        int get_capacity(){
            return ::get_capacity(tip);
        }
        float get_pret(){
            return pret;
        }
};

void sort(Hotel**hotel, int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if((hotel[j]->get_capacity()> hotel[i]->get_capacity()) || (hotel[j]->get_capacity()== hotel[i]->get_capacity() && hotel[j]->get_pret()> hotel[i]->get_pret())){
             Hotel *temp =hotel[i];
             hotel[i]=hotel[j];
             hotel[j]=temp;
            }
        }
    }
}

int main(){
 int comanda;
 Hotel **hotel=new Hotel*[1];
 int capacity=1;
     int size=0;
do {
   
     std::cin >> comanda;
     int nr,persoane;
     float pret;
     std::string tip;
     
     
     
     switch (comanda) {
         case 1: {
             std::cin>>nr>>tip>>persoane>>pret;
             if(capacity == size){
                 capacity *=2;
                 Hotel** new_hotel=new Hotel*[capacity];
                 for(int i=0; i<size; i++){
                     new_hotel[i]= hotel[i];
                 }
                 delete[]hotel;
                 hotel=new_hotel;
             }
             hotel[size++]=new Hotel(nr,tip,persoane,pret);
             break;
         }
         case 2: {
             for(int i=0; i<size; i++){
                 hotel[i]->display();
             }
             break;
         }
        case 3: {
            int aux=0;
             for(int i=0; i<nr; i++){
                 if(hotel[i]->get_persoane()!=0){
                     aux++;
                 }
             }
             float ocupat =100* (double)aux/(double)size;
            //  std::cout<<aux<<" "<<size<<" "<< ocupat<< std::endl;
             std::cout<<std::fixed<<std::setprecision(2)<<ocupat<<std::endl;
             break;
        }
        case 4:{
            int oameni =0;
            for(int i=0; i<size; i++){
                tip =hotel[i]->get_tip();
                if(hotel[i]->get_persoane()==0){
                    if(tip == "single"){
                        oameni++;
                    }
                    else if ( tip =="double" || tip == "twin"){
                        oameni+=2;
                    }
                    else{
                        oameni+=3;
                    }
                }
                
                
            }
            std::cout<<oameni<<std::endl;
            break;
        }
        case 5:{
            sort(hotel,size);
            for(int i=0; i<size; i++){
                hotel[i]->display();
            }
            break;
        }
        
    }
 } while(comanda!=-1);
 return 0;
}
