# 01. Installation:

Before proceeding, you will need to install the following items on your computer:

* The Arduino IDE - please follow the instructions for your operating system by following [this link](https://www.arduino.cc/en/Main/Software)
* Once you have the IDE installed, open it for the first time as this will initialise project and library directories on your harddrive. These will probably appear in your home Documents directory.

![ArduinoIDE](https://electricnoodlebox.files.wordpress.com/2018/08/arduinoide.png)

*The Arduino IDE will look something like this*

* With the IDE open we need to install some additional libraries (libraries are just blocks of code written by someone to simplify a task, greatly reducing the amount of code you actually need to write!) Navigate to the **Sketch** drop down menu and then to **Include Library** and choose **Manage Libraries...** at the top of this list. A new window will pop up, search and install the following libraries from the list:
	* Adafruit Neopixel
	* Adafruit Unified Sensor *(this is optional - only install if you want to use the DHT11)*
	* DHT11 Sensor Library (by Adafruit) *(this is optional - only install if you want to use the DHT11)*

![library_manager](https://electricnoodlebox.files.wordpress.com/2018/08/librarymanager.png)

*The library manager window looks like this, click on a library to reveal the install button*

* Once you have installed the libraries, close the pop-up window and close any open Arduino windows for now.

You can [download the repository](https://github.com/AidanTek/creativeprogrammingarduino/archive/master.zip) to get all the example sketches.
	
That's everything! Now move on to [Getting Started](https://github.com/AidanTek/creativeprogrammingarduino/wiki/Getting-Started)