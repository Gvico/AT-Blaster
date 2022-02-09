<!DOCTYPE html>
<html lang="fr"><head>
    <title>Projet AT-Blaster - Gilles Vico</title>

    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
	
	<link rel="icon" href="images/fav.ico">
    <link rel="stylesheet" href="style.css">
</head>

<body>
<div class=sidenav>
	<h3 class=underline>Liens :</h3>
	<p><a href="?page=accueil">Accueil</a></p>
	<p><a href="?page=specs">Spécifications</a></p>
	<p><a href="?page=features">Fonctions</a></p>
	<p><a href="?page=media">Photos et vidéos</a></p>
	<p><a href="?page=scores">Scores</a></p>
</div>

<a id=top></a>
<div class=block>
	<div class=header>
		<img src="images/logo.png" alt="Logo d'AT-Blaster" style="width:50%;">
	</div>
</div>
<?php
	$arrayPages = array(
		'accueil' => 'accueil.php',
		'specs' => 'specs.php',
		'features' => 'features.php',
		'media' => 'media.php',
		'scores' => 'scores.php'
	);
	
		// Si l'argument est inexistant ou non valide, direction l'accueil
	if (empty($_GET['page']) || !array_key_exists(strtolower($_GET['page']), $arrayPages))
		include('pages/'. $arrayPages['accueil']);
	else
		include('pages/'. $arrayPages[strtolower($_GET['page'])]);
?>
<div class=block>
	<div class=header>
		<a href="https://www.he-ferrer.eu/"><img src="https://www.he-ferrer.eu/sites/default/files/inline-images/logo_header.png" alt="Logo de la HEFF" height=80 style="margin: 0px 10px 0px 10px;"></a>
		<a href="https://www.helb-prigogine.be/"><img src="https://www.guidesocial.be/magassoc_images/458-1-original.jpg" alt="Logo de la HELB" height=100 style="margin: 0px 10px 0px 10px;"></a>
	</div>
</div>

</body></html>
