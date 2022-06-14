#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <cstring>
#include "strucs.cpp"


using namespace std;



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
    cout<<"jijijija"<<endl;
    mbr.mbr_partition_1.part_status='0';
    cout<<"jijijija 2"<<endl;
    mbr.mbr_partition_1.part_fit='-';
    mbr.mbr_partition_1.part_name[0]='\0';
    mbr.mbr_partition_1.part_size=-1;
    mbr.mbr_partition_1.part_start=-1;
    mbr.mbr_partition_1.part_type='-';
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
            int espacio;

            if(mbr.mbr_partition_1.part_status=='0'){
                cout<<"hola 8"<<endl;
                
                mbr.mbr_partition_1.part_start= sizeof(mbr);
                espacio=mbr.mbr_tamano - sizeof(mbr);
                cout<<mbr.mbr_tamano<<"----"<<sizeof(mbr)<<"="<<espacio<<endl;
                
                if(mbr.mbr_partition_1.part_status=='1'){
                    cout<<"hola 9"<<endl;
                    espacio=mbr.mbr_partition_1.part_start - sizeof(mbr);
                    cout<<espacio<<endl;


                }else if(mbr.mbr_partition_2.part_status=='0'){
                    espacio=mbr.mbr_partition_2.part_start - sizeof(mbr);

                }else if(mbr.mbr_partition_3.part_status=='0'){
                    espacio=mbr.mbr_partition_3.part_start - sizeof(mbr);

                }else if(mbr.mbr_partition_4.part_status=='0'){
                    espacio=mbr.mbr_partition_4.part_start - sizeof(mbr);
                }

                cout<<"hola 10 "<< sizefdisk<<"---" << espacio<<endl;
                if(sizefdisk <= espacio){
                    hayespacio=true;
                    
                }

            }else if(mbr.mbr_partition_2.part_status=='0'){
                mbr.mbr_partition_2.part_start=mbr.mbr_partition_1.part_start+mbr.mbr_partition_1.part_size;
                espacio= mbr.mbr_tamano-mbr.mbr_partition_2.part_start;

                if(mbr.mbr_partition_1.part_status=='0'){
                    espacio=mbr.mbr_partition_1.part_start - mbr.mbr_partition_2.part_start;
                }

                if(sizefdisk<=espacio){
                    hayespacio=true;
                }


            }else if(mbr.mbr_partition_3.part_status=='0'){
                mbr.mbr_partition_3.part_start=mbr.mbr_partition_2.part_start+mbr.mbr_partition_2.part_size;
                espacio= mbr.mbr_tamano-mbr.mbr_partition_3.part_start;

                if(mbr.mbr_partition_1.part_status=='0'){
                    espacio=mbr.mbr_partition_2.part_start -mbr.mbr_partition_3.part_start;
                }

                if(sizefdisk<=espacio){
                    hayespacio=true;
                }

            }else if(mbr.mbr_partition_4.part_status=='0'){
                mbr.mbr_partition_4.part_start=mbr.mbr_partition_3.part_start+mbr.mbr_partition_3.part_size;
                espacio= mbr.mbr_tamano-mbr.mbr_partition_4.part_start;

                if(mbr.mbr_partition_1.part_status=='0'){
                    espacio=mbr.mbr_partition_3.part_start -mbr.mbr_partition_4.part_start;
                }

                if(sizefdisk<=espacio){
                    hayespacio=true;
                }

            }

            if(hayespacio==true){
                cout<<"hola 10"<<endl;

                //char type=a_fkdisk2[4].c_str();
                partition* part = (partition*) malloc(sizeof(partition));
                part->part_status='0';
                part->part_type= *a_fkdisk2[4].c_str();
                part->part_fit=*a_fkdisk2[5].c_str();
                part->part_start=espacio;
                part->part_size= sizefdisk;
                strcpy(part->part_name,a_fkdisk2[2].c_str());
                if(mbr.mbr_partition_1.part_status == '0') mbr.mbr_partition_1 = *part;
                else if(mbr.mbr_partition_2.part_status == '0') mbr.mbr_partition_2 = *part;
                else if(mbr.mbr_partition_3.part_status == '0') mbr.mbr_partition_3 = *part;
                else if(mbr.mbr_partition_4.part_status == '0') mbr.mbr_partition_4 = *part;

                rewind(file);
                fwrite(&mbr,sizeof(MBR),1,file);
            }else{
                cout<<"no se pudo crear particion"<<endl;
            }

            

            

        }

        
    }

    fclose(file);

    file = fopen(path.c_str(),"rb+");
    MBR mbr2;
    fseek(file,0,SEEK_SET);
    fread(&mbr2,sizeof(MBR),1,file);

    std::cout<<mbr2.mbr_partition_1.part_name<<endl;

    fclose(file);    


}