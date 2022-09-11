#include <time.h>
#include <string.h>

using namespace std;




typedef struct tablaInodos{
    int i_uid;
    int i_gid;
    int i_size;
    time_t i_atime;
    time_t i_ctime;
    time_t i_mtime;
    int i_block[12];
    char i_type;
    int i_perm ;

};







typedef struct partition1{
    char part_status;
    char part_type;
    char part_fit;
    int part_start;
    int part_size;
    char part_name[16];
};

typedef struct MBR{
    int mbr_tamano;
    time_t mbr_fecha_creacion;
    int mbr_disk_signature;
    partition1 mbr_partition_1;
    partition1 mbr_partition_2;
    partition1 mbr_partition_3;
    partition1 mbr_partition_4;
};





