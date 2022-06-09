#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;


void analizar_comando(string cadena){

    char command[500];
    cadena+=" ";
    //int contador=0;
    string aux;
    string arreglo[500];
    int contador=0;
    std::string cadena1=cadena ;
    strcpy(command,cadena.c_str());
    std::cout << cadena;
    cout<<"\n estoy en analizador \n";
    for(int i=0; i<cadena.length();i++){
      
      
      if(command[i] == ' ' ){
        cout<<"\n\n"<<contador<<"\n\n";
        arreglo[contador]=aux;
        //cout<<"\n\n>>>>>>>>>>>>"<< aux<<"\n\n";
        contador+=1;
        aux="";

      }else{
        aux+=command[i];
        //cout<<command[i]<<","<<endl;
        
      }
    }

    cout<<"\n----------Arreglo-------\n" ;
    int tamanio=sizeof arreglo/sizeof arreglo[0];
    //cout<< "--------------------->"<<tamanio;
    for(int i=0; i<tamanio;i++){
      cout<< arreglo[i]<<",";
    }
}