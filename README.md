# SDVX-Controller
This is a life size Sound Voltex (SDVX) Controller made with Arduino Pro Micro

Gameplay: https://youtu.be/JhOCCdDn6Mc

## What is the goal?
As an avid rhythm game player, I have always wanted to play one specific game, Sound Voltex. Sound Voltex (or SDVX for short) is an arcade rhythm game that is only found in Japan, however many people have bought the arcade machine themselves and are now around the world. In the area I live, there is only one spot that has this machine, but it is across the country. People have made life sized controllers for this game as well, however they are very pricey going up to $500 USD for just one controller. So I came up with an idea and wanted to make my own contrller! Since I don't have the arcade game myself, someone has recreated the game so it is playable on all computers, which is how I will be demonstrating this controller. 

The goal of this project is to create a life-sized SDVX Controller so that this video game is accessable to people without the arcade machine. Below this are some tasks that are required for this project to be successful: 

### Tasks
- Create a list of parts required and acquire them
- Create the dimensions of the casing
- Create a schematic diagram and pinout list
- Create the case using HDFs
- Assemble parts and circuit 
- Polish and finish the final product

## Pre-Assembly

### Parts list
| Part | Amount |
| ----------- | :-----------: |
| Medium Density Fiberboard (MDF) 48”x24”x1/4” | 1 | 
| 60mm Square Button | 4 |
| 45mm Rectangle Button | 2 |
| 33mm Square Button | 1 |
| Optical Rotary Encoder | 2 |
| 6mm D-Shaft Knobs | 2 |
| Arduino Pro Micro | 1 |
| USB-C Cable  | 1 |
| 100pc Spade Connector | 1 |
| 5m Strip Wire | 1 |

### Button Layout and Naming
![sdvx layout](https://user-images.githubusercontent.com/67884995/209450498-75a98e8d-c59a-4119-a280-958cf7c1a38d.png)

### Pinout 
| Button | Switch Pin |
| ------ | :--------: |
| BT-A | A2 |
| BT-B | A3 |
| BT-C | A9 |
| BT-D | A10 |
| FX-L | A0 |
| FX-R | A1 |
| START | 6 |

| Encoder | A Pin | B Pin |
| ------- | :----: | :----: |
| Left | 0 | 1 |
| Right | 2 | 3 |

## The Building Process
The link below has the whole building process of this project and how I put everything together.
Building the case: https://imgur.com/a/ZvbhlnX

I have also added the arduino code for this project, which has all the buttons mapped to some keyboard input and the encoders to the mouse movements. 

