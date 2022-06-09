#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <vector>
#include "analizador.cpp"

using namespace std;


string split(string str, char del){
    
    string temp = "";
    string temp1 = "";
    string spliteo[2];
    for(int i=0; i<(int)str.size(); i++){
        
         if(str[i] != del){
            temp += str[i];
        }
          else{
            //cout << temp << " ";
              temp1=temp;
              temp = "";
        }
    }
      //cout<< "-------------split---------\n" ;
      //cout<< temp1<<temp;
      spliteo[0]=temp1;
      spliteo[1]=temp;
      /*for(int i=0; i<2;i++){
        cout << "<>"<< spliteo[i]<<"\n";
      }*/
      
      return spliteo[1];


      //analizador(temp);

}


char encontrarSigno(char *cadena){

  int cantidad= strlen(cadena);
  //cout<<cantidad<<endl;
  char resultado;

  for (int i = 0; i < cantidad; i++){
    if(cadena[i]=='$'){
      resultado='$';
      break;
    }else if (cadena[i]=='@'){
      resultado='@';
      break;
    }
    
  }
  std::cout<<resultado<<endl;
  return resultado;
  



}

string minuscula(string cadena) {
  for (int i = 0; i < cadena.length(); i++) cadena[i] = tolower(cadena[i]);
  return cadena;
}



void command(char *command){
  //char cadena[100] = "patatas#fritas#con#ketchup#y#mayonesa";
  string path;
  
  char *token = std::strtok(command, " ");
  //std::cout << token << ' '<<endl;
  //token = std::strtok(NULL, " ");
  //std::cout << token << ' '<<endl;
  

  //char *dato = strtok(command," ");
  //cout<<minuscula(token)<<endl;
  if(strcasecmp(token,"exec")==0){
    token = std::strtok(NULL, "\"");
    std::cout << token << ' '<<endl;

    token = std::strtok(NULL, "\"");
    std::cout << token << ' '<<endl;

    path=token;
    cout<<"Se manda a analizar el archivo: "+path<<endl;

  
    
    
    
  }else if (strcasecmp(token,"mkdisk")==0){
    string a_mkdisk[3];
    //Mkdisk $size=>32 $path=>”/home/mi user/” $name=>Disco1.dsk
    int cont=0;
    
    token = std::strtok(NULL, ">");
    while (token){
        //std::cout << token << ' '<<endl;
        std::cout << token<< ' '<<endl;
        /*if(token[0]=='$'||token[0]=='M'||token[0]=='m'  ){
          token = std::strtok(NULL, ">");
          cout<<"entre"<<endl;
          std::cout << token<< ' '<<endl;
        }*/
        

        if(strcasecmp(token,"$size=")==0){
          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;
          a_mkdisk[0]=token;
          token = std::strtok(NULL, ">");
          cont+=1;

        }else if (strcasecmp(token,"$path=")==0){
          
          token = std::strtok(NULL, "$");
          
          std::cout << token << ' '<<endl;
          a_mkdisk[1]=token;
          token = std::strtok(NULL, ">");
          cont+=1;

        }else if (strcasecmp(token,"name=")==0 ||strcasecmp(token,"$name=")==0 ){
          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;
          a_mkdisk[2]=token;
          token = std::strtok(NULL, ">");
          cont+=1;

        }else{
          token=NULL;
          cout<<"Falta algun parametro en mkdisk"<<endl;
          
        }
    }
    cout<<"--ARREGLO MKDISK--"<<endl;
    for (int i = 0; i < cont; i++){
      cout<<a_mkdisk[i]<<endl;
    }
  
  }else if (strcasecmp(token,"rmdisk")==0){
    //rmDisk $path=>"/home/mis discos/Disco_4.dsk"
    token = std::strtok(NULL, "\"");
    std::cout << token << ' '<<endl;

    token = std::strtok(NULL, "\"");
    std::cout << token << ' '<<endl;

    path=token;
    cout<<"El disco a eliminar es: "+path<<endl;
    

  }else if (strcasecmp(token,"fdisk")==0){
    //fdisk $sizE=>1 @type=>L @unit=>xd @fit=>bf $path=>”/mis discos/Disco3.dsk” $name=>Particion3
    //fdisk @tYpE=>E $path=>”/home/Disco2.dsk” $name=>Part3 @Unit=>K $sizE=>200
    /*Arreglo fdisk 
    Posicion:
    0   -size
    1   -path
    2   -name
    3   unit
    4   type
    5   fit
    6   delete
    7   add
    8   mov
    
    */
    int cont=0;
    bool fsize=false;
    bool fpath=false;
    bool fname=false;
    string a_fdisk[8];
    token = std::strtok(NULL, ">");
    a_fdisk[3]="k";
    a_fdisk[4]="p";
    a_fdisk[5]="wf";
    bool fdelete=false;
    bool fadd=false;

    
    while (token){
        //std::cout << token << ' '<<endl;
        std::cout << token<< ' '<<endl;
        /*if(token[0]=='$'||token[0]=='M'||token[0]=='m'  ){
          token = std::strtok(NULL, ">");
          cout<<"entre"<<endl;
          std::cout << token<< ' '<<endl;
        }*/
        

        if(strcasecmp(token,"$size=")==0){
          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;
          a_fdisk[0]=token;
          token = std::strtok(NULL, ">");
          fsize=true;
          cont+=1;

        }else if (strcasecmp(token,"$path=")==0){
          token = std::strtok(NULL, ".");
          std::cout << token << ' '<<endl;
          //token = std::strtok(NULL, " ");
          //std::cout << token << ' '<<endl;

          a_fdisk[1]=token ;
          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;
          token = std::strtok(NULL, ">");
          std::cout << token << ' '<<endl;
          fpath=true;
          cont+=1;
        
          
          //cout << aux[3] << "----------"<<endl;
          

        }else if (strcasecmp(token,"$name=")==0){
          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;
          a_fdisk[2]=token;
          token = std::strtok(NULL, ">");
          cont+=1;
          fname=true;

        
        }else if (strcasecmp(token,"@unit=")==0){
          token = std::strtok(NULL, " ");
          cout<<"tu madre"<<endl;
          std::cout << token << ' '<<endl;
          if(strcasecmp(token,"b")==0 || strcasecmp(token,"k")==0|| strcasecmp(token,"m")==0){
            
            a_fdisk[3]=token;
            token = std::strtok(NULL, ">");
            cont+=1;
          }else{
            break;
          }

          
        
        }else if (strcasecmp(token,"@type=")==0){

          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;

          if(strcasecmp(token,"p")==0 || strcasecmp(token,"e")==0|| strcasecmp(token,"l")==0){
            a_fdisk[4]=token;
            token = std::strtok(NULL, ">");
            cont+=1;
          }else{
            break;
          }
          

        }else if (strcasecmp(token,"@fit=")==0){
          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;

          if(strcasecmp(token,"bf")==0 || strcasecmp(token,"ff")==0|| strcasecmp(token,"wf")==0){
            a_fdisk[5]=token;
            token = std::strtok(NULL, ">");
            cont+=1;  
          }else{
            break;
          }
          
        
        }else if (strcasecmp(token,"@delete=")==0){
          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;
          if(strcasecmp(token,"full")==0 || strcasecmp(token,"fast")==0){
            a_fdisk[6]=token;
            token = std::strtok(NULL, ">");
            cont+=1;
            fdelete=true;
          }else{
            break;
          }
          

        }else if (strcasecmp(token,"@add=")==0){
          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;
          a_fdisk[7]=token;
          token = std::strtok(NULL, ">");
          cont+=1;
          fadd=true;

        }else if (strcasecmp(token,"@mov=")==0){
          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;
          a_fdisk[8]=token;
          token = std::strtok(NULL, ">");
          cont+=1;

        }else{
          token=NULL;
          
        }
    }

    if(fdelete==true && fpath==true && fname==true && cont==3){
      cout<<"Delete correcto"<<endl;
    }else if (fadd==true && fpath==true && fname==true){
      cout<<"Add correcto"<<endl;
    }else if( fadd==false && fdelete==false && fpath==true && fname==true && fsize== true){
      cout<<"Particion correcta"<<endl;
    }else{
      cout<<"Existe un error en fdisk"<<endl;
    }
    
    
    cout<<cont<<endl;
    cout<<"--ARREGLO FDISK--"<<endl;
    a_fdisk[1]+=".dsk";
    for (int i = 0; i < cont; i++){
      cout<<a_fdisk[i]<<endl;
    }



  
  
  }else if (strcasecmp(token,"mount")==0){
    string a_mount[2];
    bool fmount=true;
    //Mkdisk $size=>32 $path=>”/home/mi user/” $name=>Disco1.dsk
    int cont=0;
    cout<<fmount<<endl;
    
    token = std::strtok(NULL, ">");
    while (token){
        //std::cout << token << ' '<<endl;
        std::cout << token<< ' '<<endl;
        /*if(token[0]=='$'||token[0]=='M'||token[0]=='m'  ){
          token = std::strtok(NULL, ">");
          cout<<"entre"<<endl;
          std::cout << token<< ' '<<endl;
        }*/
        cout<<fmount<<endl;

        if (strcasecmp(token,"$path=")==0){
          
          token = std::strtok(NULL, "$");
          
          std::cout << token << ' '<<endl;
          a_mount[0]=token;
          token = std::strtok(NULL, ">");
          cont+=1;
          fmount=false;

        }else if (strcasecmp(token,"name=")==0 ||strcasecmp(token,"$name=")==0 ){
          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;
          a_mount[1]=token;
          token = std::strtok(NULL, ">");
          cont+=1;
          fmount=false;

        }else{
          token=NULL;
          cout<<"Falta algun parametro en mkdisk"<<endl;
          
        }
    }
    cout<<"--ARREGLO MOUNT--"<<endl;
    for (int i = 0; i < cont; i++){
      cout<<a_mount[i]<<endl;
    }

    if (fmount==true ){
        cout<<"Mostrar arreglo de particiones montadas;"<<endl;

        
    }
    



  }else if (strcasecmp(token,"unmount")==0){
    //unmount $id1=>vda1
    //unmount $id1=>vda1 $id2=>vdb2 $id3=>vdc1
    string id;
    string aux;
    string aux2;
    //string a_unmount[20];
    int cont;
    /*for (int i = 0; i < cant; i++){
      cout<<token[i]<<endl;
      if(token[i]=='$'){
        contador+=1;
      }
    }*/
    //cout<<"--"<<contador<<endl;
    //std::cout<<token[3]<<endl;
    std::vector<string> a_unmount;
    token = std::strtok(NULL, ">");
    
    while(token){
      aux=token[3];
      aux2="$id"+aux +"=";
      std::cout<<aux2<<endl;
      if(aux2==token){
        token = std::strtok(NULL, " ");
        std::cout << token << ' '<<endl;
        //a_mount[1]=token;
        token = std::strtok(NULL, ">");
        //a_unmount.push_back(token);
        
      }
      
    }
    /*cout<<"--ARREGLO UNMOUNT--"<<endl;
    for (int i = 0; i < cont; i++){
      cout<<a_unmount[i]<<endl;
    }*/

    
  
  
  }else{
    cout<<"¡Error, este comando no existe!"<<endl;
  }

}




void terminal(){
  char comando[100];
  cout<<"Ingrese el comando: "<< endl;
  scanf(" %[^\n]s", comando);
  command(comando);
  terminal();
}


int main(){
  
  terminal();
  
    /*string dato;
    string path;
    string ruta;
    string comando;
    string comando2;
    bool flag=false;
    cout<<"Ingrese el comando: "<<endl;
    getline(cin, dato);
    //exec $path=>"/home/mis documentos/archivos 2022"
    comando=split2(dato,'$');
    comando2=split2(comando,' ');
    


    cout<<comando2<<endl;
    //cout<<exec<<endl;

    if(comando2=="exec"){
        path=split(dato,'$');
        ruta=split(path,'=>'); 
        cout<<ruta<<endl;
    }else{
        while(!flag){
            

            if(dato=="exit"){
                flag=true;

            }else{
                cout<<"Ingrese el comando: "<<endl;
                //Mkdir @P $id=>vda1 $path->"/home/user/docs/usac"
                getline(cin, dato);
                analizar_comando(dato);
            }

        }


        
    }*/
     

       
}


