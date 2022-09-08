
Mkdisk -size->32 -path->"/home/sebbbasdl/archivos/fase1/" -name->D1.dsk






fdisk -tYpE->p -path->"/home/sebbbasdl/archivos/fase1/D1.dsk" -name->PRI1 -Unit->K -fit->ff -sizE->200
fdisk -tYpE->p -path->"/home/sebbbasdl/archivos/fase1/D1.dsk" -name->PRI2 -Unit->K -fit->ff -sizE->200

fdisk -tYpE->p -path->"/home/sebbbasdl/archivos/fase1/D1.dsk" -name->PRI3 -Unit->K -fit->ff -sizE->200



mounT -path->"/home/sebbbasdl/archivos/fase1/D1.dsk" -name->PRI1


mounT -path->"/home/sebbbasdl/archivos/fase1/D1.dsk" -name->PRI2


mounT -path->"/home/sebbbasdl/archivos/fase1/D1.dsk" -name->PRI3


mkfs -id->061Disco1 -type->full -fs->2fs