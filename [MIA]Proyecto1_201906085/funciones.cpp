#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <cstring>
#include <algorithm>
#include "strucs.cpp"


using namespace std;

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
        cout<<"hola 1"<<endl;
        
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


    
            
    