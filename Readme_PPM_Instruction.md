In this Firmware build we have added the Receiver input selection mode
    -->Lib name:   RxMode.h 
    -->Scope   :   rxconfig()
    -->Syntax  :   RX.InputStatus(PPM_IP); //For Selecting PPM mode input
                   RX.InputStatus(MSP_IP); //For Selecting Wi-Fi mode input
To download the Firmware build, click the following link: https://github.com/techsavvyomi/Magis
Steps to use this Firmware in your current Cygnus build
1. Open the given link
2. click on the green Code button, Now select download as zip.
3. Extract the zip in one folder
4. Now create a new worspace in Cygnus
5. click on the file from the menu bar then open projects from files system
6. Now click on the windows then click on the perspective now select C/C++
7. Open C button to select the add to c++ nature of the project.
8. click on the mafile project and- ARM Cross GCC.
9. Now your Native Firmware is set up properly. 
For mor details pleade chrcout following link: https://docs.google.com/document/d/1_X4itSaUjFtl0rr2xG9-2RV-aztFCH1I9iCWbyf6xlU/edit

Sample Program: PlutoPilot.cpp

![ppm_sample](https://user-images.githubusercontent.com/41143602/171610512-c9a3dd1f-8746-4606-b7b8-4e6c7644b064.PNG)
