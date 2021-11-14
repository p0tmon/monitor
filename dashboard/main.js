const request = new XMLHttpRequest();

rquest.addEventListener('readystatechange', () =>{
//    console.log(request, request.readyState);
    if(request.readyState === 4){
        console.log(request.responseText);
    }
});

request.open('GET', 'https://potmon.azurewebsites.net/api/getsensors/');
rquest.send();