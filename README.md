# README #

![Snooker Scoreboard](scoreboard.jpg)


### What is this repository for? ###

* This repository is for a snooker scoreboard on a 32x32 RGB LED Matrix controlled by a Raspberry Pi.
* Version 2.0

### What is Required? ###

* The scoreboard consists of 4 main hardware components.
	- You will need a Raspberry Pi. I used a Raspberry Pi 3 B+ but I can confirm it works fine with the Pi 4 as well.
	- A [32x32 RGB LED Matrix](https://www.adafruit.com/product/1484).
	- A minimum of [5V 4A power supply](https://www.adafruit.com/product/1466) like this one from Adafruit.
	- Finally, you will need the [RGB Matrix Bonnet](https://www.adafruit.com/product/3211) to control the matrix. 
	 This is the newest version of the Bonnet and comes pre-assembled. There is also an older version of the
	 [RGB Matrix Hat](https://www.adafruit.com/product/2345) that includes a real time clock if that is something
	 that interests you. This version is not assembled so you will have to solder the connectors to the board.
	 If you are the type of person who would be interested in the real time clock I can't imagine that would be 
	 an issue for you.

### How do I get setup? ###

* To begin you will need to install Raspbian on you Raspberry Pi. I would highly recommend using Raspbian Lite if 
   you plan to do more with the matrix and are familiar enough with linux that you can work comfortably from the 
   command line. If that does not describe you a Raspbian installation with GUI will work since the scoreboard is not 
   particularly taxing on the Pi. Once you have Raspbian up and running on the Pi make sure you have g++ and make 
   installed. To do this open a terminal and run the commands `sudo apt install g++` and `sudo apt install make`.
   
   
* Dependencies
* Database configuration
* How to run tests
* Deployment instructions

### Contribution guidelines ###

* Writing tests
* Code review
* Other guidelines

### Who do I talk to? ###

* Repo owner or admin
* Other community or team contact
