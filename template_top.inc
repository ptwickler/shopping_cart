<!DOCTYPE html>
<html lang="en">
<head>
    <title>
        Chris' Crystals, Charms, and Other Occult Offerings
    </title>
    <meta charset="utf-8">
    <link rel="stylesheet" href="cart.css">
  <script src="cart.js"></script>
    <link rel="shortcut icon" type="image/x-icon" href="./img/bm_icon.ico">
</head>

<body>
<div class="wrapper">

<?php


if (!isset($_SESSION)) {
    session_start();
}


if ((isset($_SESSION['sign_in']) && $_SESSION['sign_in'] == 1) && !isset($_GET['admin'])) {
echo '<div class="cart_display">'; //The start of the div that displays the users cart in the top left of the screen.

// Displays shopping cart and checkout button in top left of screen if user is signed in.

    echo "Your Cart:<br/>";
    print '<form name="checkout_button" action="cart.php?checkout=1" method="POST">';

    if (isset($_SESSION['out_cart'])) {

        $display_cart = build_display_cart($_SESSION['out_cart']);

        echo $display_cart ."<br/>";

    }

    echo '<input type="submit" value="Checkout" ></form>';
    echo '</div><!--end div.cart_display-->';

}


elseif(!isset($_SESSION['sign_in']) || isset($_GET['admin'])){
    echo '<div class="cart_place_holder"></div>'; //Inserts an empty div to maintain layout when user isn't signed in.
}


echo '<div id="banner_box" class="banner">
       <img class="banner" src="img/banner.jpg">
      </div><!--end div#banner_box-->

<div class="login" id="login_wrap">
    <form class="login" id="login_box" action="cart.php" method="POST">
        <label for="username">Name</label><br />
        <input class="login" type="text" size="20" name="username"/><br /><br />
        <label for="password" class ="login">Password</label><br>
        <input type="password" class="login" name="password" size="20"><br>
        <input class="login_button" type="submit" value="Sign In">
    </form>

    <div class="sign_out">
       <form class="login" action="cart.php?out=1" method="GET">
          <input type="text" name="out" value="1" hidden>
          <input class="sign_out" id="sign_out_button" type="submit" value="Sign Out">
       </form>


     ';

       if (isset($_SESSION["sign_in"])){
echo '<div class="user_name">Hi, '. strtoupper($_SESSION['username'][0]) . substr($_SESSION['username'],1). '. </div>';
           setcookie('signed_in',1, time() + 3600, "/" );


}

if (!isset($_SESSION['sign_in']) && !isset($_GET['register_new'])) {
    echo  '<div class="sign_in_form"><span class="require_auth">Sign in to Purchase Items</span></div><br/>';
    if (!isset($_GET['register_new'])) {
        echo '<div class="not_registered">Not&nbsp;registered? Click <a href="cart.php?register_new=1">here</a> to register.</div>';

    }


}



// Activates the register form if a user has submitted an username not in the accounts.txt list. As of now, blank
// submissions of the login form also trigger the register form display.
if (isset($_GET['register_new']) && $_GET['register_new'] == 1) {

    $register_display = register_display($_SESSION);

    echo $register_display;
}
  echo '</div><!--end div.sign_out-->
  </div><!--end div#login_wrap-->';

// This if and the subsequent elseif statement toggle the "Enter admin area" and "leave admin area" link depending on user's location.
if ((isset($_SESSION['admin']) && !isset($_GET['admin'])) ||  isset($_GET['admin']) &&  intval($_GET['admin']) < 2) {
    echo '<div class="admin_button">
  <a href="http://localhost/cart02/cart.php?admin=2">Enter Admin Area</a>
</div><div id="product_edge"></div>';
}

elseif(isset($_GET['admin']) && $_GET['admin'] >= 2) {
    echo '<div class="admin_button"><a href="http://localhost/cart02/cart.php">Leave Admin Area</a></div><!-- end .admin_button-->';
}

