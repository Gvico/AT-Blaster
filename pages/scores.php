<div class=block>
    <p>Scores de parties :</p>
	<br>
	<div class=media>
		<?php
		ini_set('display_errors', 1);
		ini_set('display_startup_errors', 1);
		error_reporting(E_ALL);
		
		$connection = mysqli_connect('localhost', 'BlasterUser', 'atblaster');
		mysqli_select_db($connection, 'BlasterDB');

		$query = "SELECT * FROM ScoresTBL ORDER BY PlayerScore DESC";
		$result = mysqli_query($connection, $query);

		echo "<table>";
		while($row = mysqli_fetch_array($result)) {
			echo "<tr><td>" . $row['PlayerName'] . "</td><td>" . $row['PlayerScore'] . "</td></tr>";
		}

		echo "</table>";

		mysqli_close($connection);
		?>
	</div>
</div>
