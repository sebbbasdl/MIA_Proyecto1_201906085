#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <algorithm>

#include "funciones.cpp"



using namespace std;





string minuscula(string cadena) {
  for (int i = 0; i < cadena.length(); i++) cadena[i] = tolower(cadena[i]);
  return cadena;
}






void commando(char *command){
  
  string path;
  
  char *token = std::strtok(command, " ");
  
  

  
  if(strcasecmp(token,"exec")==0){
    string line;
    string text;
    token = std::strtok(NULL, "\"");
    std::cout << token << ' '<<endl;
    

    

    token = std::strtok(NULL, "\"");
    std::cout << token << ' '<<endl;

    path=token;
  
    
    
    //exec $path="/home/sebbbasdl/Documentos/MIA_Proyecto1_201906085/[MIA]Proyecto1_201906085/prueba.script"
    //exec $path="/home/sebbbasdl/Descargas/CalificacionFase1p2.sh"

    //exec $path="/home/sebbbasdl/archivoprueba.sh"
    
  
    ifstream archivo(path);
    while(getline(archivo,line)){
      text=text+line;
      if(text==""){
        cout<<"entre"<<endl;
      }else{
        strcpy(command,text.c_str());
        //strcpy(comando,text.c_str());
        commando(command);
        cout<<text<<endl;
        //command(comando[100]);
        text="";
      }
      
    }
    
    
    

  
    
    
    
  }else if (strcasecmp(token,"mkdisk")==0){
    string a_mkdisk[3];
    //Mkdisk $size=>8 $path=>”/home/sebbbasdl/Documentos/prueba/” $name=>Disco1.dsk
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
        

        if(strcasecmp(token,"-size-")==0){
          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;
          a_mkdisk[0]=token;
          token = std::strtok(NULL, ">");
          cont+=1;

        }else if (strcasecmp(token,"-path-")==0){
          
          token = std::strtok(NULL, "-");
          
          std::cout << token << ' '<<endl;
          a_mkdisk[1]=token;
          token = std::strtok(NULL, ">");
          cont+=1;

        }else if (strcasecmp(token,"name-")==0 ||strcasecmp(token,"-name-")==0 ){
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

    if(cont==3 && stoi(a_mkdisk[0])%8==0){
     crearDisco(a_mkdisk);
    }else{
      cout<<"No se pudo crear disco"<<endl;
    }
    
  
  }else if (strcasecmp(token,"rmdisk")==0){
    //rmDisk $path=>"/home/sebbbasdl/Documentos/prueba/Disco1.dsk"
    token = std::strtok(NULL, "\"");
    std::cout << token << ' '<<endl;

    token = std::strtok(NULL, "\"");
    std::cout << token << ' '<<endl;

    path=token;
    cout<<"El disco a eliminar es: "+path<<endl;
    
    rmdisk(path);

  }else if (strcasecmp(token,"fdisk")==0){
    //fdisk $sizE=>1 @type=>L @unit=>xd @fit=>bf $path=>”/mis discos/Disco3.dsk” $name=>Particion3
    //Mkdisk $size=>8 $path=>”/home/sebbbasdl/Documentos/” $name=>Disco1.dsk
    //fdisk @tYpE=>p $path=>”/home/sebbbasdl/Documentos/Disco1.dsk” $name=>Part4 @Unit=>K @fit=>wf $sizE=>200
    //fdisk @tYpE=>p $path=>”/home/sebbbasdl/Documentos/Disco1.dsk” $name=>Part2 @Unit=>K @fit=>bf $sizE=>300
    //fdisk @tYpE=>p $path=>”/home/sebbbasdl/Documentos/Disco1.dsk” $name=>Part3 @Unit=>K @fit=>ff $sizE=>400

    
    //fdisk @add=>2 $path=>”/home/sebbbasdl/Documentos/Disco1.dsk” $name=>Part3
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
        

        if(strcasecmp(token,"-size-")==0){
          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;
          a_fdisk[0]=token;
          token = std::strtok(NULL, ">");
          fsize=true;
          cont+=1;

        }else if (strcasecmp(token,"-path-")==0){
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
          

        }else if (strcasecmp(token,"-name-")==0){
          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;
          a_fdisk[2]=token;
          token = std::strtok(NULL, ">");
          cont+=1;
          fname=true;

        
        }else if (strcasecmp(token,"-unit-")==0){
          token = std::strtok(NULL, " ");
          
          std::cout << token << ' '<<endl;
          if(strcasecmp(token,"b")==0 || strcasecmp(token,"k")==0|| strcasecmp(token,"m")==0){
            
            a_fdisk[3]=token;
            token = std::strtok(NULL, ">");
            cont+=1;
          }else{
            break;
          }

          
        
        }else if (strcasecmp(token,"-type-")==0){

          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;

          if(strcasecmp(token,"p")==0 || strcasecmp(token,"e")==0|| strcasecmp(token,"l")==0){
            a_fdisk[4]=token;
            token = std::strtok(NULL, ">");
            cont+=1;
          }else{
            break;
          }
          

        }else if (strcasecmp(token,"-fit-")==0){
          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;

          if(strcasecmp(token,"bf")==0 || strcasecmp(token,"ff")==0|| strcasecmp(token,"wf")==0){
            a_fdisk[5]=token;
            token = std::strtok(NULL, ">");
            cont+=1;  
          }else{
            break;
          }
          
        
        }else if (strcasecmp(token,"-delete-")==0){
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
          

        }else if (strcasecmp(token,"-add-")==0){
          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;
          a_fdisk[7]=token;
          token = std::strtok(NULL, ">");
          cont+=1;
          fadd=true;

        }else if (strcasecmp(token,"-mov-")==0){
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
      fdisk_add(a_fdisk);
    }else if( fadd==false && fdelete==false && fpath==true && fname==true && fsize== true){
      cout<<"Particion correcta"<<endl;
      crearParticion(a_fdisk);
    }else{
      cout<<"Existe un error en fdisk"<<endl;
    }
    
    
    //cout<<cont<<endl;
    //cout<<a_fdisk[7]<<endl;
    cout<<"--ARREGLO FDISK--"<<endl;
    a_fdisk[1]+=".dsk";

    for (int i = 0; i < cont; i++){
      cout<<a_fdisk[i]<<endl;
    }



  
  
  }else if (strcasecmp(token,"mount")==0){
    string a_mount[2];
    bool fmount=true;
    ////Mkdisk $size=>8 $path=>”/home/sebbbasdl/Documentos/prueba/” $name=>Disco1.dsk
    //Mkdisk $size=>32 $path=>”/home/mi user/” $name=>Disco1.dsk"
    //mount $path=>"/home/sebbbasdl/Documentos/prueba/Disco1.dsk" $name=>Part1"
    //fdisk @tYpE=>p $path=>"/home/sebbbasdl/Documentos/prueba/Disco1.dsk" $name=>Part3 @Unit=>K @fit=>ff $sizE=>200"

    int cont=0;
    bool fpath=false;
    bool fname=false;
    //cout<<fmount<<endl;
    
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

        if (strcasecmp(token,"-path-")==0){
          
          token = std::strtok(NULL, "-");
          
          std::cout << token << ' '<<endl;
          a_mount[0]=token;
          token = std::strtok(NULL, ">");
          cont+=1;
          fmount=false;
          fpath=true;

        }else if (strcasecmp(token,"name-")==0 ||strcasecmp(token,"-name-")==0 ){
          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;
          a_mount[1]=token;
          token = std::strtok(NULL, ">");
          cont+=1;
          fmount=false;
          fname=true;

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
        onlymount();

        
    }

    if(fname ==true && fpath==true){
      mount(a_mount);
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
    
    token = std::strtok(NULL, ">");
    
    while(token){
      aux=token[3];
      aux2="-id"+aux +"-";
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

    
  
  
  }else if(strcasecmp(token,"pause")==0){
    int i;

    std::cin >> i;

    if (i == 0)
        return ; // Se recibió un cero.
    else if (i < 0)
        return ; // Se recibió un uno.
    else {
        // Código para el funcionamiento normal del programa.
        return ; // El programa terminó satisfactoriamente.
    }
    
    
    
      

  }else if(strcasecmp(token,"/*")==0){
    token = std::strtok(NULL, "*");
    cout<<token<<endl;


  
  
  }else if(strcasecmp(token,"rep")==0){
    
    string a_rep[3];
    //rep $name=>mbr $id=>vda1 $path=>"/home/sebbbasdl/Documentos/reporte 2.jpg"
  //rep $name=>disk $id=>vda1 $path=>"/home/sebbbasdl/Documentos/prueba/reporte 2.jpg" 

  //exec $path=>"/home/sebbbasdl/Descargas/CalificacionFase1p1.sh"
  //exec $path="/home/sebbbasdl/Documentos/MIA_Proyecto1_201906085/[MIA]Proyecto1_201906085/prueba.sh"
    /*rep
    0   name
    1   path
    2   id
    */
    int cont=0;
    
    token = std::strtok(NULL, ">");
    while (token){
        
        std::cout << token<< ' '<<endl;
        
        

        if(strcasecmp(token,"-name-")==0){
          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;
          a_rep[0]=token;
          token = std::strtok(NULL, ">");
          cont+=1;

        }else if (strcasecmp(token,"-path-")==0){
          
          token = std::strtok(NULL, "-");
          
          std::cout << token << ' '<<endl;
          a_rep[1]=token;
          token = std::strtok(NULL, ">");
          cont+=1;

        }else if (strcasecmp(token,"id-")==0 ||strcasecmp(token,"-id-")==0 ){
          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;
          a_rep[2]=token;
          token = std::strtok(NULL, ">");
          cont+=1;

        }else{
          token=NULL;
          cout<<"Falta algun parametro en rep"<<endl;
          
        }


        
    }

    reportes(a_rep);    

    
    
  }else if (strcasecmp(token,"mkfs")==0){
    //MkfS -id->vda1 -type->fast
    /*
    0 id
    1 type
    2 fs
    */
    int cont=0;
    bool fid=false;
    string a_mkfs[8];
    token = std::strtok(NULL, ">");
  
    a_mkfs[1]="full";
    a_mkfs[2]="2fs";
    
    

    
    while (token){
        //std::cout << token << ' '<<endl;
        std::cout << token<< ' '<<endl;
        /*if(token[0]=='$'||token[0]=='M'||token[0]=='m'  ){
          token = std::strtok(NULL, ">");
          cout<<"entre"<<endl;
          std::cout << token<< ' '<<endl;
        }*/
        

        if(strcasecmp(token,"-id-")==0){
          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;
          a_mkfs[0]=token;
          token = std::strtok(NULL, ">");
          fid=true;
          cont+=1;

        }else if (strcasecmp(token,"-type-")==0){

          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;

          if(strcasecmp(token,"fast")==0 || strcasecmp(token,"full")==0){
            a_mkfs[1]=token;
            token = std::strtok(NULL, ">");
            cont+=1;
          }else{
            break;
          }
          

        }else if (strcasecmp(token,"-fs-")==0){

          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;

          if(strcasecmp(token,"2fs")==0 || strcasecmp(token,"3fs")==0){
            a_mkfs[2]=token;
            token = std::strtok(NULL, ">");
            cont+=1;
          }else{
            break;
          }
          

        }else{
          token=NULL;
          
        }

      
    }
    cout<<"----Arreglo MKFS----"<<endl;
    for (int i = 0; i < 3; i++){
      cout<<a_mkfs[i]<<endl;
    }

    if(fid==true){
      mkfs(a_mkfs);
    }else{
      cout<<"No se encontro el id para la funcion MKFS"<<endl;
    }

    
  }else if(strcasecmp(token,"mkfile")==0){
    //mkfile $id=>vda1 $path=>"/home/user/docs/b.txt" $size=>100 @cont=>"/home/Documents/b.txt" @p
    //mkfile $path=>"/home/user/docs/b.txt" $id=>vda1
    /*
    0 id
    1 path
    2 p
    3 size
    4 cont
    */
    int cont=0;
    bool fp=false;
    bool fsize=false;
    bool fcont=false;
    bool fpath=false;
    bool fid=false;
    
    string a_mkfile[8];
    token = std::strtok(NULL, ">");
    a_mkfile[3]="0";
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
        

        if(strcasecmp(token,"-size-")==0){
          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;
          a_mkfile[3]=token;
          token = std::strtok(NULL, ">");
          fsize=true;
          
          cont+=1;

        }else if (strcasecmp(token,"-path-")==0){
          token = std::strtok(NULL, ".");
          std::cout << token << ' '<<endl;
          //token = std::strtok(NULL, " ");
          //std::cout << token << ' '<<endl;

          a_mkfile[1]=token ;

          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;
          
          token = std::strtok(NULL, ">");
          std::cout << token << ' '<<endl;
          
          fpath=true;
          
          cont+=1;
        
          
          //cout << aux[3] << "----------"<<endl;
          

        }else if (strcasecmp(token,"-id-")==0){
          token = std::strtok(NULL, " ");
          
          std::cout << token << ' '<<endl;
            
            a_mkfile[0]=token;
            token = std::strtok(NULL, ">");
            cont+=1;
          fid=true;

          
        
        }else if (token[0]=='@' && token[1]=='p'){
          //cout<<"soy p"<<endl;
          a_mkfile[2]=token;
          
          fp=true;
          break;
          
          

        }else if (strcasecmp(token,"-cont-")==0){
          
          token = std::strtok(NULL, ".");
          std::cout << token << ' '<<endl;
          //token = std::strtok(NULL, " ");
          //std::cout << token << ' '<<endl;

          a_mkfile[4]=token ;
          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;
          token = std::strtok(NULL, ">");
          std::cout << token << ' '<<endl;
          fcont=true;
          
          cont+=1;
          
        
        }

        else{
          token=NULL;
          
        }
    }

    cout<<"----Arreglo MKFILE----"<<cont<<endl;
    for (int i = 0; i < 5; i++){
      cout<<a_mkfile[i]<<endl;
    }

    if(fsize==false && fcont==true && fpath==true && fid==true){
      cout<<"copiar archivo en otro directorio"<<endl;
    }else if(fpath==true && fid==true && fsize==true && fp==true){
      cout<<"crear archivo y crear rutas"<<endl;

    }else if(fpath==true && fid==true && fsize==true && fp==false){
      cout<<"crear archivo en ruta"<<endl;
    }else{
      cout<<"Algun parametro esta malo en mkfile"<<endl;
    }

  }else if(strcasecmp(token,"mkdir")==0){
    //Mkdir $id=>vda1 $path=>"/home/user/docs/usac" @p
    int cont=0;
    bool fp=false;
    
    bool fpath=false;
    bool fid=false;
    
    string a_mkdir[8];
    token = std::strtok(NULL, ">");
    

    
    while (token){
        //std::cout << token << ' '<<endl;
        std::cout << token<< ' '<<endl;
        /*if(token[0]=='$'||token[0]=='M'||token[0]=='m'  ){
          token = std::strtok(NULL, ">");
          cout<<"entre"<<endl;
          std::cout << token<< ' '<<endl;
        }*/
        

        if(strcasecmp(token,"-id-")==0){
          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;
          a_mkdir[0]=token;
          token = std::strtok(NULL, ">");
          fid=true;
          
          cont+=1;

        }else if (strcasecmp(token,"-path-")==0){
          token = std::strtok(NULL, "-");
          
          std::cout << token << ' '<<endl;
          a_mkdir[1]=token;
          token = std::strtok(NULL, ">");
          cont+=1;


          
          fpath=true;
          
          
        
          
          //cout << aux[3] << "----------"<<endl;
          

        }else if ((token[0]=='-' || token[0]==' ') || token[0]=='p'){
          cout<<"soy p"<<endl;
          a_mkdir[2]=token;
          
          fp=true;
          break;
          
          

        }
        

        else{
          token=NULL;
          
        }
    }

    cout<<"----Arreglo MKFDIR----"<<cont<<endl;
    for (int i = 0; i < 5; i++){
      cout<<a_mkdir[i]<<endl;
    }

    if(fp==true && fid==true && fpath==true){
      cout<<"se crear rutas"<<endl;
    }else if(fp==false && fid==true && fpath==true){
      cout<<"la carpeta padre ya debe existir"<<endl;
    }
  }else if(strcasecmp(token,"mkgrp")==0){
    string pathId;
    //mkgrp -name->usuarios
    /*
    0 name
    */
    int cont=0;
    bool fname=false;
    string name;
    token = std::strtok(NULL, ">");
  
    //a_mkfs[1]="full";
    //a_mkfs[1]="2fs";
    
    

    
    while (token){
        //std::cout << token << ' '<<endl;
        std::cout << token<< ' '<<endl;
        /*if(token[0]=='$'||token[0]=='M'||token[0]=='m'  ){
          token = std::strtok(NULL, ">");
          cout<<"entre"<<endl;
          std::cout << token<< ' '<<endl;
        }*/
        

        if(strcasecmp(token,"-name-")==0){
          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;
          name=token;
          token = std::strtok(NULL, ">");
          fname=true;
          cont+=1;

        }else{
          token=NULL;
          
        }

        if(fname==true){
          cout<<arregloMountPath[0]<<endl;
          mkgrp(name,pathId);
        }

      
    }
    
  }else if(strcasecmp(token,"login")==0){
    string pathId;
    
    int cont=0;
    bool fname=false;
    string name;
    token = std::strtok(NULL, ">");
    string log[3];
    //a_mkfs[1]="full";
    //a_mkfs[1]="2fs";
    
    

    
    while (token){
        //std::cout << token << ' '<<endl;
        std::cout << token<< ' '<<endl;
        /*if(token[0]=='$'||token[0]=='M'||token[0]=='m'  ){
          token = std::strtok(NULL, ">");
          cout<<"entre"<<endl;
          std::cout << token<< ' '<<endl;
        }*/
        

        if(strcasecmp(token,"-usr-")==0){
          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;
          log[0]=token;
          token = std::strtok(NULL, ">");
          fname=true;
          cont+=1;

        }else if(strcasecmp(token,"-pass-")==0){
          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;
          log[1]=token;
          token = std::strtok(NULL, ">");
          
          cont+=1;
        }else if(strcasecmp(token,"-id-")==0){
          token = std::strtok(NULL, " ");
          std::cout << token << ' '<<endl;
          log[2]=token;
          token = std::strtok(NULL, ">");
          
          cont+=1;
        }else{
          token=NULL;
          
        }

        

      
    }

    if(cont==3){
      cout<<log[0]<<log[1]<<log[2]<<endl;
      login(log[0],log[1],log[2]);
      
    }else{
      cout<<"Hace falta algun parametro en Login para poder iniciar sesion."<<endl;
    }
    
  }else if(strcasecmp(token,"logout")==0){
    activa=false;
    cout<<"Usted ha cerrado sesion"<<endl;
  }else{
    cout<<"¡Error, este comando no existe!"<<endl;
  }

  
  

}




void terminal(){
  if(4%8==0){
    cout<<"----"<<endl;
  }
  char comando[100];
  cout<<"Ingrese el comando: "<< endl;
  scanf(" %[^\n]s", comando);
  

  
  commando(comando);
  terminal();
}


int main(){
  /*int arreglo[4] = {100,5,6,21};
  ordenar(4,arreglo);*/
  //tablaInodos *inodos=new tablaInodos();
  
  /*cout<<"1-------------"<<endl;
  insertar(inodos,"prueba",'0',"/root/");
  cout<<"2-------------"<<endl;
  insertar(inodos,"prueba",'0',"/root/home/");*/
  /*cout<<"3--------------"<<endl;
  insertar(inodos,"prueba",'0',"/root/casa/");*/
  //crearArchivo_UyG("/home/sebbbasdl/Documentos/MIA_Proyecto1_201906085/[MIA]Proyecto1_201906085/Users.txt");
  //login("root","123","/home/sebbbasdl/Documentos/MIA_Proyecto1_201906085/[MIA]Proyecto1_201906085/Users.txt");
  //mkgrp("cr7","/home/sebbbasdl/Documentos/MIA_Proyecto1_201906085/[MIA]Proyecto1_201906085/Users.txt");
  //mkusr("sebas2","321","cr7","/home/sebbbasdl/Documentos/MIA_Proyecto1_201906085/[MIA]Proyecto1_201906085/Users.txt");
  //cout<<path_sindisco("/home/sebbbasdl/archivos/fase1/D1.dsk")<<endl;
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


