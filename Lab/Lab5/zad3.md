Do założenia systemu plików użyto następującego polecenia: 

```bash 
mkfs -t ext4 pusty.dat
```

lub: 

```bash
mount -t ext4 pusty.dat /mnt
```

Polecenia utworzą system plików ext4 na pliku pusty.dat.

Aby umożliwić montowanie/odmoontowanie przez użytkownika bez uprawnień root można dodać wpis do pliku /etc/fstab zawierającego info o systemach plików, które są automatycznie montowane przy starcie systemu. 

Wpis do pliku to: 

```bash 
/path/to/pusty.dat /mnt ext4 defaults,user 0 0
```

To umożliwi montowanie pusty.dat bez uprawinień root.
