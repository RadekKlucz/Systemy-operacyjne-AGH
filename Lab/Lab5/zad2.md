Dowiązania to specjalne rodzaje plików wskazujące na inne pliki w systemie plików. Do stworzenia dowiązania miękiego użyto: 

```bash 
ln -s losowy.dat losowy-soft.dat
```

Utworzyło nam to dowiązanie miękkie o nazwie losowy-soft.dat do pliku losowy.dat. Dowiązanie miękkie nie zajmuje dodatkowego miękkie nie zajmuje miejsca na dysku, ponieważ jest to tylko wskaźnik do pliku. 

Dowiązanie tworde: 

```bash 
ls losowy.dat losowy-hard.dat
```
Zajmuje dodatkowe miejsce na dysku, ponieważ jest to kopia danych z orginalnego pliku. 

Do sprawdzenia zajętości przestrzeni wykorzystujemy:

``` bash
ls -l losowy*
du -h losowy*
stat losowy*
```
Wyświetlają info o dowiązaniach. 
