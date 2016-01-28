<?php








echo '<!DOCTYPE html>
<html lang="en">
  <head>
    <title>
      Fizz, Then also Buzz
    </title>
    <meta charset="utf-8" />
  </head>
  <body>';

     $i = 1;


while ($i <= 100){
    if ($i % 5 ==0 && $i % 3 ==0){
        echo "FizzBuzz" . "<br/>";
    }

    elseif ($i % 5 ==0){
        echo "Buzz" . "<br/>";
    }

    elseif ($i % 3 == 0){
        echo "Fizz" . "<br/>";
    }
    else {

        echo $i . "<br/>";
    }
    $i++;
}

    echo ' </body>
</html>
';