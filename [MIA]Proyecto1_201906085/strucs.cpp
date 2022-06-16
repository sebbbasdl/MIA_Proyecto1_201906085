#include <time.h>

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

