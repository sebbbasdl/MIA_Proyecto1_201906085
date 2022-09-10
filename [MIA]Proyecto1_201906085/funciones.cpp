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

#define STRING(num) #num
using namespace std;

string arregloMountId[20];
string arregloMountPath[20];
string arregloMountPart[20];
int contadorMount=0;
string arregloletra[20];
string arregloDiscos[20];
int contadorDiscos1=0;
int contadorMount2=0;
string infoEXT;
bool activa=false;

string usuario_actual;
string path_actual;


void crearArchivo_UyG(string path){
    ofstream archivo;

    archivo.open(path, ios::out);
    if(archivo.fail()){
        cout<<"No se pudo crear el archivo raiz usuarios y grupos"<<endl;
    }

    archivo<<"1,G,root"<<endl;
    archivo<<"1,U,root,root,123";
    archivo.close();
}

string abecedario(int conta){
    string letra;
    if(conta==0){
        letra="a";

    }else if(conta==1){
        letra="b";

    }else if(conta==2){
        letra="c";

    }else if(conta==3){
        letra="d";

    }else if(conta==4){
        letra="e";

    }else if(conta==5){
        letra="f";

    }else if(conta==6){
        letra="g";

    }else if(conta==7){
        letra="h";

    }else if(conta==8){
        letra="i";

    }else if(conta==9){
        letra="j";

    }else if(conta==10){
        letra="k";

    }else if(conta==11){
        letra="l";

    }else if(conta==12){
        letra="m";

    }else if(conta==13){
        letra="n";

    }else if(conta==14){
        letra="ñ";

    }else if(conta==15){
        letra="o";

    }else if(conta==16){
        letra="p";

    }else if(conta==17){
        letra="q";

    }else if(conta==18){
        letra="r";

    }

    return letra;
}
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
    if(directorio=opendir(rut.c_str())){
        closedir(directorio);
        return true;
    }else{
        return false;
    }
}

bool existeArchivo(string ruta){
    FILE *archivo;
    if(archivo=fopen(ruta.c_str(),"r")){

        fclose(archivo);
        return true;
    }else{
        return false;
    }
}

void reportes(string a_rep[]){
    
    bool flag=false;
    bool flag2=false;
    string rutacreada;
    string aux;
    
    aux=pathsinC2(a_rep);
    cout<<aux<<endl;

    if(existeArchivo(aux)==true){
        cout<<"El archivo del reporte ya existe"<<endl;
        
        
    
    }else{
        
        int conta=0;
        int contslash=0;
        conta=aux.length();
        //cout<<conta<<endl;
        for (int i = 0; i < conta; i++){
            if(aux[i]=='/'){
                contslash=i;
                //cout<<contslash<<endl;
                
            }
        }
        //cout<<contslash<<endl;
        for (int i = 0; i < contslash; i++){
            rutacreada+=aux[i];
        }
        
        
    }
    rutacreada+="/";
    //cout<<rutacreada<<endl;
    //cout<<existeDirectorio(rutacreada)<<endl;
    if(existeDirectorio(rutacreada)==true){
        int x;
    }else{
        string arreglopath[30];
        string dato;
        int contaa =0;
        
        //cout<<rutacreada.length()<<endl;
        for (int i = 0; i < rutacreada.length(); i++){
            
            if(rutacreada[i] == '/'){
                
                arreglopath[contaa]=dato;
                dato="";
                contaa+=1;
            }else{
                dato+=rutacreada[i];
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
    }

    int lugar=0;
    cout<<"aqui 10"<<endl;
    int auxcont;
    
    for (int x = 0; x < contadorMount; x++){
        if(a_rep[2]==/*arregloMountId[x]*/arregloMountId[x]){
            
            //if(a_rep[0]==mbr.mbr_partition_1.part_name || a_rep[0]==mbr.mbr_partition_2.part_name || a_rep[0]==mbr.mbr_partition_3.part_name || a_rep[0]==mbr.mbr_partition_4.part_name) {
                flag=true;
                lugar=x;
                break;
            //}
        auxcont+=1;

        }
    }
    cout<<"aqui 10"<<endl;
    
    FILE *file;
    file= fopen(arregloMountPath[lugar].c_str(),"rb+");
    
    fseek(file,0,SEEK_SET);
    MBR mbr;
    fread(&mbr,sizeof(MBR),1,file);
    cout<<"aqui 10"<<endl;
    
    
    string tamano(STRING(mbr.mbr_tamano));
    string fecha=ctime( &mbr.mbr_fecha_creacion);
    string signature(STRING(mbr.mbr_disk_signature));
    string arreglosize[4]={};
    
    string startp1(STRING(mbr.mbr_partition_1.part_start));
    string startp2(STRING(mbr.mbr_partition_2.part_start));
    string startp3(STRING(mbr.mbr_partition_3.part_start));
    string startp4(STRING(mbr.mbr_partition_4.part_start));

    string size1(STRING(mbr.mbr_partition_1.part_size));
    string size2(STRING(mbr.mbr_partition_2.part_size));
    string size3(STRING(mbr.mbr_partition_3.part_size));
    string size4(STRING(mbr.mbr_partition_4.part_size));
    string dot;
    
    if(flag==true && a_rep[0]=="mbr"){
        
        ofstream archivodot(rutacreada+a_rep[2]+".dot");
        
        dot+="digraph{\n";
        dot+="node[shape=none fontname=Helvetica] \n";
        dot+="n [ label = <\n";
        dot+="<table border=\"3\" bgcolor=\"black\" color=\"yellow\">\n";
        dot+="<tr>\n";
        dot+="<td bgcolor=\"red\">MBR</td>\n";
        dot+="</tr>\n";
        dot+="<tr>\n";
        dot+="<td bgcolor=\"red\">Tamaño: "+std::to_string(mbr.mbr_tamano)  ;
        dot+="</td>\n";
        dot+="</tr>\n";
        dot+="<tr>\n";
        dot+="<td bgcolor=\"red\">Fecha de creacion: "+fecha;
        dot+="</td>\n";
        dot+="</tr>\n";
        dot+="<tr>\n";
        dot+="<td bgcolor=\"red\">disk_signature: "+std::to_string(mbr.mbr_disk_signature);
        dot+="</td>\n";
        dot+="</tr>\n";
        dot+="<tr>\n";
        dot+="<td bgcolor=\"red\">:partition_1.part_status: ";
        dot.append(0,mbr.mbr_partition_1.part_status);
        dot+="</td>\n";
        dot+="</tr>\n";
        dot+="<tr>\n";
        dot+="<td bgcolor=\"red\">:partition_1.part_type: ";
        dot+="\n \n";
        dot.append(0,mbr.mbr_partition_1.part_type);
        dot+="</td>\n";
        dot+="</tr>\n";
        dot+="<tr>\n";
        dot+="<td bgcolor=\"red\">:partition_1.part_fit: ";
        dot.append(0,mbr.mbr_partition_1.part_fit);
        dot+="f </td>\n";
        dot+="</tr>\n";
        dot+="<tr>\n";
        dot+="<td bgcolor=\"red\">:partition_1.part_start: "+std::to_string(mbr.mbr_partition_1.part_start);
        dot+="</td>\n";
        dot+="</tr>\n";
        dot+="<tr>\n";
        dot+="<td bgcolor=\"red\">:partition_1.part_size: "+std::to_string(mbr.mbr_partition_1.part_size);
        dot+="</td>\n";
        dot+="</tr>\n";
        dot+="<tr>\n";
        dot+="<tdb gcolor=\"red\">:partition_1.part_name: "+mbr.mbr_partition_1.part_name[16];
        dot+="</td>\n";
        dot+="</tr>\n";
    


        dot+="<tr>\n";
        dot+="<td bgcolor=\"red\">:partition_2.part_status: ";
        dot.append(0,mbr.mbr_partition_2.part_status);
        dot+="</td>\n";
        dot+="</tr>\n";
        dot+="<tr>\n";
        dot+="<td bgcolor=\"red\">:partition_2.part_type: ";
        dot+="\n \n";
        dot.append(0,mbr.mbr_partition_2.part_type);
        dot+="</td>\n";
        dot+="</tr>\n";
        dot+="<tr>\n";
        dot+="<td bgcolor=\"red\">:partition_2.part_fit: ";
        dot.append(0,mbr.mbr_partition_2.part_fit);
        dot+="f</td>\n";
        dot+="</tr>\n";
        dot+="<tr>\n";
        dot+="<td bgcolor=\"red\">:partition_2.part_start: "+std::to_string(mbr.mbr_partition_2.part_start);
        dot+="</td>\n";
        dot+="</tr>\n";
        dot+="<tr>\n";
        dot+="<td bgcolor=\"red\">:partition_2.part_size: "+std::to_string(mbr.mbr_partition_2.part_size);
        dot+="</td>\n";
        dot+="</tr>\n";
        dot+="<tr>\n";
        dot+="<td bgcolor=\"red\">:partition_2.part_name: "+mbr.mbr_partition_2.part_name[16];
        dot+="</td>\n";
        dot+="</tr>\n";
        

        dot+="<tr>\n";
        dot+="<td bgcolor=\"red\">partition_3.part_status: ";
        dot.append(0,mbr.mbr_partition_3.part_status);
        dot+="</td>\n";
        dot+="</tr>\n";
        dot+="<tr>\n";
        dot+="<td bgcolor=\"red\">partition_3.part_type: ";
        dot+="\n";
        dot.append(0,mbr.mbr_partition_3.part_type);
        dot+="</td>\n";
        dot+="</tr>\n";
        dot+="<tr>\n";
        dot+="<td bgcolor=\"red\">:partition_3.part_fit: ";
        dot+="\n \n";
        dot.append(0,mbr.mbr_partition_3.part_fit);
        dot+="f </td>\n";
        dot+="</tr>\n";
        dot+="<tr>\n";
        dot+="<td bgcolor=\"red\">partition_3.part_start: "+std::to_string(mbr.mbr_partition_3.part_start);
        dot+="</td>\n";
        dot+="</tr>\n";
        dot+="<tr>\n";
        dot+="<td bgcolor=\"red\">partition_3.part_size: "+std::to_string(mbr.mbr_partition_3.part_size);
        dot+="</td>\n";
        dot+="</tr>\n";
        dot+="<tr>\n";
        dot+="<td bgcolor=\"red\">partition_3.part_name: "+mbr.mbr_partition_3.part_name[16];
        dot+="</td>\n";
        dot+="</tr>\n";

        dot+="<tr>\n";
        dot+="<td bgcolor=\"red\">partition_4.part_status: ";
        dot.append(0,mbr.mbr_partition_4.part_status);
        dot+="</td>\n";
        dot+="</tr>\n";
        dot+="<tr>\n";
        dot+="<td bgcolor=\"red\">partition_4.part_type: ";
        dot+="\n \n";
        dot.append(0,mbr.mbr_partition_4.part_type);
        dot+="</td>\n";
        dot+="</tr>\n";
        dot+="<tr>\n";
        dot+="<td bgcolor=\"red\">partition_4.part_fit: ";
        dot.append(0,mbr.mbr_partition_4.part_fit);
        dot+="f </td>\n";
        dot+="</tr>\n";
        dot+="<tr>\n";
        dot+="<td bgcolor=\"red\">:partition_4.part_start: "+std::to_string(mbr.mbr_partition_4.part_start);
        dot+="</td>\n";
        dot+="</tr>\n";
        dot+="<tr>\n";
        dot+="<td bgcolor=\"red\">:partition_4.part_size: "+std::to_string(mbr.mbr_partition_4.part_size);
        dot+="</td>\n";
        dot+="</tr>\n";
        dot+="<tr>\n";
        dot+="<td bgcolor=\"red\">:partition_4.part_name: "+mbr.mbr_partition_4.part_name[16];
        dot+="</td>\n";
        dot+="</tr>\n";
        dot+="</table>\n";
        dot+="> ]\n";
        dot+="}";

        archivodot<<dot;
        string gendot= " dot -Tjpg "+rutacreada+a_rep[2]+".dot " +" -o "+aux;
        string gendot2=" nohup display "+aux +" &";

        system(gendot.c_str());
        system(gendot2.c_str()); 


    }else if(flag==true && a_rep[0]=="disk"){
        
        ofstream archivodot2(rutacreada+a_rep[2]+".dot");
        string dot2;
        dot2+="digraph H {\n";
        dot2+=" parent [shape=plaintext \nlabel=<\n";
        dot2+="<table border='1' cellborder='1'>\n <tr>\n"  ;  

        if(mbr.mbr_partition_1.part_size==-1){
            dot2+="<td port='port_one'>LIBRE</td>\n";

        }else{
            dot2+="<td port='port_one'>PRIMARIA</td>\n";

        }

        if(mbr.mbr_partition_2.part_size==-1){
            dot2+="<td port='port_two'>LIBRE</td>\n";

        }else{
            dot2+="<td port='port_two'>PRIMARIA</td>\n";
            
        }

        if(mbr.mbr_partition_3.part_size==-1){
            dot2+="<td port='port_three'>LIBRE</td>\n";

        }else{
            dot2+="<td port='port_three'>PRIMARIA</td>\n";
            
        }

        if(mbr.mbr_partition_4.part_size==-1){
            dot2+="<td port='port_four'>LIBRE</td>\n";

        }else{
            dot2+="<td port='port_four'>PRIMARIA</td>\n";
            
        }
        dot2+="</tr>";

        dot2+=" </table>\n>];\n}";
        archivodot2<<dot2;
        cout<<dot2<<endl;
        string gendot1= " dot -Tjpg "+rutacreada+a_rep[2]+".dot " +" -o "+aux;
        string gendot22=" nohup display "+aux +" &";

        system(gendot1.c_str());
        system(gendot22.c_str()); 

    }else{
        cout<<"No se pudo generar ya que el id o la particion no existe."<<endl;
    }


    


    //fclose(file);
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
    string nombredisco;
    int poss=0;
    int poss2=0;

    for (int i = 0; i < path.length(); i++){
        if(path[i]=='/'){
            poss=i;
        }

        if(path[i]=='.'){
            poss2=i;
        }
    }

    for (int i = poss+1; i < poss2; i++){
        nombredisco+=path[i];
    }
    
    //cout<<"OOOOOOO "<<nombredisco<<endl;
    

    cout<<path<<endl;
    FILE *file;
    file= fopen(path.c_str(),"rb+");

    if(file==NULL){
        cout<<"El disco al que deseea aplicar mount no existe."<<endl;
    }else{
        fseek(file,0,SEEK_SET);
        MBR mbr;
        fread(&mbr,sizeof(MBR),1,file);    
        //cout<<mbr.mbr_partition_1.part_name<<endl;
        if(contadorDiscos1==0){
            if(mbr.mbr_partition_1.part_name==aux[0]){
            
                
                //cout<<"entre"<<endl;
                mbr.mbr_partition_1.part_status='1';
                //cout<<"-------------------"<<contadorDiscos1<<endl;
                arregloMountId[contadorMount]="85"+std::to_string(contadorMount+1)+nombredisco;
                arregloMountPart[contadorMount]=aux[0];
                arregloMountPath[contadorMount]=path;
                
                contadorMount+=1;
                arregloletra[contadorDiscos1]="a";
                contadorDiscos1+=1;
                rewind(file);
                fwrite(&mbr,sizeof(MBR),1,file);
            }else if( mbr.mbr_partition_2.part_name==aux[0]){
                mbr.mbr_partition_1.part_status=='1';
                arregloMountId[contadorMount]="85"+std::to_string(contadorMount+1)+nombredisco;
                arregloMountPart[contadorMount]=aux[0];
                arregloMountPath[contadorMount]=path;
                contadorMount+=1;
                arregloletra[contadorDiscos1]="a";
                contadorDiscos1+=1;
                rewind(file);
                fwrite(&mbr,sizeof(MBR),1,file);
                
            }else if( mbr.mbr_partition_3.part_name==aux[0]){
                arregloMountId[contadorMount]="85"+std::to_string(contadorMount+1)+nombredisco;
                arregloMountPart[contadorMount]=aux[0];
                arregloMountPath[contadorMount]=path;
                contadorMount+=1;
                mbr.mbr_partition_1.part_status=='1';
                arregloletra[contadorDiscos1]="a";
                contadorDiscos1+=1;
                rewind(file);
                fwrite(&mbr,sizeof(MBR),1,file);
                
            }else if( mbr.mbr_partition_4.part_name==aux[0]){
                arregloMountId[contadorMount]="85"+std::to_string(contadorMount+1)+nombredisco;
                arregloMountPart[contadorMount]=aux[0];
                arregloMountPath[contadorMount]=path;
                contadorMount+=1;
                arregloletra[contadorDiscos1]="a";
                contadorDiscos1+=1;
                rewind(file);
                fwrite(&mbr,sizeof(MBR),1,file);
                
            }else{
                cout<<"Esta particion no existe en el disco con la ruta: "<<aux[1]<<endl;
            }
        cout<<"------STATUS----"<<endl;
        
        

        }else{
            fseek(file,0,SEEK_SET);
            MBR mbr;
            fread(&mbr,sizeof(MBR),1,file); 
            cout<<"mori1"<<endl;
            int contt=1;
            int auxlugar=0;
            for (int i = 0; i < arregloMountPath->length(); i++){
                if(path==arregloMountPath[i]){
                    contt+=1;  
                    cout<<"cont: "<<contt<<endl; 
                    auxlugar=i;
                    cout<<"lugar: "<<auxlugar<<endl; 
                }
            }

            for (int i = 0; i <= arregloletra->length(); i++){
                cout<<arregloletra[i]<<endl;
            }
            
            
            for (int i = 0; i < arregloMountPath->length(); i++){
                if(path==arregloMountPath[i] || contt>1) {
                    cout<<"mori2"<<endl;
                    if(mbr.mbr_partition_1.part_name==aux[0]){
                        cout<<"mori3"<<endl;
                        mbr.mbr_partition_1.part_status='1';
                        
                        arregloMountId[contadorMount]="85"+std::to_string(contadorMount+1)+nombredisco;
                        arregloMountPart[contadorMount]=aux[0];
                        arregloMountPath[contadorMount]=path;
                        arregloletra[contadorMount]=arregloletra[auxlugar];
                        
                        contadorMount+=1;
                        rewind(file);
                        fwrite(&mbr,sizeof(MBR),1,file);
                    break;
                        
                    }else if(mbr.mbr_partition_2.part_name==aux[0]){
                        cout<<"mori3"<<endl;
                        mbr.mbr_partition_2.part_status='1';
                        //cout<<"-------------------"<<contadorDiscos1<<endl;
                        cout<<"ESTO ESSS I : "<<i<<endl;
                        cout<<std::string(arregloletra[i])<<endl;
                        arregloMountId[contadorMount]="85"+std::to_string(contadorMount+1)+nombredisco;
                        arregloMountPart[contadorMount]=aux[0];
                        arregloMountPath[contadorMount]=path;
                        arregloletra[contadorMount]=arregloletra[auxlugar];
                        
                        contadorMount+=1;
                        rewind(file);
                        fwrite(&mbr,sizeof(MBR),1,file);
                    break;
                        
                    }else if(mbr.mbr_partition_3.part_name==aux[0]){
                        cout<<"mori3"<<endl;
                        mbr.mbr_partition_3.part_status='1';
                        //cout<<"-------------------"<<contadorDiscos1<<endl;
                        arregloMountId[contadorMount]="85"+std::to_string(contadorMount+1)+nombredisco;
                        arregloMountPart[contadorMount]=aux[0];
                        arregloMountPath[contadorMount]=path;
                        arregloletra[contadorMount]=arregloletra[auxlugar];
                        
                        contadorMount+=1;
                        rewind(file);
                        fwrite(&mbr,sizeof(MBR),1,file);
                    break;
                        
                    }else if(mbr.mbr_partition_4.part_name==aux[0]){
                        cout<<"mori3"<<endl;
                        mbr.mbr_partition_4.part_status='1';
                        //cout<<"-------------------"<<contadorDiscos1<<endl;
                        arregloMountId[contadorMount]="85"+std::to_string(contadorMount+1)+nombredisco;
                        arregloMountPart[contadorMount]=aux[0];
                        arregloMountPath[contadorMount]=path;
                        arregloletra[contadorMount]=arregloletra[auxlugar];
                        
                        contadorMount+=1;
                        rewind(file);
                        fwrite(&mbr,sizeof(MBR),1,file);
                    break;
                        
                    }

                }else{
                    
                    if(mbr.mbr_partition_1.part_name==aux[0]){
                        cout<<"CONTADOR DISCOSSSS : "<<contadorDiscos1<<endl;
                        
                        
                        mbr.mbr_partition_1.part_status='1';
                        //cout<<"-------------------"<<contadorDiscos1<<endl;
                        cout<<abecedario(2)<<endl;
                        
                        arregloMountId[contadorMount]="85"+std::to_string(contadorMount+1)+nombredisco;
                        
                        arregloMountPart[contadorMount]=aux[0];
                        
                        arregloMountPath[contadorMount]=path;
                        
                        
                        arregloletra[contadorMount]=abecedario(contadorDiscos1);
                        contadorMount+=1;
                        contadorDiscos1+=1;
                        rewind(file);
                        fwrite(&mbr,sizeof(MBR),1,file);
                        
                        contadorDiscos1+=1;
                        break;
                    }else if(mbr.mbr_partition_2.part_name==aux[0]){
                        cout<<"CONTADOR DISCOSSSS : "<<contadorDiscos1<<endl;
                        
                        
                        mbr.mbr_partition_2.part_status='1';
                        //cout<<"-------------------"<<contadorDiscos1<<endl;
                        cout<<abecedario(2)<<endl;
                        
                        arregloMountId[contadorMount]="85"+std::to_string(contadorMount+1)+nombredisco;
                        
                        arregloMountPart[contadorMount]=aux[0];
                        
                        arregloMountPath[contadorMount]=path;
                        
                        
                        
                        arregloletra[contadorMount]=abecedario(contadorDiscos1);
                        contadorMount+=1;
                        contadorDiscos1+=1;
                        rewind(file);
                        fwrite(&mbr,sizeof(MBR),1,file);
                        
                        contadorDiscos1+=1;
                        break;
                    }else if(mbr.mbr_partition_3.part_name==aux[0]){
                        cout<<"CONTADOR DISCOSSSS : "<<contadorDiscos1<<endl;
                        
                        
                        mbr.mbr_partition_3.part_status='1';
                        //cout<<"-------------------"<<contadorDiscos1<<endl;
                        cout<<abecedario(2)<<endl;
                        
                        arregloMountId[contadorMount]="85"+std::to_string(contadorMount+1)+nombredisco;
                        
                        arregloMountPart[contadorMount]=aux[0];
                        
                        arregloMountPath[contadorMount]=path;
                        
                       
                        
                        arregloletra[contadorMount]=abecedario(contadorDiscos1);
                        contadorMount+=1;
                        contadorDiscos1+=1;
                        rewind(file);
                        fwrite(&mbr,sizeof(MBR),1,file);
                        
                        contadorDiscos1+=1;
                        break;
                    }else if(mbr.mbr_partition_4.part_name==aux[0]){
                        cout<<"CONTADOR DISCOSSSS : "<<contadorDiscos1<<endl;
                        
                        
                        mbr.mbr_partition_4.part_status='1';
                        //cout<<"-------------------"<<contadorDiscos1<<endl;
                        cout<<abecedario(2)<<endl;
                        
                        arregloMountId[contadorMount]="85"+std::to_string(contadorMount+1)+nombredisco;
                        
                        arregloMountPart[contadorMount]=aux[0];
                        
                        arregloMountPath[contadorMount]=path;
                        
                        
                        
                        arregloletra[contadorMount]=abecedario(contadorDiscos1);
                        contadorMount+=1;
                        contadorDiscos1+=1;
                        rewind(file);
                        fwrite(&mbr,sizeof(MBR),1,file);
                        
                        contadorDiscos1+=1;
                        break;
                    }
                    
                }
            }
            

            
        }
        
        fclose(file);
    }

    file = fopen(path.c_str(),"rb+");
    MBR mbr2;
    fseek(file,0,SEEK_SET);
    fread(&mbr2,sizeof(MBR),1,file);


    
    std::cout<<mbr2.mbr_partition_1.part_fit<<endl;
    std::cout<<mbr2.mbr_partition_1.part_name<<endl;
    std::cout<<mbr2.mbr_partition_1.part_size<<endl;
    std::cout<<mbr2.mbr_partition_1.part_start<<endl;
    std::cout<<mbr2.mbr_partition_1.part_status<<endl;
    std::cout<<mbr2.mbr_partition_1.part_type<<endl;
    
    fclose(file);

    
}
void onlymount(){
    cout<<contadorMount<<endl;
    for (int i = 0; i < contadorMount; i++){
       cout<< i << " "<<arregloMountId[i]<<" "<<arregloMountPath[i]<<" "<<arregloMountPart[i]<<endl;
        
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

    
    int cont= a_mkdisk2->length();
    for (int i = 0; i <= cont; i++){
      cout<<a_mkdisk2[i]<<endl;
    }

    path =pathsinC2(a_mkdisk2);
    //char path2[255] = "/tmp/d1.dk";
    std::cout<<"ijjija"<<path<<endl;

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
        //arregloDiscos[contadorDiscos1]=contadorDiscos1;
        //contadorDiscos1+=1;
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
        return;
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
    
    fclose(file);

}

string path_sindisco(string path){
    int lugar=0;
    string path2;
    for (int i = 0; i < path.length(); i++){
        if(path[i]=='/'){
            lugar=i;
        }
        
    }

    for (int i = 0; i <= lugar; i++){
        path2+=path[i];
        
    }

    return path2;
    
}

void mkfs(string a_mkfs[]){
    string path;
    string path2;
    string name;
    bool flag_mkfs=false;
    int poss;
    for (int i = 0; i < contadorMount; i++){
        if(a_mkfs[0]==arregloMountId[i]){
            path=arregloMountPath[i];
            name=arregloMountPart[i];
            poss=i;

            flag_mkfs=true;
            break;
        }
    }
    
    if(flag_mkfs==true){
        path2=path;
        string auxpath="users.txt";
        path2=path_sindisco(path2);
        path2+=auxpath;
        cout<<path2<<endl;
        crearArchivo_UyG(path2);
        
        FILE *file;
        
        file= fopen(path.c_str(),"r+b");
        
        
        fseek(file,0,SEEK_SET);
        
        MBR mbr;
        
        fread(&mbr,sizeof(MBR),1,file);

        if(mbr.mbr_partition_1.part_name==name){
            //cout<<poss<<endl;
            //path_actual=arregloMountPath[poss];
            cout<<path_actual<<endl;
            int posi=mbr.mbr_partition_1.part_start;
            int posf=mbr.mbr_partition_1.part_size;
            //cout<<posi<<endl;
            //cout<<posf<<endl;
            
            
            

            
            
            /*prueba pru;
            
            pru.id=a_mkfs[0];
            fseek(file, pos, SEEK_SET);
            
            rewind(file);
            
            fwrite(&pru,sizeof(pru),1,file);*/

        }else if(mbr.mbr_partition_2.part_name==name){
            //cout<<poss<<endl;
            //path_actual=arregloMountPath[poss];
            int pos=mbr.mbr_partition_2.part_start;
            /*prueba pru;
            
            pru.id=a_mkfs[0];
            fseek(file, pos, SEEK_SET);
            
            rewind(file);
            
            fwrite(&pru,sizeof(pru),1,file);*/

        }else if(mbr.mbr_partition_3.part_name==name){
            cout<<poss<<endl;
            //path_actual=arregloMountPath[poss];
            /*int pos=mbr.mbr_partition_3.part_start;
            prueba pru;
            
            pru.id=a_mkfs[0];
            fseek(file, pos, SEEK_SET);
            
            rewind(file);
            
            fwrite(&pru,sizeof(pru),1,file);*/
        }else if(mbr.mbr_partition_4.part_name==name){
            cout<<poss<<endl;
            //path_actual=arregloMountPath[poss];
            /*int pos=mbr.mbr_partition_4.part_start;
            prueba pru;
            
            pru.id=a_mkfs[0];
            fseek(file, pos, SEEK_SET);
            
            rewind(file);
            
            fwrite(&pru,sizeof(pru),1,file);*/
            
        } 
        
        
        fclose(file);


        

        
    }else{
        cout<<"No se encontre el Id en la lista de particiones montadas."<<endl;
    }
       /* FILE *file;
        
        file= fopen(path.c_str(),"rb+");
        
        
        fseek(file,0,SEEK_SET);
        
        MBR mbr;
        
        fread(&mbr,sizeof(MBR),1,file);
        
        prueba pru;
        cout<<"---SOY PRUEBA ID:--- "<<endl;
        cout<<pru.id[0]<<endl;
        
        fclose(file);*/
    

}



void insertar(tablaInodos *&inodo , string id, char tipo, string path){
    
    int contadorinodos=0;
    int contadorbloques=0;
    tablaInodos *nuevo_inodo = new tablaInodos();
    nuevo_inodo->id=id;
    nuevo_inodo->i_type=tipo;
    

    string arreglopath[30];
    string dato;
    int contaa =0;
    
    
    for (int i = 0; i < 12; i++){
        *inodo->i_block[i].b_name='e';
    }

    //cout<<path.length()<<endl;
    for (int i = 1; i < path.length(); i++){
        
        if(path[i] == '/' || path[i]==NULL ){
            
            arreglopath[contaa]=dato;
            dato="";
            contaa+=1;
        }else{
            dato+=path[i];
        }
    }

    for (int i = 0; i < contaa; i++){
        cout<<arreglopath[i]<<endl;
    }
    
    //cout<<arreglopath[2]<<endl;
    cout<<"---------------"<<endl;
    tablaInodos *aux1 =inodo;
    tablaInodos *aux2;
    while (aux1!=NULL){
        //cout<<arreglopath[contadorinodos]<<endl;
        contadorinodos+=1;
        cout<<"ci: "<<contadorinodos<<endl;
        
        
        for (int i = 0; i < 12; i++){
            cout<<*aux1->i_block[0].b_name<<endl;
            cout<<"I: "<<i<<endl;
            if(aux1->i_block[i].b_name==arreglopath[contadorinodos]){
                //cout<<"I: "<<i<<endl;
                contadorbloques=i;
                cout<<"Encontro igual"<<endl;
                contadorinodos=contadorinodos-1;
                break;
            }else if(*aux1->i_block[i].b_name=='e'){
                  if(arreglopath[contadorinodos-1]=="root"){
                    //cout<<"I: "<<i<<endl;
                    cout<<"entre"<<endl;
                    contadorinodos=0;
                    contadorbloques=i;
                    break;
                  }else{
                    //cout<<"I: "<<i<<endl;
                    contadorbloques=i;
                    contadorinodos=contadorinodos-1;
                    cout<<"No encontro"<<endl;
                    break;
                  }
                
                    
                
                

            }
        }
        
        aux2=aux1;
        aux1 =aux1->i_block[contadorbloques].tinodo;
        
        //contadorinodos+=1;    
        
        //cout<<"Contador inodos: "<<contadorinodos<<endl;

    }
    
    nuevo_inodo->i_block[contadorbloques].b_name[12]= *arreglopath[contadorinodos].c_str();
    //cout<<"CI: ";
    //cout<<contadorinodos<<endl;
    //cout<<"ARr: ";
    //infoEXT+=arreglopath[contadorinodos];
    
    cout<<"arreglo: "<<arreglopath[contadorinodos]<<endl;
    cout<<"contai: "<<contadorinodos<<endl;
    cout<<"contab: "<<contadorbloques<<endl;
    aux2->i_block[contadorbloques].tinodo=nuevo_inodo;
    //cout<<"muere"<<endl;
    nuevo_inodo->i_block[contadorbloques].tinodo=aux1;
    //cout<<"muere2"<<endl;

}

void mostrarExt3(tablaInodos *inodos){
    /*tablaInodos *actual= new tablaInodos();
    tablaInodos *aux = new tablaInodos();
    actual= inodos;
    

    while(actual!=NULL){
        for (int i = 0; i < 12; i++){
            aux=inodos;
            if(actual->i_block[i].b_name==NULL){
                break;
            }else{
                actual=actual->i_block[i].inodo;
                

                while (actual!=NULL){
                    actual=actual->i_block[i].inodo;
                }
                
                
            }
        }
        

    }*/
}
            
    


void login(string user, string contra, string id ){
    string path;
    //int contadorlog=0;
    int poss;
    string datos[5];
    int cont_datos;
    string aux_dato;
    bool flag=false;

    for (int i = 0; i < contadorMount; i++){
        if(id==arregloMountId[i]){
            path=arregloMountPath[i];
            poss=i;

            flag=true;
            break;
        }
    }

    path=path_sindisco(path);
    path+="users.txt";
    if(activa==false && flag==true){
        
        ifstream archivo;
        string texto;
        archivo.open(path, ios:: out);
        if(archivo.fail()){
        cout<<"No se pudo leer en el archivo raiz usuarios y grupos. Por lo tanto no se podra iniciar sesion."<<endl;
        }

        while (!archivo.eof()){
            //contadorlog+=1;
            getline(archivo,texto);
            //cout<<contadorlog<<texto<<endl;
            //cout<<texto.length()<<endl;
            //cout<<texto[8]<<endl;
            cont_datos=0;
            
            for (int i = 0; i < texto.length(); i++){
                if(texto[i]==','){
                    cout<<aux_dato<<endl;
                    datos[cont_datos]=aux_dato;
                    cont_datos+=1;
                    aux_dato="";

                    
                }else{
                    if(i==texto.length()-1){
                        aux_dato+=texto[i];
                        cout<<aux_dato<<endl;
                        datos[cont_datos]=aux_dato;
                        cont_datos+=1;
                        aux_dato="";
                    }else{
                        aux_dato+=texto[i];
                    }
                    
                }
                
            }
            //cout<<cont_datos<<endl;

            if(cont_datos==5){
                if(datos[3]==user && datos[4]==contra){
                    activa=true;
                    cout<<"Inicio de sesion correcto, bienvenido: "<<user<<endl;
                    path_actual=path;
                    if(user=="root"){
                        cout<<"Usuario root activo"<<endl;
                    }

                    usuario_actual=user;

                    break;
                }else{
                    cout<<"Usuario o contraseña son incorrectos"<<endl;
                }
            }
            
        }
        archivo.close();


    }else{
        cout<<"No se puede iniciar sesion ya que hay un usuario activo o el id no existe"<<endl;
    }
}



void mkgrp(string name, string path){
    string datos[5];
    int cont_datos;
    string aux_dato;
    int id_grupo;
    bool flag=false;
    path= path_actual;
    if(activa==true && usuario_actual=="root"){
        
        ifstream archivo;
        string texto;
        string aux_texto;
        archivo.open(path, ios:: out);
        if(archivo.fail()){
        cout<<"No se pudo leer en el archivo raiz usuarios y grupos. Por lo tanto no se podra crear grupos."<<endl;
        }

        while (!archivo.eof()){
            //contadorlog+=1;
            getline(archivo,texto);
            //cout<<contadorlog<<texto<<endl;
            //cout<<texto.length()<<endl;
            //cout<<texto[8]<<endl;
            cont_datos=0;
            aux_texto+=texto+"\n";
            
            
            for (int i = 0; i < texto.length(); i++){
                if(texto[i]==','){
                    cout<<aux_dato<<endl;
                    datos[cont_datos]=aux_dato;
                    cont_datos+=1;
                    aux_dato="";

                    
                }else{
                    if(i==texto.length()-1){
                        aux_dato+=texto[i];
                        cout<<aux_dato<<endl;
                        datos[cont_datos]=aux_dato;
                        cont_datos+=1;
                        aux_dato="";
                    }else{
                        aux_dato+=texto[i];
                    }
                    
                }
                
            }
            //cout<<cont_datos<<endl;

            if(cont_datos==3){
                if(datos[2]==name){
                    cout<<"Este grupo ya existe"<<endl;
                    flag=false;
                }else{
                    flag=true;   
                    id_grupo=stoi(datos[0]);
                    //cout<<"xxxxxxxxx "<<stoi(datos[0])+1<<endl;
                }

                
                
                
            }


            
        }
        archivo.close();

        ofstream archivo1;

        archivo1.open(path, ios::out);
        if(archivo1.fail()){
            cout<<"No se pudo crear el archivo raiz usuarios y grupos"<<endl;
        }
        archivo1<<aux_texto;
        if(flag==true){
            
            archivo1<<id_grupo+1<<",G,"<<name;
    
        }
        
        archivo1.close();


    }else{
        cout<<"No se puede crear un grupo ya que la sesion no es del usuario root"<<endl;
    }
        
}
void mkusr(string name,string contra, string grupo, string path){
    string datos[5];
    int cont_datos;
    string aux_dato;
    int id_grupo;
    int cont_grupos=0;
    bool flaguser=false;
    bool flaggroup=false;
    string arr_grupos[30];
    if(activa==true && usuario_actual=="root"){
        
        ifstream archivo;
        string texto;
        string aux_texto;
        archivo.open(path, ios:: out);
        if(archivo.fail()){
        cout<<"No se pudo leer en el archivo raiz usuarios y grupos. Por lo tanto no se podra crear un nuevo usuario."<<endl;
        }

        while (!archivo.eof()){
            //contadorlog+=1;
            getline(archivo,texto);
            //cout<<contadorlog<<texto<<endl;
            //cout<<texto.length()<<endl;
            //cout<<texto[8]<<endl;
            cont_datos=0;
            aux_texto+=texto+"\n";
            
            
            for (int i = 0; i < texto.length(); i++){
                if(texto[i]==','){
                    cout<<aux_dato<<endl;
                    datos[cont_datos]=aux_dato;
                    cont_datos+=1;
                    aux_dato="";

                    
                }else{
                    if(i==texto.length()-1){
                        aux_dato+=texto[i];
                        cout<<aux_dato<<endl;
                        datos[cont_datos]=aux_dato;
                        cont_datos+=1;
                        aux_dato="";
                    }else{
                        aux_dato+=texto[i];
                    }
                    
                }
                
            }
            cout<<"---"<<cont_datos<<endl;

            if(cont_datos==3){
                //cout<<"entre"<<cont_grupos<<endl;
                arr_grupos[cont_grupos]=datos[2];
                //cout<<"entre"<<endl;
                cont_grupos+=1;
            }

            if(cont_datos==5){
                if(datos[3]==name){
                    flaguser=false;
                    cout<<"Ya existe el usuario: "<<name<<" por lo tanto no se podrá crear." <<endl;
                }else{
                    id_grupo=stoi(datos[0]);
                    flaguser=true;

                }
            }
            /*if(cont_datos==2){
                if(datos[2]==name){
                    cout<<"Este grupo ya existe"<<endl;
                    flag=false;
                }else{
                    flag=true;   
                    id_grupo=stoi(datos[0]);
                    cout<<"xxxxxxxxx "<<stoi(datos[0])+1<<endl;
                }

                
                
                
            }*/


            
        }
        archivo.close();

        for (int i = 0; i < cont_grupos; i++){
            if(grupo==arr_grupos[i]){
                flaggroup=true;
                break;
            }else{
                flaggroup=false;
            }
        }
        
        if(flaggroup==false){
            cout<<"El grupo no existe: "<<grupo<<endl;
        }
        ofstream archivo1;

        archivo1.open(path, ios::out);
        if(archivo1.fail()){
            cout<<"No se pudo crear el archivo raiz usuarios y grupos"<<endl;
        }
        archivo1<<aux_texto;
        if(flaguser==true && flaggroup==true){
            
            archivo1<<id_grupo+1<<",U,"<< grupo <<","<<name<<","<<contra;
    
        }

        
        
        archivo1.close();


    }else{
        cout<<"No se puede crear usuario ya que no ha iniciado sesion en el usuario root!!!"<<endl;
    }
        
}

void rmgrp(string name,string path){
 string datos[5];
    int cont_datos;
    string aux_dato;
    int id_grupo;
    bool flag=false;
    path= path_actual;
    if(activa==true && usuario_actual=="root"){
        
        ifstream archivo;
        string texto;
        string aux_texto;
        archivo.open(path, ios:: out);
        if(archivo.fail()){
        cout<<"No se pudo leer en el archivo raiz usuarios y grupos. Por lo tanto no se podra crear grupos."<<endl;
        }

        while (!archivo.eof()){
            //contadorlog+=1;
            getline(archivo,texto);
            //cout<<contadorlog<<texto<<endl;
            //cout<<texto.length()<<endl;
            //cout<<texto[8]<<endl;
            cont_datos=0;
            
            
            
            for (int i = 0; i < texto.length(); i++){
                if(texto[i]==','){
                    cout<<aux_dato<<endl;
                    datos[cont_datos]=aux_dato;
                    cont_datos+=1;
                    aux_dato="";

                    
                }else{
                    if(i==texto.length()-1){
                        aux_dato+=texto[i];
                        cout<<aux_dato<<endl;
                        datos[cont_datos]=aux_dato;
                        cont_datos+=1;
                        aux_dato="";
                    }else{
                        aux_dato+=texto[i];
                    }
                    
                }
                
            }
            //cout<<cont_datos<<endl;

            if(cont_datos==3){
                if(datos[2]==name){
                    cout<<"Existe el grupo"<<endl;
                    texto="";
                    for (int i = 0; i < cont_datos; i++){
                        datos[0]="0";
                        if(i==cont_datos-1){
                            texto+=datos[i]; 
                        }else{
                            texto+=datos[i]+",";
                        }
                        
                    }
                    

                    flag=true;
                }else{
                    flag=false;   
                    id_grupo=stoi(datos[0]);
                    //cout<<"xxxxxxxxx "<<stoi(datos[0])+1<<endl;
                }

                
                
                
            }
            aux_texto+=texto+"\n";


            
        }
        archivo.close();

        ofstream archivo1;

        archivo1.open(path, ios::out);
        if(archivo1.fail()){
            cout<<"No se pudo crear el archivo raiz usuarios y grupos"<<endl;
        }
        
        if(flag==true){
            
            archivo1<<aux_texto;
    
        }
        
        archivo1.close();


    }else{
        cout<<"No se puede crear un grupo ya que la sesion no es del usuario root"<<endl;
    }   
}


void rmusr(string user, string path){
    string datos[5];
    int cont_datos;
    string aux_dato;
    int id_grupo;
    bool flag=false;
    path= path_actual;
    if(activa==true && usuario_actual=="root"){
        
        ifstream archivo;
        string texto;
        string aux_texto;
        archivo.open(path, ios:: out);
        if(archivo.fail()){
        cout<<"No se pudo leer en el archivo raiz usuarios y grupos. Por lo tanto no se podra crear grupos."<<endl;
        }

        while (!archivo.eof()){
            //contadorlog+=1;
            getline(archivo,texto);
            //cout<<contadorlog<<texto<<endl;
            //cout<<texto.length()<<endl;
            //cout<<texto[8]<<endl;
            cont_datos=0;
            
            
            
            for (int i = 0; i < texto.length(); i++){
                if(texto[i]==','){
                    cout<<aux_dato<<endl;
                    datos[cont_datos]=aux_dato;
                    cont_datos+=1;
                    aux_dato="";

                    
                }else{
                    if(i==texto.length()-1){
                        aux_dato+=texto[i];
                        cout<<aux_dato<<endl;
                        datos[cont_datos]=aux_dato;
                        cont_datos+=1;
                        aux_dato="";
                    }else{
                        aux_dato+=texto[i];
                    }
                    
                }
                
            }
            //cout<<cont_datos<<endl;

            if(cont_datos==5){
                if(datos[3]==user){
                    cout<<"Existe el usuario"<<endl;
                    texto="";
                    for (int i = 0; i < cont_datos; i++){
                        datos[0]="0";
                        if(i==cont_datos-1){
                            texto+=datos[i]; 
                        }else{
                            texto+=datos[i]+",";
                        }
                        
                    }
                    

                    flag=true;
                }else{
                    flag=false;   
                    id_grupo=stoi(datos[0]);
                    //cout<<"xxxxxxxxx "<<stoi(datos[0])+1<<endl;
                }

                
                
                
            }
            aux_texto+=texto+"\n";


            
        }
        archivo.close();

        ofstream archivo1;

        archivo1.open(path, ios::out);
        if(archivo1.fail()){
            cout<<"No se pudo crear el archivo raiz usuarios y grupos"<<endl;
        }
        
        if(flag==true){
            
            archivo1<<aux_texto;
    
        }
        
        archivo1.close();


    }else{
        cout<<"No se puede crear un grupo ya que la sesion no es del usuario root"<<endl;
    }
}

void unmount(string id){
    //arregloMount[0].erase(0);
    int dato;
    for (int i = 0; i < contadorMount; i++){
        if(id==arregloMountId[i]){
            dato=i;
            break;
        }
    }
    cout<<"///////"<<dato<<endl;
    
    arregloMountId[dato].erase(0);
    arregloMountPart[dato].erase(0);
    arregloMountPath[dato].erase(0);
    
}
