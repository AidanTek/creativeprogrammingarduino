# 02. Getting Started: The IDE

Now that installation is complete, we can check everything is working as expected by loading a program onto the Arduino.

The Arduino is a self-contained computer with a small amount of memory included onboard, part of this memory is used to store the program. This means that once you have loaded a program onto the Arduino, you no longer need your computer to be connected in order for the Arduino to run the code as it is retained in memory.

A program created for Arduino is called a "Sketch" and is written in a language closely related to C++. Don't let this put you off because the Arduino language contains plenty of simplifications, shortcuts and human readable commands!

Let's get started by doing the initiation that everyone starting Arduino must go through, Blink!

* Open the Arduino IDE software
* Connect the Arduino Uno hardware to your computer with the USB cable - you should see some lights come on as the USB will provide power
* We need to tell the Arduino IDE what kind of hardware it is working with (there is a big family to choose from!) and also how it is connected to the computer
  * Click on the **Tools** drop down menu and hover the mouse pointer over **Board:**. From this menu, make sure Arduino/Genuino Uno is selected
  * Click on the **Tools** drop down menu again and now hover over the **Port** menu. There should be a USB option highlighted that shows a connection to the Arduino, make sure it is selected.

Now we will load an example program on to the Arduino

* Navigate to the **File** and hover over **Examples**. In **01.Basics** you will find a sketch called **Blink**, select it and it should load in a new window (my sketch may look a little different to yours but it is the same thing!):

![blink](https://electricnoodlebox.files.wordpress.com/2018/08/blink1.png)

* Let's go ahead and load the sketch onto the Arduino Uno, do this by clicking the big arrow button at the top left of the window ![uploadarrow](https://electricnoodlebox.files.wordpress.com/2018/08/uploadarrow.png)
* You should see a brief progress bar in the IDE and some LED activity on the Arduino Uno as the sketch uploads
* Once the upload is complete, take a look at the Arduino - there is a built in LED that you can program which is connected to digital pin 13, this should now be blinking on and off at a regular interval. Success!

### Modify Blink

Now it is time to get your hands dirty with your first bit of hacking! 

The Blink sketch is a typical Arduino program. It has two main sections named "void setup()" and "void loop()" - every Arduino sketch needs to have these sections in order to work at all. 

* **setup()** is a section of code that will run once when the Arduino is powered on or reset, it is typically used to initialise things in your program and the hardware. 
* **loop()** is the main program. As the name suggests, this section of code will loop forever until the Arduino is powered off or reset. 

Let's just concentrate on loop() for now - 

```cpp
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
```

There are two commands in loop() - **digitalWrite()** and **delay()**. 
* digitalWrite() is used to tell any of Arduino's 13 digital pins to be either "on" or "off" - in terms of voltage this is "HIGH" or "LOW". As the comments highlight in the sketch, digitalWrite(LED_BUILTIN, HIGH); tells Arduino to turn the LED on by making the pin it is connected to go to a high voltage, and off by setting it to low voltage.
* delay() is a command that is used to tell Arduino to pause everything for a set amount of time in milliseconds (there are 1000ms in one second) - without using delay() the Arduino will carry out commands as fast as it possibly can, but delay() also prevents the Arduino from doing anything else while it is paused.

Try changing the numbers in delay() now to change the interval the light is turned on and off - once you have made the changes upload the sketch ![uploadarrow](https://electricnoodlebox.files.wordpress.com/2018/08/uploadarrow.png) and have a look at how the Arduino behaves.


Now try to add some more steps to the code so the LED behaviour is more complicated, you can do this by simply copying and pasting some extra lines of digitalWrite() and delay() like so:

```cpp
void loop() {
  digitalWrite(LED_BUILTIN, HIGH); 
  delay(200);                       
  digitalWrite(LED_BUILTIN, LOW);   
  delay(200);        
  digitalWrite(LED_BUILTIN, HIGH); 
  delay(200);                       
  digitalWrite(LED_BUILTIN, LOW);   
  delay(2000);               
}
```

Arduino will execute the commands in your sketch one at a time in a sequence, and will work from the top of the sketch to the bottom. When the bottom of void loop() is reached, Arduino will jump back to the first command in the loop() and repeat. Take a minute to read over the code and take in what you have made.

### Variables

Before we move on, we should go over one more thing: Variables. Variables are stored numbers and other bits of data that can be used throughout your sketch. They are defined by you as the programmer, given a unique name so you can reference to them anywhere in your code, and they have all kinds of powerful uses as we will explore in the other tutorials. 

It is worth mentioning that there are a number of different kinds of variable, which will define what kind of data is contained (e.g. how big a number). For now we are just going to use one type, the **int**. Copy the following code into a new Sketch (create a new sketch from the **File** menu):

```cpp
/*
  Blink

  Modified blink with variables included
  
*/

// Variables added below:
int ledontime = 2000; 
int ledofftime = 1000;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(ledontime);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(ledofftime);                       // wait for a second
}
```

Try uploading the code to the Arduino to see what happens - you can see that the behaviour is the same. Have a look at the sketch. Above setup(), see how two variables are created called "ledontime" and "ledofftime", they are both loaded with an initial value as well. In void loop(), delay() has been changed to contain the name of the variable in the brackets - this is like a pointer telling delay() to use whatever value that variable contains.

It may be hard to see the point of this at first, but imagine that you needed to repeat the delay() command 100 times, and you had typed the value 1000 into all of them, then you find that actually the value needed to be 200. You would have to modify 100 lines of code to fix this issue, whereas using a variable means that you only have to modify one! This is just one basic example, variables have many more uses as the value they contain can also be *modified* over time. Take a minute to read over the code and take in what you have made.

That's all we need for now, it's time to look at something more interesting! You can move on to [Neopixels Setup and Testing](https://github.com/AidanTek/creativeprogrammingarduino/wiki/Neopixels-Setup-and-Test) next. I have also provided some further information below which you can optionally choose to read.


### Further Information

#### Comments

Comments are useful messages that you can add to your sketch - they are ignored by the editor when the sketch is uploaded and are meant for you to be able to add human readable notes in your program. There are two ways you can add comments as shown below:

```cpp
// This is a standard quick comment - it starts with two forward slashes "//"

/*
  A forward slash followed by an asterix can be used for a longer section of text
  It needs to have a closing set which will be an asterix followed by a forward slash
  as shown here.
*/
```

#### Functions

The two commands we used to make Blink are called functions, digitalWrite() and delay(). You can spot a function as it will always have a pair of round brackets that follow the name. Sometimes *arguments* are required in order for the function to work. A function can be thought of as a tiny software machine that takes some kind of input and processes it in some way to an output, you will encounter them a lot! setup() and loop() are also functions and you can even define your own so you can call complex sequences of commands with a single line e.g. myfunction().

#### Parenthesis / Encapsulation

Encapsulation with parenthesis is very important in Arduino, it tells the IDE where something should start and end such as the arguments for a function. You often need to associate a set of commands with something, and this is defined with curly brackets: { and }. In the Blink example, we can see this in use with both setup() and loop():

```cpp
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
```
You can see how curly brackets define which commands are contained within loop(). You can have multiple layers of containers as we will soon see. Take care as it can easily get confusing, unclosed or misplaced brackets are a very common error to make that can break your program or lead to odd behaviour! Remember that every opened set of brackets needs to be closed at some point. There is a handy feature built in to the IDE - if you place the cursor by any opening or closing set of brackets, the editor will highlight which opposite set it thinks should be associated.

#### Completing commands with semicolon ;

Pretty much every function and command needs to be finished with a ; as you can spot in the Blink sketch - this tells Arduino to **do it!**, forgetting ; is a common mistake and can sometimes lead to confusing errors! 

#### Final note on errors

The Arduino IDE is very good at reporting errors! When code refuses to upload, there is usually a good reason why! Read the red error prompt and it should give you a good indication of what it thinks the problem is, and why it thinks it is a problem. As an extra hint, if you don't understand what the error is or can't spot the problem on the line the editor is highlighting then check the line above! The problem can often be that you forgot to use ; or you forgot to close a set of brackets so the editor is linking the lower correct line to the incorrect one above.