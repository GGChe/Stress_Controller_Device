![StressFree.org Banner](https://github.com/GGChe/Stress_Controller_Device/blob/master/User%20Manual%20%26%20Support%20Documents/Pictures/Banner.png)
[![Github Quickguide](https://travis-ci.com/GGChe/Stress_Controller_Device.svg?branch=master)](https://travis-ci.org/GGChe/Stress_Controller_Device/)
[![first-timers-only Friendly](https://img.shields.io/badge/first--timers--only-friendly-blue.svg)](http://www.firsttimersonly.com/)
[![Open Source Helpers](https://www.codetriage.com/ggche/stress_controller_device/badges/users.svg)](https://www.codetriage.com/ggche/stress_controller_device)



# Welcome to FreeStressGame's open source Project!

Our tream provides an open-source real time embedded project based on the development of a real time biomedical device which aim is to monitor the stress level of a videogame player. This project is open source and anyone is invited to contribute freely sharing all your tips and modifications

## Table of Contents

* [Introduction](#introduction)
* [Methodology](#methodology)
* [Required Components](#required-components)
* [System Manual](#system-manual)
* [Found a Bug](#found-a-bug)
* [Contributing](#contributing)
* [Pubilcation](#publication)
* [SNS](#sns)
* [License](#lisence)


### Introduction


According to the World Health Organisation, mental disorders are a main topic in global health, specially because one in four people in the world will be affected by mental or neurological disorders at some point in their lives. It is estimated that more that 450 million people are currently suffering from such disorders, placing this risk to the top of all the ill-health's causes and disability worldwide. The main mental disorder is depression, and in many situations it is caused by stress. Nowadays, stress is a risk that every person need to face in some point of the day, like work, house, friends, etc. 

There is evidence available that supports the fact that the stress is one of the main triggers of depression. More in detail , such evidence shows that depression can stem from chronic overstimulation of the body's hypothalamic-pituitary-adrenal axis, which produces cortisol in humans. However, while adults can face the stress with therapy and different skills, children are a very enthreaten sector of the population that does not own skills against that. 

With the mentioned before, we can imagine that one of the most risky situations for a child are videogames where we set an unprepared person against a stressfull and addictive situation, causing severe damage on the child. 

Then, this project constitutes a reliable and attractive solution for parents, therapists and adults that want to monitor and control the stress status of the player.

### Methodology
#### [HeartBeat Detection]
The heartbeat measurement technology that we chose for this project is the photopletismography. 
This technique is based on the use of a photodiodethat emits a light pulse in a specific wavelength which, after passing by the blood vessel, the wavelength signal captured by the photosensor changes.  

![OUTLINE](https://user-images.githubusercontent.com/46483800/56081586-d5207680-5e06-11e9-939d-f019cedb7b10.png)<img width="3" height="3"></img>

According to that change, we can determine whether a pulse of blood has passed in a specific time, depending on our sampling rate.  


#### [Stress Recognition] 
Once the signal is taken, it is carried to the raspberry Pi using a proper wirebased connection to avoid any unwanted interaction with other signals and for a better performance of the device.  
Then, the Raspberry PI will process the data in real time and, at the same time, it will do a basic threshold based control for deciding whether the person is under stress or not. When this process recognize the stress, it makes beep sound for warning. 

![img1](https://user-images.githubusercontent.com/16301652/76198963-43c0ac80-61ef-11ea-9122-5f8dfcf463b7.png)


### Required Components 
The device consists of the next components:
- Raspberry Pi 3 B+
- PCB adaptor: 
  * 2 X 2Kohm SMD resistors
- Wrist sensor:
  * VEML6030 Light sensor 
  * 1 X IR LED
  * 1 X 1 Kohm SMD resistor 
  * 1 X 10 Kohm SMD resistor
  * 1 X 1000 nF SMD capasitor 
- Piezo Buzzer
- RJ45 Cable
- Finger / Band type case for Wrist sensor
- Raspberry Pi case 

All circuit schematics / PCB Eagle files/ 3D Solidworks files are included in UPLOADED DOCUMENTS. 

### System Description 

#### Hardware section 
In this section you will find useful information of how to replicate our project. Given the components listed before, you need to print the pcb, which files and more deep information is shown in the PCB folder.  

![OUTLINE](https://user-images.githubusercontent.com/46483800/56098901-de403f00-5efd-11e9-93b5-40b94c091432.JPG)<img width="3" height="3"></img>
![pin outline](https://user-images.githubusercontent.com/46483800/55650311-3b8d0f80-57dd-11e9-888e-57d0e911ed39.JPG)
* Connect PCB adaptor with Wrist sensor by RJ45 cable
* Connect PCB adaptor pins with Raspberry Pi pins as shown in below table 

<p align="center">
<img width="250" height="200" src="https://user-images.githubusercontent.com/16301652/56097786-d332e200-5ef0-11e9-94b8-7715ed1de8a4.PNG")
</p>
 
<p align="center">
<img width="250" height="150" src="https://user-images.githubusercontent.com/16301652/56097791-dcbc4a00-5ef0-11e9-86bb-00c68b79a9ae.PNG")
</p>

#### Software section

##### Software setting 
To build our program in your Pi, you need to follow some steps.  

```
sudo apt-get update

git clone https://github.com/GGChe/Stress_Controller_Device
```
You would need to update and install the libraries of PHP5.6, Apache2 and compilers if your are working on a vanilla version of the OS.

```
sudo apt-get install php5.6

sudo apt-get install apache2

sudo apt-get install g++
```
If you have any problem installing php5.6 in Raspbian, cause it is not very well supported, follow this guide:
https://unnikked.ga/how-to-install-php-5-6-on-a-raspberry-pi-2-5fd93879cb14

##### Driver 
We developed a driver for the VEML6030 sensor, that uses I2C communication protocol, using the data obtained from the link below. The driver given in that project was initially prepared for Arduino but we had to modify it completely to make it run in every system using a proper c++ code.

[Mbed VEML6030 Driver](https://os.mbed.com/teams/MSS/code/VEML6030/)

##### Compilation from source

To compile the whole code, you only need to go to the code's folder and type on the terminal

```
cmake .

make 

sudo ./StressC.out
```

To run the program from the boot of the system

```
sudo nano /etc/rc.local

```

And then, write before "exit 0" the following scrypt:


```
sudo ./PATH/StressC.out

```

### Found a bug?

Bugs can be reported at: https://github.com/GGChe/Stress_Controller_Device/issues

Please try the latest release build before reporting, be sure to also include any logs or steps to reproduce you may have, as well as your Forge version, and whether or not you are using a third party loader such as Cauldron. When submitting logs please use a service such as Pastebin, do not paste the log directly into the issue.

### Contributing

Ahmed Elmogamer 
* Main role: Software Engineer 
* Specific tasks 
  : Coding the main program and making sensors' driver.  

Daewon Jung  
* Main role: Mechanical Engineer 
* Specific tasks 
  : Designing cases, assist making PCB and Promotion. 
  
Gabriel Galeote Checa 
* Main role: Electronic Engineer 
* Specific tasks 
  : Designing PCB and Website architecture development, Fabrication and Soldering of the PCB. 
  
### Publication
Check our publication in Hackaday.

[<img src="https://user-images.githubusercontent.com/46483800/56085357-98ba3e00-5e39-11e9-9d22-95d3b9b24ce1.png" width="130">](https://hackaday.io/project/164972-free-stress-gaming)

### SNS 
In our socialmedia you can find some demos and video explanations of how the system works. 

[<img src="https://user-images.githubusercontent.com/46483800/56038160-29552900-5d29-11e9-81a1-04e26ac6b5c5.jpg" width="50">](https://www.youtube.com/channel/UC1Y8QuR_0B8nRpyRaub2-ag)

[<img src="https://user-images.githubusercontent.com/46483800/56040715-eb5b0380-5d2e-11e9-84c1-765cc2f00ddd.jpg" width="50">](https://www.instagram.com/free_stress_gaming/)

Check our two youtube videos explaining how the system works!
- https://www.youtube.com/watch?v=JRjO4hhqV6E
- https://www.youtube.com/watch?v=9uvpTM_b6e0&t=2s
### Credits

This project used the current driver uploaded in mbed for other purposes, we fixed some errors for the VEML6030 use in RPI and we had to recode some sections of the driver.

We also wannt to thanks our mate Cheng who was really helpful in the lab.

### License

The MIT License
