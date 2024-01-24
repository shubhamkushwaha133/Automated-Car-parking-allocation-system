# Automated car Parking Allocation System
Throughout this century, population increase has been a significant issue. It goes without saying
that there will be a significant increase in the number of vehicles used as the population grows.
Moreover, parking issues would result from the congested streets and marketplaces. People will
have a hard time finding free parking slots inside the big parking areas. So, in order to solve this
issue, we intend to design a smart parking allocation system prototype. The objective is to lessen
traffic congestion and the parking allocation issue inside parking.
<br><br>
In this project, we have designed the basic circuit diagram of the model which we are proposing.
This circuit contains Arduino UNO, 20x4 LCD Display with I2C module, servo motor and IR
proximity sensors. The first two IR sensors which are adjacent to the servo motor are used to
maintain the count of available slots in the parking lot. Whenever any vehicle passes through
these two IR sensors from out to in direction then the available slot count will decrease by one
and whenever any vehicle passes from in to out direction then the available slot will be increased
by one. Other sensors which are placed at the slot in the parking lot will provide information
about which slot is available and which one is full. When slots are available and the vehicle tries
to enter in the parking lot then by the use of a servo motor the gate will be opened. The LCD
screen will be fixed at the main gate to provide full information about the parking lot.
<br><br>
<img width="2230" alt="How to make Car Parking System using Arduino" src="https://github.com/shubhamkushwaha133/Automated-Car-parking-allocation-system/assets/110382194/c3998b5b-7676-41c4-8f84-744bc6a6d224">
<br> <br>
-------------------------------------------------Proteus Simulation------------------------------------------------
<br><br>
<p align="center">
  <img src="https://github.com/shubhamkushwaha133/Automated-Car-parking-allocation-system/assets/110382194/9bb769c7-92c5-4e69-8776-24be37711945" width="1000" alt="accessibility text">
</p>
------------------------------------------------Output--------------------------------------------------------------
<br><br>
<img width="1000" alt="Screenshot 2024-01-25 003832" src="https://github.com/shubhamkushwaha133/Automated-Car-parking-allocation-system/assets/110382194/cd642381-26b5-49f8-add1-c56458b8f918">
<br><br>
