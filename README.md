Welcome to my "bluetooth" Kobo Page Turner project.


The project was born because my wife wanted a pageTurner for the KOBO Libra, and everything she found didn't meet her needs, and as I had some material that I wasn't using,
I decided to accept the challenge. Basically, I just needed to emulate a keyboard and be able to connect via Bluetooth, to avoid more connections.

This code will simply emulate a keyboard, that is all that is needed.
You can change the button order to suit your needs.
Or change the Led brightness.

// Define the pins for the buttons and LED

const int buttonPin1 = D5;     // Button 1 (will send Left Arrow)

const int buttonPin2 = D4;     // Button 2 (will send Right Arrow)

const int extLedPin = D9;      // External LED pin (GPIO9)

const int LED_BRIGHTNESS = 1;  // Value between 0-255 for brightness (adjust as needed - If you want a flashlight, put the 255 :P)


In order to use this on Kobo we must enable the " devmode ", to do so pls refer to this video that shows how to do it.
https://www.youtube.com/watch?v=fA2ApXlZ0VU&t=56s

Once inside Devmode enable ( Force wifi On ) or Kobo system will automatically disable the connection after 2min.
( Attention with this option on, the kobo Battery will drain out, the solution is to everytime you stop using the PageTurner,
Go setting and disable "bluetooth and wi-fi".


Be free to go wild with the design, I made the design in fonction of my wife's desire.

If you make any improvements on the code, or design pls share with the community.

If you have any questions that I can help with, feel free to contact me.

mp3dpt@gmail.com

Happy making and printing.

//if you want to buy me a coffee - paypal.me/mmpires
