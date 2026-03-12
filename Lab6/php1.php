<?php
if ($_SERVER["REQUEST_METHOD"] !== "POST") {
    header("Location: practice4.html");
    exit;
}

$number = isset($_POST["number"]) ? (int) $_POST["number"] : 0;
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Multiplication Table</title>
</head>
<body>
    <h1>Practice Page 4 -- PHP Multiplication Table</h1>
    <?php if ($number < 1): ?>
        <p>Please enter a positive number.</p>
    <?php else: ?>
        <h2>Multiplication Table for <?php echo $number; ?></h2>
        <table border="1">
            <tr>
                <th></th>
                <?php for ($i = 1; $i <= $number; $i++): ?>
                    <th><?php echo $i; ?></th>
                <?php endfor; ?>
            </tr>
            <?php for ($i = 1; $i <= $number; $i++): ?>
                <tr>
                    <th><?php echo $i; ?></th>
                    <?php for ($j = 1; $j <= $number; $j++): ?>
                        <td><?php echo $i * $j; ?></td>
                    <?php endfor; ?>
                </tr>
            <?php endfor; ?>
        </table>
    <?php endif; ?>
    <p><a href="practice4.html">Go back</a></p>
</body>
</html>