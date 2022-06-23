
Mkdisk $size=>32 $path=>"/home/sebbbasdl/archivos/fase1/" $name=>D1.dsk
Mkdisk $size=>64 $path=>"/home/sebbbasdl/archivos/fase1/" $name=>D2.dsk





fdisk @tYpE=>p $path=>"/home/sebbbasdl/archivos/fase1/D1.dsk" $name=>PRI1 @Unit=>K @fit=>ff $sizE=>200
fdisk @tYpE=>p $path=>"/home/sebbbasdl/archivos/fase1/D1.dsk" $name=>PRI2 @Unit=>K @fit=>ff $sizE=>200

fdisk @tYpE=>p $path=>"/home/sebbbasdl/archivos/fase1/D2.dsk" $name=>PRI11 @Unit=>K @fit=>wf $sizE=>400
fdisk @tYpE=>p $path=>"/home/sebbbasdl/archivos/fase1/D2.dsk" $name=>PRI12 @Unit=>K @fit=>wf $sizE=>400
fdisk @tYpE=>p $path=>"/home/sebbbasdl/archivos/fase1/D1.dsk" $name=>PRI3 @Unit=>K @fit=>ff $sizE=>200



mounT $path=>"/home/sebbbasdl/archivos/fase1/D1.dsk" $name=>PRI1
moUnt $path=>"/home/sebbbasdl/archivos/fase1/D2.dsk" $name=>PRI11

mounT $path=>"/home/sebbbasdl/archivos/fase1/D1.dsk" $name=>PRI2

mounT $path=>"/home/sebbbasdl/archivos/fase1/D2.dsk" $name=>PRI12
mounT $path=>"/home/sebbbasdl/archivos/fase1/D1.dsk" $name=>PRI3


mount








