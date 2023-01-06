# Wstęp 

Do utworzenia pliku o rozmiarze 100 MB z pustymi warotściami wykonano następujące polecenie: 

```bash 
dd if=/dev/zero of=zero.dat bs=1M count=100
```


To polecenie skopiuje 100 megabajtów danych z urządzenia /dev/zero do pliku o nazwie zero.dat. Urządzenie /dev/zero jest specjalnym plikiem w systemie operacyjnym, który zawsze zwraca ciąg pustych bajtów (tzn. bajtów zerowych).

Do utowrzenia pliku z losowymi danymi użyto: 

```bash 
dd if=/dev/urandom of=losowy.dat bs=1M count=100
```

o polecenie skopiuje 100 megabajtów danych z urządzenia /dev/urandom do pliku o nazwie losowy.dat. Urządzenie /dev/urandom jest specjalnym plikiem w systemie operacyjnym, który zawsze zwraca ciąg losowych bajtów.

(Zadanie 1)[zad1.md]
(Zadanie 2)[zad2.md]
(Zadanie 3)[zad3.md]
(Zadanie 5 (skrypt))[zad5.cc]
(Zadanie 6 (skrypt))[zad6.sh]