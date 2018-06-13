<html>
    <head>
    <title>IOT</title>
        <style>
        table, th, td {
    border: 1px solid black;
            border-spacing: 5px;
}
            h1,h3 {text-align: center;}
        </style>
    </head>
    <body bgcolor="#3396FF">
        <h1 style="color:#333333;"><b>Automatic plant irrigation based on soil moisture</b></h1>
        <h3 style="color:#333333;">Database of moisture sensing</h3>
        
<?php
$host    = "localhost";
$user    = "root";
$pass    = "";
$db_name = "arduino";

//create connection
$connection = mysqli_connect($host, $user, $pass, $db_name);

//test if connection failed
if(mysqli_connect_errno()){
    die("connection failed: "
        . mysqli_connect_error()
        . " (" . mysqli_connect_errno()
        . ")");
}

//get results from database
$result = mysqli_query($connection,"SELECT * FROM iot")or die(mysqli_error($connection));
$all_property = array();  //declare an array for saving property

//showing property
echo '<table class="data-table" align="center">
        <tr class="data-heading">';  //initialize table tag
while ($property = mysqli_fetch_field($result)) {
    echo '<td>' . $property->name . '</td>';  //get field name for header
    array_push($all_property, $property->name);  //save those to array
}
echo '</tr>'; //end tr tag

//showing all data
while ($row = mysqli_fetch_array($result)) {
    echo "<tr>";
    foreach ($all_property as $item) {
        echo '<td>' . $row[$item] . '</td>'; //get items using property value
    }
    echo '</tr>';
}
echo "</table>";
?>
     <?php
$dbc = mysqli_connect('localhost', 'root', '', 'arduino') or die('Error connecting to MySQL server.'); 
if(isset($_POST['submit_button']))
{
    mysqli_query($dbc, 'TRUNCATE TABLE `iot`');
    header("Location: " . $_SERVER['PHP_SELF']);
    exit();
}

?>
<form method="post" action="">
    <input name="submit_button" type="submit" value=" Clear Table " />
</form>
    </body>
</html>