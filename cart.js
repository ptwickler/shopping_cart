

window.onload = function (){
 var cookies = document.cookie.split(';');
    console.log(cookies);

    var signed_in_regex = new RegExp("signed_in=1");
    var signed_out_regex = new RegExp("signed_in=0");

    for (var i = 0; i < cookies.length; i++){
       var sign_match = cookies[i].match(signed_in_regex);

        console.log("match? - " + sign_match);

        if (sign_match){
            var login_box = document.getElementById('login_box');
            console.log('got it');

            login_box.style.visibility = "hidden";
        }

        else if(!(sign_match)){
            var login_box = document.getElementById('login_box');
            login_box.style.visibility = "visible";

        }
    }

   /* if (document.cookie[signed_in] == 1){
     var login_box = document.getElementById('login').setAttribute('hidden', 'true');
 }*/
}