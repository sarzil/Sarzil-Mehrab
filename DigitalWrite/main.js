/**
 * @file
 * A simple Node.js application to write to a digital output.
 *
 * Supported Intel IoT development boards are identified in the code.
 * See the `cfg-app-platform.js` file for board configuration details.
 *
 * <https://software.intel.com/en-us/xdk/docs/using-templates-nodejs-iot>
 *
 * @author Paul Fischer, Intel Corporation
 * @author Elroy Ashtian, Intel Corporation
 * @author Dan Yocom, Intel Corporation
 *
 * @copyright (c) 2016-2017, Intel Corporation
 * @license BSD-3-Clause
 * See LICENSE.md for complete license terms and conditions.
 */

/* spec jslint and jshint lines for desired JavaScript linting */
/* see http://www.jslint.com/help.html and http://jshint.com/docs */
/* jslint node:true */
/* jshint unused:true */

"use strict" ;


var APP_NAME = "IoT Digital Write" ;
var Cfg = require("./utl/cfg-app-platform.js") ;    // get Cfg() constructor
var cfg = new Cfg() ;                               // init and config I/O resources

console.log("\n\n\n\n\n\n") ;                       // poor man's clear console
console.log("Initializing " + APP_NAME) ;

process.on("exit", function(code) {                 // define up front, due to no "hoisting"
    clearInterval(intervalID) ;
    console.log(" ") ;
    console.log("Exiting " + APP_NAME + ", with code:", code) ;
    console.log(" ") ;
}) ;


// confirm that we have a version of libmraa and Node.js that works
// exit this app if we do not

cfg.identify() ;                // prints some interesting platform details to console

if( !cfg.test() ) {
    process.exit(1) ;
}

if( !cfg.init() ) {
    process.exit(2) ;
}


// configure (initialize) our I/O pins for usage (gives us an I/O object)
// configuration is based on parameters provided by the call to cfg.init()

cfg.io = new cfg.mraa.Gpio(cfg.ioPin, cfg.ioOwner, cfg.ioRaw) ;
cfg.io.dir(cfg.mraa.DIR_OUT) ;                  // configure the gpio pin as an output

console.log("Using digital output pin number: " + cfg.ioPin) ;


// now we are going to write the digital output at a periodic interval

var digOut ;
var periodicActivity = function() {
    digOut = cfg.io.read() ;                    // get the current state of the output pin
    cfg.io.write(digOut?0:1) ;                  // if the pin is currently 1 write a '0' (low) else write a '1' (high)
    process.stdout.write(digOut?'0':'1') ;      // and write an unending stream of toggling 1/0's to the console
} ;
var intervalID = setInterval(periodicActivity, 1000) ;  // start the periodic write
