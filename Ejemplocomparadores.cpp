#include <iostream>
#include "Date.h"
#include <stdlib.h>

int main(){

    int mounth=0,day=0,year=0,opc=0;

    std::cout<<"Ingrese el mes actual: "<<std::endl;
    std::cin>>mounth;
    std::cout<<"Ingrese el dia de hoy: "<<std::endl;
    std::cin>>day;
    std::cout<<"Ingrese el año actual: "<<std::endl;
    std::cin>>year;
    Date a(mounth,day,year);
    do
    {
    	system("cls");
        std::cout<<"Esta es la fecha actual..."<<std::endl;
        std::cout<<a<<std::endl;
        std::cout<<"Que es lo que desea hacer?"<<std::endl;
        std::cout<<"1- Sumar un dia: "<<std::endl;
        std::cout<<"2- Sumar un mes: "<<std::endl;
        std::cout<<"3- Sumar un año: "<<std::endl;
        std::cout<<"4- Restar un dia: "<<std::endl;
        std::cout<<"5- Restar un mes: "<<std::endl;
        std::cout<<"6- Restar un año: "<<std::endl;
        std::cout<<"7- Salir: "<<std::endl;
        std::cin>>opc;
        switch (opc)
        {
        case 1:
            a.incrementDay(); 
            break;
        case 2:
            a.incrementMes();
            break;
        case 3:
            a.incrementYear();
            break;
        case 4:
            a.DecrementDay();
            break;
        case 5:
            a.DecrementMes();
            break;
        case 6:
            a.DecrementYear();
            break;
        default:
        std::cout<<"Gracias, que pase buena dia..."<<std::endl;
        break;
        }   
    } while (opc != 7);
    

}