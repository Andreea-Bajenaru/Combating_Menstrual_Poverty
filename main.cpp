// Main file for the code

#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int main(){
   bool padButtonPressed = false;
   bool tamponButtonPressed = false;
   bool dispensing = false;
   int dispenseTime = 5000; // 5 seconds

   while(true){
   // Selecting and checking if the buttons are pressed

   // Dispensing

   // Dispense product if button is pressed and not currently dispensing
      if(padButtonPressed || tamponButtonPressed) {
         if(!dispensing) {
            dispensing = true;
      
            // Wait for dispenseTime milliseconds
            std::this_thread::sleep_for(std::chrono::milliseconds(dispenseTime));

            dispensing = false;

            // Reset buttons
            padButtonPressed = false;
            tamponButtonPressed = false;
         }

      }

   }

   return 0;
}
