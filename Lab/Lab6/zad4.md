# Zadanie 4 

1. Tworzenie zaszyfrowanego pliku:

```bash 
cryptsetup luksFromat /path/to/losowy.dat 
```

2. Otwarcie i zamontowanie pliku jako systemu plików:

```bash 
cryptsetup luksOpen /path/to/losowy name_of_mapped_device

mount /dev/mapper/name_of_mapped_device /path/to/mount/point
```

3. Zamkniecie zaszyfrowanego pliku 

```bash 
umount /path/to/mount/point
cryptsetup luksClose name_of_mapped_device
```
4. Dodanie wpisu do pliku /etc/crypttab, aby automatycznie odszyfrowywać i montować plik po włożeniu pendrive'a:

```bash 
name_of_mapped_device /path/to/losowy.dat /path/to/keyfile.key
```
5. Dodanie wpisu do pliku /etc/fstab, aby automatycznie montować system plików po uruchomieniu:

```bash 
/dev/mapper/name_of_mapped_device /path/to/mount/point ext4 defaults 0 0
```

