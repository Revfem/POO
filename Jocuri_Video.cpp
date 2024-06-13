#include<iostream>
#include<string>
#include<iomanip>
class JocuriVideo{
    protected:
        std::string nume;
        int data[3];
        int nr_note;
        int *note;
        std::string indicator;
        
    public: 
    JocuriVideo(std::string nume, int *data, int nr_note, int *note, std::string indicator): nume(nume), nr_note(nr_note), indicator(indicator){
        for(int i=0; i<3;i++){
            this->data[i]=data[i];
        }
        this->note = new int[nr_note];
        for(int i=0; i<nr_note;i++){
            this->note[i]=note[i];
        }
    }
    float nota_totala(){
        float a=0;
        for(int i=0; i<nr_note; i++){
            a+=note[i];
        }
        a/=(float)nr_note;
        return a;
    }
    int get_data(int nr){
        return data[nr];
    }
    void display_nota(float aux){
        std::cout<<nume<<": "<<std::fixed<<std::setprecision(2)<<aux<<std::endl;
    }
    void display_filtru(){
        std::cout<<nume<<": "<<indicator<<std::endl;
    }
    virtual void display()=0;
    virtual void get_playtime(int a, float b)= 0;
    ~JocuriVideo(){}
    
};
class JocSinglePlayer: public JocuriVideo{
    private:
        int nivele;
    public:
        JocSinglePlayer(std::string nume, int *data, int nr_note, int *note, std::string indicator, int nivele): JocuriVideo(nume,data,nr_note,note,indicator), nivele(nivele){}
        ~JocSinglePlayer(){}
        void display(){
            std::cout<<"singleplayer: "<<nume<<" - "<<data[0]<<" "<<data[1]<<" "<<data[2]<<" - "<<nivele<<std::endl;
        }
        void get_playtime(int jucatori, float timp){
            float playtime = nivele*jucatori*timp;
            std::cout<<nume<<": "<<std::fixed<<std::setprecision(2)<<playtime<<std::endl;
        }
};
class JocMultiPlayer : public JocuriVideo{
    private:
        int meciuri;
    public:
        ~JocMultiPlayer(){}
        JocMultiPlayer(std::string nume, int *data, int nr_note, int *note, std::string indicator, int meciuri): JocuriVideo(nume,data,nr_note,note,indicator), meciuri(meciuri){}
        void display(){
            std::cout<<"multiplayer: "<<nume<<" - "<<data[0]<<" "<<data[1]<<" "<<data[2]<<" - "<<meciuri<<std::endl;
        }
        void get_playtime(int jucatori, float timp){
            float playtime = (meciuri*timp/jucatori);
            std::cout<<nume<<": "<<std::fixed<<std::setprecision(2)<<playtime<<std::endl;
        }
};
class JocVideoHandler{
    private:
        JocuriVideo **vector;
        int nr;
    public:
        JocVideoHandler( JocuriVideo **vector, int nr): vector(vector), nr(nr){}
        ~JocVideoHandler(){
          for(int i=0; i<nr;i++){
              delete vector[i];
          }  
          delete [] vector;
        }
        void display(){
            for(int i=0; i<nr; i++){
                vector[i]->display();
            }
        }
        void nota(){
            float aux=0;
            for(int i=0; i<nr; i++){
                if(vector[i]->nota_totala()>aux){
                    aux=vector[i]->nota_totala();
                }
            }
            for(int i=0; i<nr; i++){
                if(vector[i]->nota_totala()==aux){
                 
                vector[i]->display_nota(aux);
                }
            }
        }
        void filtrare(int new_data[3]){
            for(int i=0; i<nr; i++){
                if(vector[i]->get_data(2)> new_data[2]){
                    vector[i]->display_filtru();
                }
                else if (vector[i]->get_data(2)== new_data[2]){
                    if(vector[i]->get_data(1)> new_data[1]){
                         vector[i]->display_filtru();
                    }
                    else if(vector[i]->get_data(1)== new_data[1]){
                        if(vector[i]->get_data(0)>new_data[0]){
                            vector[i]->display_filtru();
                        }
                    }
                }
            }
        }
        void nou(){
            int aux[3]={0,0,0};
            for(int i=0; i<nr; i++){
                if(vector[i]->get_data(2)>aux[2]){
                    aux[2] = vector[i]->get_data(2);
                }
            }
            for(int i=0; i<nr; i++){
                if(vector[i]->get_data(2)==aux[2]){
                    if(vector[i]->get_data(1)>aux[1]){
                        aux[1]=vector[i]->get_data(1);
                    }
                }
            }
             for(int i=0; i<nr; i++){
                if(vector[i]->get_data(2)==aux[2]){
                    if(vector[i]->get_data(1)==aux[1]){
                        if(vector[i]->get_data(0)>aux[0]){
                        aux[0]=vector[i]->get_data(0);
                        }
                    }
                }
            }
            for(int i=0; i<nr; i++){
                if(aux[0] == vector[i]->get_data(0) && aux[1] == vector[i]->get_data(1) && aux[2] == vector[i]->get_data(2) ){
                    vector[i]->display();
                }
            }
        }
        void vechi(){
            int aux[3]={99,99,9999};
            for(int i=0; i<nr; i++){
                if(vector[i]->get_data(2)<aux[2]){
                    aux[2] = vector[i]->get_data(2);
                }
            }
            for(int i=0; i<nr; i++){
                if(vector[i]->get_data(2)==aux[2]){
                    if(vector[i]->get_data(1)<aux[1]){
                        aux[1]=vector[i]->get_data(1);
                    }
                }
            }
             for(int i=0; i<nr; i++){
                if(vector[i]->get_data(2)==aux[2]){
                    if(vector[i]->get_data(1)==aux[1]){
                        if(vector[i]->get_data(0)<aux[0]){
                        aux[0]=vector[i]->get_data(0);
                        }
                    }
                }
            }
            
            for(int i=0; i<nr; i++){
                if(aux[0] == vector[i]->get_data(0) && aux[1] == vector[i]->get_data(1) && aux[2] == vector[i]->get_data(2) ){
                    vector[i]->display();
                }
            }
        }
        void calcul_timp(int jucatori, float timp){
            for(int i=0; i<nr; i++){
                vector[i]->get_playtime(jucatori, timp);
            }
        }
    
};

int main(){
    int nr;
    std::cin>>nr;
    JocuriVideo **vector = nullptr;
    vector = new JocuriVideo*[nr];
    for(int i=0; i <nr; i++){
        std::string nume,indicator;
        int data[3];
        int nr_note, nivele_meciuri;
        std::cin.ignore();
        std::getline(std::cin, nume);
        for(int i=0; i<3; i++){
            std::cin>>data[i];
        }
        std::cin>>nr_note;
        int note[nr_note];
         for(int i=0; i<nr_note; i++){
            std::cin>>note[i];
        }
        std::cin>>indicator>>nivele_meciuri;

        if(indicator=="singleplayer"){
            vector[i]= new JocSinglePlayer(nume,data,nr_note,note,indicator,nivele_meciuri);
        }
        else{
             vector[i]= new JocMultiPlayer(nume,data,nr_note,note,indicator,nivele_meciuri);
        }
        
    }
    JocVideoHandler handler(vector,nr);
    int test;
    std::cin>>test;
    switch(test){
        case 1:
            {
                handler.display();
                break;
                
            }
        case 2:
            {
                handler.nota();
                break;
                
            }
        case 3:
            {
                int new_data[3];
                for(int i=0; i<3; i++){
                    std::cin>>new_data[i];
                }
                handler.filtrare(new_data);
                break;
                
            }
        case 4:
            {
                handler.nou();
                handler.vechi();
                break;
                
            }
        case 5:
            {
                int jucatori;
                float timp;
                std::cin>>jucatori>>timp;
                handler.calcul_timp(jucatori,timp);
                break;
                
            }
            
    }
    return 0;
}
