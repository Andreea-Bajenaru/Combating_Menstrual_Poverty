// Main file for the code

#include <iostream>
#include <chrono>
#include <thread>
// #include <wiringPi.h> 
using namespace std;

int main(){
   bool padButtonPressed = false;
   bool tamponButtonPressed = false;
   bool padIsChosen = false;
   bool tamponIsChosen = false;
   bool dispensing = false;
   int dispenseTime = 5000; // 5 seconds
   int dispensingTimeout = 10000; // 10 seconds
   bool isEmpty = false;
   int dispenseCycles = 0;

   // wiringPiSetup();			// Setup the library for Raspberry pi gpio
   // pinMode(0, OUTPUT);		// led ?
   // pinMode(1, INPUT);	  // padbutton
   // pinMode(2, INPUT);      //tamponbutton

   while(!isEmpty){
   // Selecting and checking if the buttons are pressed
   // If the button is pressed only one product can be selected
   // TODO: format as function
   if (padButtonPressed) {
       padIsChosen = true;
       tamponIsChosen = false;
   } else if (tamponButtonPressed) {
       tamponIsChosen = true;
       padIsChosen = false;
   }


   // Dispensing
   // digitalWrite(0, dispensing ? HIGH : LOW);

   // Dispense product if button is pressed and not currently dispensing
      if(padButtonPressed || tamponButtonPressed) {
         if(!dispensing) {
            dispensing = true;
         
         dispenseCycles++;
            //error handling
            auto startTime = chrono::steady_clock::now();
                while (dispensing && chrono::steady_clock::now() - startTime < chrono::milliseconds(dispenseTime)) {
                    // Check if the dispenser becomes empty during dispensing , should be replaced with sensor
                    if (dispenseCycles > 20) {
                        cout << "Error! Empty!!" << endl;
                        dispensing = false;
                        break;
                    }
                    // Check if the timeout has been reached
                    if (chrono::steady_clock::now() - startTime >= chrono::milliseconds(dispensingTimeout)) {
                        cout << "Error! Timeout!!" << endl;
                        dispensing = false;
                        break;
                    }
                }

            // Wait for dispenseTime milliseconds
            std::this_thread::sleep_for(std::chrono::milliseconds(dispenseTime));

            dispensing = false;

            // Reset buttons
            padButtonPressed = false;
            tamponButtonPressed = false;
         }

      }
      //if there is no specific sensor to check?
      if(dispenseCycles > 20){
         isEmpty = true;
      }

   }

   return 0;
}
