
Mkdisk -s->10 -path->"/home/sebbbasdl/archivos/fase1/D1.dsk"






fdisk -t->p -path->"/home/sebbbasdl/archivos/fase1/D1.dsk" -name->PRI1 -u->K -f->ff -s->200
fdisk -t->p -path->"/home/sebbbasdl/archivos/fase1/D1.dsk" -name->PRI2 -u->K -f->ff -s->200
fdisk -t->p -path->"/home/sebbbasdl/archivos/fase1/D1.dsk" -name->PRI3 -u->K -f->ff -s->200




mounT -path->"/home/sebbbasdl/archivos/fase1/D1.dsk" -name->PRI1


mounT -path->"/home/sebbbasdl/archivos/fase1/D1.dsk" -name->PRI2


mounT -path->"/home/sebbbasdl/archivos/fase1/D1.dsk" -name->PRI3



MkfS -id->851D1 -type->fast
rep -name->disk -id->851D1 -path->"/home/sebbbasdl/Documentos/reporte5.jpg"

