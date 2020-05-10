# README #

![Snooker Scoreboard](scoreboard.jpg)


### What is this repository for? ###

* This repository is for a snooker scoreboard on a 32x32 RGB LED Matrix controlled by a Raspberry Pi.
* Version 2.0

### What is Required? ###

* The scoreboard consists of 4 main hardware components.
	1. You will need a Raspberry Pi. I used a Raspberry Pi 3 B+ but I can confirm it works fine with the Pi 4 as well.
	2. A [32x32 RGB LED Matrix](https://www.adafruit.com/product/1484).
	3. A minimum of [5V 4A power supply](https://www.adafruit.com/product/1466) like this one from Adafruit.
	4. Finally, you will need the [RGB Matrix Bonnet](https://www.adafruit.com/product/3211) to control the matrix. 
	    This is the newest version of the Bonnet and comes pre-assembled. There is also an older version of the
	    [RGB Matrix Hat](https://www.adafruit.com/product/2345) that includes a real time clock if that is something
	    that interests you. The older version is not assembled so you will have to solder the connectors to the board.

### How do I get setup? ###

1. To begin you will need to install Raspbian on you Raspberry Pi. I would highly recommend using Raspbian Lite if 
   you plan to do more with the matrix and are familiar enough with linux that you can work comfortably from the 
   command line. If that does not describe you a Raspbian installation with GUI will work since the scoreboard is not 
   particularly taxing on the Pi. Once you have Raspbian up and running on the Pi you want to install g++, make, git,
   and ncurses. To do this open a terminal and run the commands `sudo apt-get install g++`, `sudo apt-get install make`,
   `sudo apt-get install git`, and finally `sudo apt-get install libncurses5-dev libncursesw5-dev`.
   
2. The next step is to setup the Raspberry Pi Bonnet/Hat. Follow [these](https://learn.adafruit.com/adafruit-rgb-matrix-bonnet-for-raspberry-pi/)
    instructions provided by Adafruit to setup the hardware and install the rpi-rgb-led-matrix matrix. I have my library installed in my home 
    directory which you can get to by running the command `cd ~` in a terminal or simply opening a terminal which will typically open in your
    home directory. When connecting the power from the LED Matrix to the Bonnet/Hat be sure to double check that the wire colors actually
    correlate to the correct terminals. The LED board I received came with a power cord that was incorrectly assembled resulting in flipped 
    colors where black was positive and red was negative for the matrix. If you connect the power backwards you can damage your Matrix.

3. The final step is to copy and build the snooker-scoreboard repository. I have the library setup to run from my documents folder. To get to
    the documents folder open a terminal and run the command `cd Documents`. Once in the documents folder run the command 
    `git clone https://github.com/Mike-R-R/Snooker-Scoreboard.git`.
   
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
