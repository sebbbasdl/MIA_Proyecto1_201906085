#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <cstring>
#include <algorithm>
#include <dirent.h>

#include "strucs.cpp"


using namespace std;

string arregloMount[20];

int ordenar(int TAMANYO, int datos[]){
  
      sort(datos, datos + TAMANYO);
      cout << "Datos ordenados: ";
      for (int i = 0; i != TAMANYO; ++i)
          cout << datos[i] << " ";

      return datos[TAMANYO];
}

bool existeE(MBR mbr){
    if(mbr.mbr_partition_1.part_type == 'E'|| mbr.mbr_partition_2.part_type == 'E'
    || mbr.mbr_partition_3.part_type == 'E'|| mbr.mbr_partition_4.part_type == 'E'){
        return true;
    }

    return false;
}

string pathsinC(string prueba[]){
    string path;
    int fin = prueba[1].length();
    for (int i = 0; i < fin; i++){
        if(prueba[1][i]=='/' || isalpha(prueba[1][i])  || isdigit(prueba[1][i])) {

            path+=prueba[1][i];

            

        }
    }

    std::cout<<path<<endl;
    return path;

}

string pathsinC2(string prueba[]){
    string path;
    int fin = prueba[1].length();
    for (int i = 0; i < fin; i++){
        if(prueba[1][i]=='/' || isalpha(prueba[1][i])  || isdigit(prueba[1][i]) || prueba[1][i]=='.') {

            path+=prueba[1][i];

            

        }
    }

    std::cout<<path<<endl;
    return path;

}

bool existeDirectorio(string rut){
    DIR *directorio;
    if(directorio==opendir(rut.c_str())){
        closedir(directorio);
        return true;
    }else{
        return false;
    }
}

bool existeArchivo(string ruta){
    FILE *archivo;
    if(archivo==fopen(ruta.c_str(),"r")){

        fclose(archivo);
        return true;
    }else{
        return false;
    }
}

void rmdisk(string pathh){

    if(existeArchivo(pathh)==false){
        cout<<"No se puede eliminar el disco ya que no existe."<<endl;
    }else{
        FILE *file;
        file=fopen(pathh.c_str(),"w");
        fclose(file);

        remove(pathh.c_str());
    }


}

void mount( string a_mount2[]){

    string aux[2];
    aux[0]=a_mount2[1];
    aux[1]=a_mount2[0];
    string path;
    path=pathsinC2(aux);

    cout<<path<<endl;
    FILE *file;
    file= fopen(path.c_str(),"rb+");

    if(file==NULL){
        cout<<"El disco al que deseea aplicar mount no existe."<<endl;
    }else{
        fseek(file,0,SEEK_SET);
        MBR mbr;
        fread(&mbr,sizeof(MBR),1,file);    
        cout<<mbr.mbr_partition_1.part_name<<endl;
        if(mbr.mbr_partition_1.part_name==aux[0]){
            cout<<"entre"<<endl;
            mbr.mbr_partition_1.part_status='1';

            arregloMount[0]="vda1";

            rewind(file);
            fwrite(&mbr,sizeof(MBR),1,file);
        }else if( mbr.mbr_partition_2.part_name==aux[0]){
            mbr.mbr_partition_1.part_status=='1';
            arregloMount[1]="vda2";

            rewind(file);
            fwrite(&mbr,sizeof(MBR),1,file);
            
        }else if( mbr.mbr_partition_3.part_name==aux[0]){
            arregloMount[2]="vda3";

            mbr.mbr_partition_1.part_status=='1';
            rewind(file);
            fwrite(&mbr,sizeof(MBR),1,file);
            
        }else if( mbr.mbr_partition_4.part_name==aux[0]){
            arregloMount[2]="vda4";
            mbr.mbr_partition_1.part_status=='1';

            rewind(file);
            fwrite(&mbr,sizeof(MBR),1,file);
            
        }else{
            cout<<"Esta particion no existe en el disco con la ruta: "<<aux[1]<<endl;
        }
        cout<<"------STATUS----"<<endl;
        
        fclose(file);

    }

    file = fopen(path.c_str(),"rb+");
    MBR mbr2;
    fseek(file,0,SEEK_SET);
    fread(&mbr2,sizeof(MBR),1,file);


    cout<<"---------------"<<endl;
    std::cout<<mbr2.mbr_partition_1.part_fit<<endl;
    std::cout<<mbr2.mbr_partition_1.part_name<<endl;
    std::cout<<mbr2.mbr_partition_1.part_size<<endl;
    std::cout<<mbr2.mbr_partition_1.part_start<<endl;
    std::cout<<mbr2.mbr_partition_1.part_status<<endl;
    std::cout<<mbr2.mbr_partition_1.part_type<<endl;
    
}
void onlymount(){
    for (int i = 0; i < 4; i++){
       cout<< arregloMount[i]<<endl;
        
    }
    
}

void crearDisco(string a_mkdisk2[]){
    /*
    0 size
    1 path
    2 name
    */
    string path;
    int contc=0;
    
    //int fin =a_mkdisk2[2].length();

    cout<<"--ARREGLO MKDISK--"<<endl;
    int cont= a_mkdisk2->length();
    for (int i = 0; i <= cont; i++){
      cout<<a_mkdisk2[i]<<endl;
    }

    path =pathsinC(a_mkdisk2) + a_mkdisk2[2];
    //char path2[255] = "/tmp/d1.dk";
    std::cout<<path<<endl;

    string arreglopath[30];
    string dato;
    int contaa =0;

    cout<<path.length()<<endl;
    for (int i = 0; i < path.length(); i++){
        
        if(path[i] == '/'){
            
            arreglopath[contaa]=dato;
            dato="";
            contaa+=1;
        }else{
            dato+=path[i];
        }
    }


    cout<<"---------"<<endl;
    string rutaaux;
    string rutaaux2;
    for (int i = 0; i < contaa; i++){
        rutaaux+="/"+arreglopath[i];

        if(existeDirectorio(rutaaux)==false){
            string com ="mkdir "+rutaaux2+"/\""+ arreglopath[i]+"\"";
            cout<<com<<endl;
            system(com.c_str());
        }
        rutaaux2+="/"+arreglopath[i];

    }


    
    


    /*MBR* mbr = (MBR*) malloc(sizeof(MBR));
    FILE *file;

    file=fopen(path.c_str(),"w+b");

    

    int megas=1024*1024;

    int start= (int)  sizeof(MBR);

    fwrite(mbr, sizeof(MBR),1,file);
    
    for (int i = 0; i < (stoi(a_mkdisk2[0]))*megas; i++){
        fputc('\0', file); 
    }
    fclose(file);
    cout<<"DISCO CREADO"<<endl;*/
    
    MBR mbr;
    FILE *file;

    file= fopen(path.c_str(),"wb");

    char buffer[1024];

    for (int i = 0; i < 1024; i++){
        buffer[i]='\0';

    }
    
    int size=stoi(a_mkdisk2[0]);
    for (int x = 0; x < (size*1024); x++){
        
        fwrite(&buffer,1024,1,file);
        
    }
    fclose(file);
    
    /*partition *part;
    part->part_fit='-';
    part->part_name[0]= '\0';
    part->part_size=-1;
    part->part_start=-1;
    part->part_status='0';
    part->part_type='-';*/

    time_t current_time;
    mbr.mbr_tamano=size*1024*1024;
    mbr.mbr_disk_signature=rand()%16;
    mbr.mbr_fecha_creacion=time(nullptr);
    mbr.mbr_partition_1.part_status='e';
    mbr.mbr_partition_1.part_fit='-';
    mbr.mbr_partition_1.part_name[0]='\0';
    mbr.mbr_partition_1.part_size=-1;
    mbr.mbr_partition_1.part_start=-1;
    mbr.mbr_partition_1.part_type='-';
    
    mbr.mbr_partition_2.part_status='e';
    mbr.mbr_partition_2.part_fit='-';
    mbr.mbr_partition_2.part_name[0]='\0';
    mbr.mbr_partition_2.part_size=-1;
    mbr.mbr_partition_2.part_start=-1;
    mbr.mbr_partition_2.part_type='-';

    mbr.mbr_partition_3.part_status='e';
    mbr.mbr_partition_3.part_fit='-';
    mbr.mbr_partition_3.part_name[0]='\0';
    mbr.mbr_partition_3.part_size=-1;
    mbr.mbr_partition_3.part_start=-1;
    mbr.mbr_partition_3.part_type='-';

    mbr.mbr_partition_4.part_status='e';
    mbr.mbr_partition_4.part_fit='-';
    mbr.mbr_partition_4.part_name[0]='\0';
    mbr.mbr_partition_4.part_size=-1;
    mbr.mbr_partition_4.part_start=-1;
    mbr.mbr_partition_4.part_type='-';
    /*mbr.mbr_partition_2=NULL;
    mbr.mbr_partition_3=NULL;
    mbr.mbr_partition_4=NULL;*/

    file = fopen(path.c_str(),"rb+");
    if(file !=NULL){
        fseek(file,0,SEEK_SET);
        fwrite(&mbr,sizeof(MBR),1,file);
        fclose(file);
    }else{
        cout<<"creacion del disco incorrecta"<<endl;
    }


    file = fopen(path.c_str(),"rb+");
    MBR mbr2;
    fseek(file,0,SEEK_SET);
    fread(&mbr2,sizeof(MBR),1,file);

    std::cout<<ctime( &mbr2.mbr_fecha_creacion)<<endl;

    fclose(file);
    
    

    
    
    
    
}


void crearParticion(string a_fkdisk2[]){
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
    string path;
    int sizefdisk;
    path =pathsinC(a_fkdisk2);

    path+=".dsk";
    cout<<"----"<<path<<endl;

    bool flagf=true;

    FILE *file;
    file= fopen(path.c_str(),"rb+");
    
    if(file==NULL){
        cout<<"El disco no existe."<<endl;
    }else{
        
        
        fseek(file,0,SEEK_SET);
        MBR mbr;
        fread(&mbr,sizeof(MBR),1,file);
        cout<<"hola 2"<<endl;
        cout<<mbr.mbr_tamano<<endl;

        std::cout<<mbr.mbr_partition_1.part_status<<endl;
    
        if(a_fkdisk2[3]=="m"){
            cout<<"hola 3"<<endl;
            sizefdisk=stoi(a_fkdisk2[0])*1024*1024;
        }else if(a_fkdisk2[3]=="K"){
            cout<<"hola 4"<<endl;
            sizefdisk=stoi(a_fkdisk2[0])*1024;
        }else if(a_fkdisk2[3]=="b"){
            
            sizefdisk=stoi(a_fkdisk2[0]);
        } 


        if(a_fkdisk2[4]=="p" || a_fkdisk2[4]=="e"){
            cout<<"hola 5"<<endl;
        
            cout<<"hola 6"<<endl;
            if(mbr.mbr_partition_1.part_status=='0' && mbr.mbr_partition_2.part_status=='0' && mbr.mbr_partition_3.part_status=='0' && mbr.mbr_partition_4.part_status=='0'){
                cout<<"Todas las particiones estan ocupadas";
                flagf==false;
                
            }
        }


        if(a_fkdisk2[4]=="e"){
            if(existeE(mbr)==true){
                cout<<"Ya existe una particion extendida en "<<a_fkdisk2[2]<<endl;
                flagf=false;
                
            }
        }else if(a_fkdisk2[4]=="l"){
            if(existeE(mbr)==false){
                cout<<"No existe un particion extendida en "<<a_fkdisk2[2]<<" entonces no se puede crear la particion logica."<<endl;
                flagf=false;
                
            }

        }


        if(a_fkdisk2[4]=="l" && flagf==true){
            //se puede crear particion l
        }else{
            //se puede crear particion extendida o primaria
            cout<<"hola 7"<<endl;
            bool hayespacio=false;
            int espaciototal=mbr.mbr_tamano - sizeof(mbr);
            int arreglo_espacios[4];
            int esp1=0;
            int esp2=0;
            int esp3=0;
            int esp4=0;

            int arr1=0;
            int arr2=0;
            int arr3=0;
            int arr4=0;

            if(mbr.mbr_partition_1.part_status=='e' && mbr.mbr_partition_2.part_status=='e' && mbr.mbr_partition_3.part_status=='e' && mbr.mbr_partition_4.part_status=='e' ){
                cout<<"entre 0"<<endl;
                if(sizefdisk<= espaciototal){
                    cout<<"entre"<<endl;
                    cout<<mbr.mbr_tamano<<endl;
                    cout<<espaciototal<<endl;
                    mbr.mbr_partition_1.part_status='0';
                    mbr.mbr_partition_1.part_fit=*a_fkdisk2[5].c_str();
                    strcpy(mbr.mbr_partition_1.part_name,a_fkdisk2[2].c_str());
                    mbr.mbr_partition_1.part_size=sizefdisk;
                    mbr.mbr_partition_1.part_start=espaciototal;
                    mbr.mbr_partition_1.part_type=*a_fkdisk2[4].c_str();

                    std::cout<<mbr.mbr_partition_1.part_status<<endl;

                    rewind(file);
                    fwrite(&mbr,sizeof(MBR),1,file);
                }
            }else{
                cout<<"else"<<endl;
                if(mbr.mbr_partition_1.part_status!='e'){
                    esp1=mbr.mbr_partition_1.part_size;
                    arr1=mbr.mbr_partition_1.part_start;
                }

                if(mbr.mbr_partition_2.part_status!='e'){
                    esp2=mbr.mbr_partition_2.part_size;
                    arr2=mbr.mbr_partition_2.part_start;
                }

                if(mbr.mbr_partition_3.part_status!='e'){
                    esp3=mbr.mbr_partition_3.part_size;
                    arr3=mbr.mbr_partition_3.part_start;
                }

                if(mbr.mbr_partition_4.part_status!='e'){
                    esp4=mbr.mbr_partition_4.part_size;
                    arr4=mbr.mbr_partition_4.part_start;
                }

                espaciototal=mbr.mbr_tamano - sizeof(mbr) - esp1 -esp2 -esp3 -esp4;
                cout<<sizefdisk<<"----"<<espaciototal<<endl;
                if(sizefdisk<=espaciototal){
                    cout<<"entre compa"<<endl;
                    arreglo_espacios[0]=esp1;
                    arreglo_espacios[1]=esp2;
                    arreglo_espacios[2]=esp3;
                    arreglo_espacios[3]=esp4;

                    int arreglo_start[4];

                    arreglo_start[0]=arr1;
                    arreglo_start[1]=arr2;
                    arreglo_start[2]=arr3;
                    arreglo_start[3]=arr4;


                    int espaciodispo;
                    int arreglolibre[4];
                    for (int i = 0; i < 4; i++){

    
                        arreglo_start[i]=arreglo_start[i-1]+arreglo_espacios[i-1];
                        espaciodispo=mbr.mbr_tamano -arreglo_start[i];
                        
                        
                        
                        for (int j = i; j < 4; j++){
                            if(arreglo_espacios[j]!=0){
                                espaciodispo=arreglo_start[j] - arreglo_start[i];
                                break;
                                
                                
                            }

                                
                        }
                        
                        arreglolibre[i]=espaciodispo;
                        
                            
                        
                    }
                    
                    for(int x=0; x<4; x++){
                        cout<<"arreglo LIBRE"<<endl;
                        cout<<arreglolibre[x]<<endl;
                    }

                    if(a_fkdisk2[5]=="ff"){

                        for (int i = 0; i < 4; i++){
                            if(sizefdisk<=arreglolibre[i]){
                                if(i==0){
                                    mbr.mbr_partition_1.part_status='0';
                                    mbr.mbr_partition_1.part_fit=*a_fkdisk2[5].c_str();
                                    strcpy(mbr.mbr_partition_1.part_name,a_fkdisk2[2].c_str());
                                    mbr.mbr_partition_1.part_size=sizefdisk;
                                    mbr.mbr_partition_1.part_start=espaciototal;
                                    mbr.mbr_partition_1.part_type=*a_fkdisk2[4].c_str();

                                    //std::cout<<mbr.mbr_partition_1.part_status<<endl;

                                    rewind(file);
                                    fwrite(&mbr,sizeof(MBR),1,file);
                                    break;

                                }else if(i==1){
                                    mbr.mbr_partition_2.part_status='0';
                                    mbr.mbr_partition_2.part_fit=*a_fkdisk2[5].c_str();
                                    strcpy(mbr.mbr_partition_2.part_name,a_fkdisk2[2].c_str());
                                    mbr.mbr_partition_2.part_size=sizefdisk;
                                    mbr.mbr_partition_2.part_start=espaciototal;
                                    mbr.mbr_partition_2.part_type=*a_fkdisk2[4].c_str();

                                    //std::cout<<mbr.mbr_partition_1.part_status<<endl;

                                    rewind(file);
                                    fwrite(&mbr,sizeof(MBR),1,file);
                                    break;

                                }else if(i==2){
                                    mbr.mbr_partition_3.part_status='0';
                                    mbr.mbr_partition_3.part_fit=*a_fkdisk2[5].c_str();
                                    strcpy(mbr.mbr_partition_3.part_name,a_fkdisk2[2].c_str());
                                    mbr.mbr_partition_3.part_size=sizefdisk;
                                    mbr.mbr_partition_3.part_start=espaciototal;
                                    mbr.mbr_partition_3.part_type=*a_fkdisk2[4].c_str();

                                    //std::cout<<mbr.mbr_partition_1.part_status<<endl;

                                    rewind(file);
                                    fwrite(&mbr,sizeof(MBR),1,file);
                                    break;

                                }else if(i==3){
                                    mbr.mbr_partition_4.part_status='0';
                                    mbr.mbr_partition_4.part_fit=*a_fkdisk2[5].c_str();
                                    strcpy(mbr.mbr_partition_4.part_name,a_fkdisk2[2].c_str());
                                    mbr.mbr_partition_4.part_size=sizefdisk;
                                    mbr.mbr_partition_4.part_start=espaciototal;
                                    mbr.mbr_partition_4.part_type=*a_fkdisk2[4].c_str();

                                    //std::cout<<mbr.mbr_partition_1.part_status<<endl;

                                    rewind(file);
                                    fwrite(&mbr,sizeof(MBR),1,file);
                                    break;

                                }
                            }
                        }
                        

                        

                    }else if(a_fkdisk2[5]=="bf"){
                        cout<<"entre bf"<<endl;
                        sort(arreglolibre, arreglolibre + 4);

                        cout<<"es arreglo ordenado: "<<endl;
                        for (int i = 0; i < 4; i++){
                            
                            cout<<arreglolibre[i]<<endl;

                            if(sizefdisk<=arreglolibre[i]){
                                
                                if(i==0){
                                    mbr.mbr_partition_1.part_status='0';
                                    mbr.mbr_partition_1.part_fit=*a_fkdisk2[5].c_str();
                                    strcpy(mbr.mbr_partition_1.part_name,a_fkdisk2[2].c_str());
                                    mbr.mbr_partition_1.part_size=sizefdisk;
                                    mbr.mbr_partition_1.part_start=espaciototal;
                                    mbr.mbr_partition_1.part_type=*a_fkdisk2[4].c_str();

                                    //std::cout<<mbr.mbr_partition_1.part_status<<endl;

                                    rewind(file);
                                    fwrite(&mbr,sizeof(MBR),1,file);
                                    break;

                                }else if(i==1){
                                    mbr.mbr_partition_2.part_status='0';
                                    mbr.mbr_partition_2.part_fit=*a_fkdisk2[5].c_str();
                                    strcpy(mbr.mbr_partition_2.part_name,a_fkdisk2[2].c_str());
                                    mbr.mbr_partition_2.part_size=sizefdisk;
                                    mbr.mbr_partition_2.part_start=espaciototal;
                                    mbr.mbr_partition_2.part_type=*a_fkdisk2[4].c_str();

                                    //std::cout<<mbr.mbr_partition_1.part_status<<endl;

                                    rewind(file);
                                    fwrite(&mbr,sizeof(MBR),1,file);
                                    break;

                                }else if(i==2){
                                    mbr.mbr_partition_3.part_status='0';
                                    mbr.mbr_partition_3.part_fit=*a_fkdisk2[5].c_str();
                                    strcpy(mbr.mbr_partition_3.part_name,a_fkdisk2[2].c_str());
                                    mbr.mbr_partition_3.part_size=sizefdisk;
                                    mbr.mbr_partition_3.part_start=espaciototal;
                                    mbr.mbr_partition_3.part_type=*a_fkdisk2[4].c_str();

                                    //std::cout<<mbr.mbr_partition_1.part_status<<endl;

                                    rewind(file);
                                    fwrite(&mbr,sizeof(MBR),1,file);
                                    break;

                                }else if(i==3){
                                    mbr.mbr_partition_4.part_status='0';
                                    mbr.mbr_partition_4.part_fit=*a_fkdisk2[5].c_str();
                                    strcpy(mbr.mbr_partition_4.part_name,a_fkdisk2[2].c_str());
                                    mbr.mbr_partition_4.part_size=sizefdisk;
                                    mbr.mbr_partition_4.part_start=espaciototal;
                                    mbr.mbr_partition_4.part_type=*a_fkdisk2[4].c_str();

                                    //std::cout<<mbr.mbr_partition_1.part_status<<endl;

                                    rewind(file);
                                    fwrite(&mbr,sizeof(MBR),1,file);
                                    break;

                                }

                            }
                            
                        }
                        

                        /*int espaciopart;
                        int sizepart;
                        int startpart;

                        for (int i = 0; i < 4; i++){
                            if(arreglo_espacios[i]!=0 ){
                                sizepart=arreglo_espacios[i];

                                if(i==0){
                                    startpart=mbr.mbr_partition_1.part_start ;
                                    
                                }else if(i==1){
                                    startpart=mbr.mbr_partition_2.part_start ;
                                    //arreglo_libre[1]=startpart;
                                }else if(i==2){
                                    startpart=mbr.mbr_partition_3.part_start ;
                                    //arreglo_libre[2]=startpart;
                                }else if(i==3){
                                    startpart=mbr.mbr_partition_4.part_start ;
                                    //arreglo_libre[3]=startpart;
                                }
                                espaciopart=sizepart+startpart;
                                
                                
                            }
                        }*/
                        
                        
                    

                    }else if(a_fkdisk2[5]=="wf"){
                        cout<<"entre bf"<<endl;
                        
                        sort(arreglolibre, arreglolibre + 4);

                        cout<<"es arreglo ordenado: "<<endl;
                        int cont1=0;
                        for (int i = 1; i<=4 ; i++){
                            cont1=4-i;
                            cout<<arreglolibre[cont1]<<endl;

                            if(sizefdisk<=arreglolibre[i]){
                                
                                if(i==0){
                                    mbr.mbr_partition_1.part_status='0';
                                    mbr.mbr_partition_1.part_fit=*a_fkdisk2[5].c_str();
                                    strcpy(mbr.mbr_partition_1.part_name,a_fkdisk2[2].c_str());
                                    mbr.mbr_partition_1.part_size=sizefdisk;
                                    mbr.mbr_partition_1.part_start=espaciototal;
                                    mbr.mbr_partition_1.part_type=*a_fkdisk2[4].c_str();

                                    //std::cout<<mbr.mbr_partition_1.part_status<<endl;

                                    rewind(file);
                                    fwrite(&mbr,sizeof(MBR),1,file);
                                    break;

                                }else if(i==1){
                                    mbr.mbr_partition_2.part_status='0';
                                    mbr.mbr_partition_2.part_fit=*a_fkdisk2[5].c_str();
                                    strcpy(mbr.mbr_partition_2.part_name,a_fkdisk2[2].c_str());
                                    mbr.mbr_partition_2.part_size=sizefdisk;
                                    mbr.mbr_partition_2.part_start=espaciototal;
                                    mbr.mbr_partition_2.part_type=*a_fkdisk2[4].c_str();

                                    //std::cout<<mbr.mbr_partition_1.part_status<<endl;

                                    rewind(file);
                                    fwrite(&mbr,sizeof(MBR),1,file);
                                    break;

                                }else if(i==2){
                                    mbr.mbr_partition_3.part_status='0';
                                    mbr.mbr_partition_3.part_fit=*a_fkdisk2[5].c_str();
                                    strcpy(mbr.mbr_partition_3.part_name,a_fkdisk2[2].c_str());
                                    mbr.mbr_partition_3.part_size=sizefdisk;
                                    mbr.mbr_partition_3.part_start=espaciototal;
                                    mbr.mbr_partition_3.part_type=*a_fkdisk2[4].c_str();

                                    //std::cout<<mbr.mbr_partition_1.part_status<<endl;

                                    rewind(file);
                                    fwrite(&mbr,sizeof(MBR),1,file);
                                    break;

                                }else if(i==3){
                                    mbr.mbr_partition_4.part_status='0';
                                    mbr.mbr_partition_4.part_fit=*a_fkdisk2[5].c_str();
                                    strcpy(mbr.mbr_partition_4.part_name,a_fkdisk2[2].c_str());
                                    mbr.mbr_partition_4.part_size=sizefdisk;
                                    mbr.mbr_partition_4.part_start=espaciototal;
                                    mbr.mbr_partition_4.part_type=*a_fkdisk2[4].c_str();

                                    //std::cout<<mbr.mbr_partition_1.part_status<<endl;

                                    rewind(file);
                                    fwrite(&mbr,sizeof(MBR),1,file);
                                    break;

                                }

                            }
                            
                        }

                    }
                }


            }





            

            

            

        }

        
    }

    fclose(file);

    file = fopen(path.c_str(),"rb+");
    MBR mbr2;
    fseek(file,0,SEEK_SET);
    fread(&mbr2,sizeof(MBR),1,file);


    cout<<"---------------"<<endl;
    std::cout<<mbr2.mbr_partition_1.part_fit<<endl;
    std::cout<<mbr2.mbr_partition_1.part_name<<endl;
    std::cout<<mbr2.mbr_partition_1.part_size<<endl;
    std::cout<<mbr2.mbr_partition_1.part_start<<endl;
    std::cout<<mbr2.mbr_partition_1.part_status<<endl;
    std::cout<<mbr2.mbr_partition_1.part_type<<endl;


    cout<<"---------------"<<endl;
    std::cout<<mbr2.mbr_partition_2.part_fit<<endl;
    std::cout<<mbr2.mbr_partition_2.part_name<<endl;
    std::cout<<mbr2.mbr_partition_2.part_size<<endl;
    std::cout<<mbr2.mbr_partition_2.part_start<<endl;
    std::cout<<mbr2.mbr_partition_2.part_status<<endl;
    std::cout<<mbr2.mbr_partition_2.part_type<<endl;
    fclose(file);    


}


void fdisk_add(string a_fdisk3[]){
    
    
    string path;
    int sizefdisk1=0;
    path =pathsinC(a_fdisk3);
    path+=".dsk";
    FILE *file;
    file= fopen(path.c_str(),"rb+");
    
    if(file==NULL){
        cout<<"El disco no existe."<<endl;
    }else{
        
        fseek(file,0,SEEK_SET);
        MBR mbr;
        fread(&mbr,sizeof(MBR),1,file);
        
        int espaciototal=mbr.mbr_tamano - sizeof(mbr);
        int arreglo_espacios[4];
        int esp1=0;
        int esp2=0;
        int esp3=0;
        int esp4=0;

        int arr1=0;
        int arr2=0;
        int arr3=0;
        int arr4=0;
        
        if(a_fdisk3[3]=="m" || a_fdisk3[3]=="M"  ){
        //cout<<"hola 3"<<endl;
        sizefdisk1=stoi(a_fdisk3[7])*1024*1024;
        }else if(a_fdisk3[3]=="K" || a_fdisk3[3]=="k" ){
            
            sizefdisk1=stoi(a_fdisk3[7])*1024;
            
        }else if(a_fdisk3[3]=="b" || a_fdisk3[3]=="B" ){
            
            sizefdisk1=stoi(a_fdisk3[7]);
        }    

        cout<<sizefdisk1<<endl;

        if(mbr.mbr_partition_1.part_status!='e'){
            esp1=mbr.mbr_partition_1.part_size;
            arr1=mbr.mbr_partition_1.part_start;
        }

        if(mbr.mbr_partition_2.part_status!='e'){
            esp2=mbr.mbr_partition_2.part_size;
            arr2=mbr.mbr_partition_2.part_start;
        }

        if(mbr.mbr_partition_3.part_status!='e'){
            esp3=mbr.mbr_partition_3.part_size;
            arr3=mbr.mbr_partition_3.part_start;
        }

        if(mbr.mbr_partition_4.part_status!='e'){
            esp4=mbr.mbr_partition_4.part_size;
            arr4=mbr.mbr_partition_4.part_start;
        }

        espaciototal=mbr.mbr_tamano - sizeof(mbr) - esp1 -esp2 -esp3 -esp4;
        cout<<sizefdisk1<<"----"<<espaciototal<<endl;
        if(sizefdisk1<=espaciototal){
            cout<<"entre compa"<<endl;
            arreglo_espacios[0]=esp1;
            arreglo_espacios[1]=esp2;
            arreglo_espacios[2]=esp3;
            arreglo_espacios[3]=esp4;

            int arreglo_start[4];

            arreglo_start[0]=arr1;
            arreglo_start[1]=arr2;
            arreglo_start[2]=arr3;
            arreglo_start[3]=arr4;


            int espaciodispo;
            int arreglolibre[4];
            for (int i = 0; i < 4; i++){


                arreglo_start[i]=arreglo_start[i-1]+arreglo_espacios[i-1];
                espaciodispo=mbr.mbr_tamano -arreglo_start[i];
                
                
                
                for (int j = i; j < 4; j++){
                    if(arreglo_espacios[j]!=0){
                        espaciodispo=arreglo_start[j] - arreglo_start[i];
                        break;
                        
                        
                    }

                        
                }
                
                arreglolibre[i]=espaciodispo;
                
                    
                
            }
            
            for(int x=0; x<4; x++){
                cout<<"arreglo LIBRE"<<endl;
                cout<<arreglolibre[x]<<endl;
            }
            cout<<a_fdisk3[2]<<endl;
            int valor =10;

            if(a_fdisk3[2]==mbr.mbr_partition_1.part_name){
                valor=0;

            }else if(a_fdisk3[2]==mbr.mbr_partition_2.part_name){
                valor=1;

            }else if(a_fdisk3[2]==mbr.mbr_partition_3.part_name){
                valor=2;

            }else if(a_fdisk3[2]==mbr.mbr_partition_4.part_name){
                valor=3;

            }

            if(valor==10){
                cout<<"El nombre no coincide de la particion a la que desea add espacio"<<endl;
            }else{
                if(valor==0){
                    if(arreglolibre[valor+1]==0){
                        cout<<"No se puede agregar tamaño en la particion"<<endl;
                    }else{
                        
                        mbr.mbr_partition_1.part_size+=sizefdisk1;
                        

                        std::cout<<mbr.mbr_partition_1.part_status<<endl;

                        rewind(file);
                        fwrite(&mbr,sizeof(MBR),1,file);
                        


                    }
            
                    
                }else if(valor==1){
                    if(arreglolibre[valor+1]!=0){
                        
                        cout<<"---AGREGANDO VALOR------"<<endl;
                        mbr.mbr_partition_2.part_size+=sizefdisk1;
                        

                        std::cout<<mbr.mbr_partition_2.part_size<<endl;

                        rewind(file);
                        fwrite(&mbr,sizeof(MBR),1,file);
                        


                    }else if(arreglolibre[valor-1]!=0){
                        
                        cout<<"---AGREGANDO VALOR------"<<endl;
                        mbr.mbr_partition_2.part_start-=sizefdisk1;
                        
                        

                        std::cout<<mbr.mbr_partition_2.part_start<<endl;

                        rewind(file);
                        fwrite(&mbr,sizeof(MBR),1,file);
                        


                    }else{
                        cout<<"No se pudo agregar tamano a la particion"<<endl;
                    }

                }
            }


            /*for (int i = 0; i < 4; i++){
                
            }*/
            
        }
    }

    fclose(file);

    file = fopen(path.c_str(),"rb+");
    MBR mbr2;
    fseek(file,0,SEEK_SET);
    fread(&mbr2,sizeof(MBR),1,file);


    cout<<"---------------"<<endl;
    std::cout<<mbr2.mbr_partition_1.part_fit<<endl;
    std::cout<<mbr2.mbr_partition_1.part_name<<endl;
    std::cout<<mbr2.mbr_partition_1.part_size<<endl;
    std::cout<<mbr2.mbr_partition_1.part_start<<endl;
    std::cout<<mbr2.mbr_partition_1.part_status<<endl;
    std::cout<<mbr2.mbr_partition_1.part_type<<endl;


    cout<<"---------------"<<endl;
    std::cout<<mbr2.mbr_partition_2.part_fit<<endl;
    std::cout<<mbr2.mbr_partition_2.part_name<<endl;
    std::cout<<mbr2.mbr_partition_2.part_size<<endl;
    std::cout<<mbr2.mbr_partition_2.part_start<<endl;
    std::cout<<mbr2.mbr_partition_2.part_status<<endl;
    std::cout<<mbr2.mbr_partition_2.part_type<<endl;
    
    

}

    
            
    