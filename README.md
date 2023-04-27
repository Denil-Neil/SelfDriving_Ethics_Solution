# Ethical Car AI

This project proposes a solution to the ethical dilemma of self-driving cars as outlined by Patrick Lin's TED Talk in 2016, using a C++ program with Jsonrpccpp and Object-Oriented Programming (OOP).

The program implements a decision-making algorithm that takes into account various ethical considerations, such as prioritizing the safety of passengers, pedestrians, and other drivers. It also considers legal liability and moral responsibility when making decisions.

TED Talk Link: [Click Here](https://www.youtube.com/watch?v=ixIoDYVfKA0&ab_channel=TED-Ed)

## Requirements
To use this program, you need to have the following installed:

* C++ compiler (supporting C++11 or later)
* Jsonrpccpp library
* Jsoncpp library

## Installation
1. Clone the repository or download the source code
2. Install the required libraries
3. Compile the program using a C++ compiler

## Usage
To run the program, type make to execute the makefile, then create the three servers in order:
* ./car
* ./motor1
* ./motor2

As soon as the three servers are created, the car.cpp (auto v) will receive data from motor1 and motor2, then compare their information (for default motor1 has a higher safety rating), so the car will send different messages to both motorcycles:
* motor1 will know that it's going to be crashed.
* motor2 will know that it's safe.

The program will then communicate with the server using Jsonrpccpp and make decisions based on the data received from various sensors.
