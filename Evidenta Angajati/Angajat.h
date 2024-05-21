#ifndef ANGAJAT_H
#define ANGAJAT_H

class Angajat{
private:
    std::string nume;
    std::string departament;
public:
    Angajat(std::string nume, std::string departament): nume(nume), departament(departament){}
    virtual void afisare() = 0;
    virtual float rentabilitate_angajat() = 0;
    virtual float brut()=0;
    
    std::string get_nume(){
        return nume;
    }
    std::string get_departament(){
        return departament;
    }
    ~Angajat(){}
};

#endif
