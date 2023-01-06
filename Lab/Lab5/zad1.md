Stworzenie skompresowanego pliku o nazwie zero.dat.gz

```bash 
gzip zero.dat
```

Spakowanie pliku losowy.dat przy użyciu zip (utworzy losowy.zip): 

```bash 
zip losowy.zip losowy.dat
```

Po skompresowaniu rozmiary powinny być mniejsze niżeli 100 MB. Plik zero.dat jest łatwiejszy do skompresowania, ponieważ zawiera ciąg pustych bajtów co powoduje że jest mniej unikalny. W przypadku drugiego pliku z losowymi danymi stopień trudności kompresji rośnie co przekłada się na mniejszy stopień kompresji niżeli pliku zero.dat.