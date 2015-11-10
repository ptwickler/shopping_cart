

window.onload = function (){
 var cookies = document.cookie.split(';');
    console.log(cookies);

    var signed_in_regex = new RegExp("signed_in=1");


    for (var i = 0; i < cookies.length; i++){
       var sign_match = cookies[i].match(signed_in_regex);

        if (sign_match){
            var login_box = document.getElementById('login_box');
            var sign_out_button = document.getElementById('sign_out_button');
            var login_box = document.getElementById('login_box'); //Gets the login form so that we can shrink it.

            //Toggles the visibility of the sign in and sign out buttons. The sing in button is part of the login form, all of which gets hidden.
            sign_out_button.style.visibility = 'visible';
            login_box.style.visibility = "hidden";


            login_box.style.height = "12px";


        }

        else if(!(sign_match)){
            var login_box = document.getElementById('login_box');
            var sign_out_button = document.getElementById('sign_out_button');

            sign_out_button.style.visibility = 'hidden';
            login_box.style.visibility = "visible";

            //Shrinks the login form to make the box on the page shrink when the form is hidden (the user is logged in).


            login_box.style.height = "110px";

        }
    }


}