
var request = require("request");
var groveSensor = require('jsupm_grove');

//require("jsupm_mic");

var mathjs = require ('mathjs');
var mraa = require('mraa');


//var lightSensor = new mraa.Aio(1);
var soundSensor = new mraa.Aio(2);


//var lightValraw=lightSensor.read();
var soundValraw=soundSensor.read();

 
 
//console.log(tempRound);
 


// var lightrealtimedata=light.value();
 

//console.log(tempValraw);

//console.log(lightValraw);




var fs = require("fs");
var mathjs = require ('mathjs');
var mraa = require('mraa');
var express = require('express');
var app = express();
var http = require('http');
var date = new Date();
var utcDate = date.toUTCString();
console.log(utcDate);

//var tzlookup = require("tz-lookup");
//console.log(tzlookup(23.8103, 90.4125));
//console.log(Date());

var app = express();




/*
var temperatureSensor = new mraa.Aio(0);
		var tempValraw=temperatureSensor.read();
		var resistance=(1023-tempValraw)*10000/tempValraw; 
		var temperature=1/(Math.log(resistance/10000)/3975+1/298.15)-273.15; 
		var tempRound=Math.round(temperature*1e2)/1e2;

var light = new groveSensor.GroveLight(1);
	var lightrealtimedata=light.value();

var soundval=soundValraw;
*/












function Sensingmethod(sensortype)
{
	if(sensortype="temperature")
	{
		var temperatureSensor = new mraa.Aio(0);
		var tempValraw=temperatureSensor.read();
		var resistance=(1023-tempValraw)*10000/tempValraw; 
		var temperature=1/(Math.log(resistance/10000)/3975+1/298.15)-273.15; 
		var tempRound=Math.round(temperature*1e2)/1e2;
		return tempRound;
		
	}
	
	if(sensortype="light")
	{
	var light = new groveSensor.GroveLight(1);
	var lightrealtimedata=light.value();
 	return lightrealtimedata;
		
	}
	
	if(sensortype="sound")
	{
		var soundval=soundValraw;
		return soundValraw;
		
	}
	
}




//console.log("Temperature is "+tempRound+" Degree C");
//console.log("Light is " +lightrealtimedata+ " Lux");
//console.log("Sound is "+soundValraw+ " db");
count=1;






var json= 
   {
      "name" : "Master",
      "id" : 0,
      "sensordata": 4,
	  "time:": "demo data"
   
}


function  clientSideSending(sensortype)

{
	json.id=count++;
    json.name=sensortype;
    json.sensordata= Sensingmethod(sensortype);
    json.time = new Date();
	
	
request({
        method: "PUT",
        url: "http://192.168.4.109:8081/1/"+sensortype,
        json:true,
        headers: {
            "content-type" : "application/json",
        },
        body: json
    
    
    },function(err,res,body){
        
    });
}
	
	
	
setInterval(function(){
    clientSideSending('temperature');
},5000);
setInterval(function(){
    clientSideSending('light');
},5000);
setInterval(function(){
    clientSideSending('sound');
},5000);

	





