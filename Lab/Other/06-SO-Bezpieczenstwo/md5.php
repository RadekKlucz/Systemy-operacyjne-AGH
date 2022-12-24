<html>
<head>
<style type="text/css">
html{background:black;
	color:yellow;}
</style>
</head>
<body>


<form action=md5.php method=GET>

Szukany poczatek: <input name='szukane' value="c8" type=text ><br>
Ilosc hashy: <input name='dlugosc' value="1000" type=text ><br>
Wyswietlac hashe? 
<br/>
<input type='radio' name='wyswietlac' value="TRUE" type=text checked>Tak<br>
<input type='radio' name='wyswietlac' value="FALSE" type=text>Nie<br>
<br/>
<br/><br/>
<input type=submit value="OK">
</body>
</form>

<?php

$szukany_tekst2 = "-".$_GET['szukane'];
for ($i = 1; $i <= $_GET['dlugosc']; $i++){
	$hashe[$i] = md5($i);
	//if($_GET['wyswietlac']=="TRUE") echo $i.' = '.$hashe[$i].'<br/>';
}
echo '</br></br>';
$lancuch = implode("-", $hashe);
$czy = strpos($lancuch, $szukany_tekst2,$pozycja);

while($pozycja<=strlen($lancuch)){
if($czy != FALSE){
	echo "Znaleziono powtarzajacy sie poczatek <b> $szukany_tekst </b> hasha na pozycji: ".($czy)."</br>";
	$pozycja = $czy;
	$czy = FALSE;
	$OK = "FALSE";
}else{
$pozycja++;
}
$czy = strpos($lancuch, $szukany_tekst2,$pozycja+1);
}
echo '</br>';
if($OK == FALSE) echo "<br/><br/>Nie istnieje taki poczatek hasha!";

for ($i = 1; $i <= $_GET['dlugosc']; $i++){
	
	if($_GET['wyswietlac']=="TRUE") echo $i.' = '.$hashe[$i].'<br/>';
}


?>
</html>