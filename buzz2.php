<?php


$i = 1;





while ($i <= 100){
    if ($i % 5 ==0){
        if ($i % 3 == 0){
            echo "FizzBuzz" . "<br/>";
        }

      else { echo "Buzz". "<br/>";}
    }

    elseif ($i % 3 == 0){
        echo "Fizz" . "<br/>";
    }
    else {

        echo $i . "<br/>";
    }
    $i++;
}

