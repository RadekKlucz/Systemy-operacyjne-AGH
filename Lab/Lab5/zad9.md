Do przygotowania 4 plików o wielkości 100 MB użyto:

```bash 
dd if=/dev/zero of=disc_512 bs=1M count=100
dd if=/dev/zero of=disc_1024 bs=1M count=100
dd if=/dev/zero of=disc_2048 bs=1M count=100
dd if=/dev/zero of=disc_4096 bs=1M count=100
```

Do założenia systemu plików użyto: 

```bash 
mkfs.ext4 -b 512 disc_512
mkfs.ext4 -b 1024 disc_1024
mkfs.ext4 -b 2048 disc_2048
mkfs.ext4 -b 4096 disc_4096
```

Do uzyskania maksymalnej liczby plików, które można utworzyć z tych systemów można przprowadzić test w benchmarku z obciążeniem. Następnie odczytać dane z pliku /proc/mounts

Np. bonnie++ 

Uruchamiamy:

```bash
bonnie++ -d <path> -n0 -u0
```
gdzie path to ścieżka do podmontowanego urządzenia. W rezultacie otrzymamy informację jaka jest maksymalna liczba plików jakie może stworzyć system plików.

Do zamątowania plików jako urządzenia blokowe użyto: 

```bash
sudo losetup -f disc_512
sudo losetup -f disc_1024
sudo losetup -f disc_2048
sudo losetup -f disc_4096

# lub 

sudo mount -t ext4 /dev/loop0 <path>
sudo mount -t ext4 /dev/loop1 <path>
sudo mount -t ext4 /dev/loop2 <path>
sudo mount -t ext4 /dev/loop3 <path>
```

Wrzucamy do każdego podmontowanego urządzenia 1000 plików o rozmiarach jak w treści:

```bash 
for i in $(seq 1 1000); do
    dd if=/dev/urandom of=<path>/file_512 bs=512 count=1
    dd if=/dev/urandom of=<path>/file_1024 bs=1024 count=1
    dd if=/dev/urandom of=<path>/file_2048 bs=2048 count=1
    dd if=/dev/urandom of=<path>/file_4096 bs=4096 count=1
done
```
Można ręczne zliczyć pliki w systemie plików (ls -l) i można porównać ile plików zostało utworzonych i z jaką efektywnością w zależności od wielkości bloku. 

Do wrzucenia każdego podmontowanego urządzenia 1000 plików o losowym rozmiarze (256 B - 8192 B) użyto polecenia: 

```bash
for i in $(seq 1 1000); do
    dd if=/dev/urandom of=<path>
```