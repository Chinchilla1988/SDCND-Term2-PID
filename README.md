# SDCND-Term2-PID
Project PID Controller
Videolink: https://www.youtube.com/watch?v=Ti7SBQzHvSA&feature=youtu.be
Describe the effect each of the P, I, D components had in your implementation.

In this Project I implemented a PID-Controller to control the lateral dynamics of the vehicle.

The P-gain is a factor which is multiplicated with the acutal Cross-Track Error. If the P-Gain is small the controller reacts very slowly. If it's big the controller reacts fast and it might overshoot. To tune this parameter the velocity should be kept constant and you should try several P-Gain Parameters. If the oscillation is constant in it's amplitude, we found the critical P-Gain. Every Factor above the critical P-Gain results in instability. In order to have a good P-Gain choose the parameter 10 till 20 percent smaller than the critical P-Gain.

The I-gain is a parameter which is multiplicated with the Integral-Error. The Integral-Error behaves like a batch or storage which stores all values from the past added with the actual CTE-value. If the sum of the Integral-Error is zero, the I-Controller is deactivated, otherwise it's activated. If the I-gain is too small the car tend to drift for longer times. It takes too long to eliminate the CTE!

The D-gain is a parameter which is multiplicated with the Derivative-Error / Difference between past and actual CTE. If the Difference is not zero the Controller is activated, else it's set to zero. The bigger the D-gain the faster the controller reacts. If the D-gain is too big it might lead to a constant steering angle. If its too small it might overshoot. The D-controller is not diminishing the CTE but the derivative of the CTE. It helps to converge smoothly and fast to the desired position.

Parameter-Tuning:

To tweak the parameteres I started with a simple P-Controller. After I found my P-gain, I implemented the D-Gain. In the end I tried to implement the I-gain. While driving at high velocity the car started oscillating, because the increase of the velocity is influencing vehicle dynamics. So I decided to neglect the I-gain and implemented a PD-Controller.

The final parameters are: 
      P -> 0.2
      I -> 0
      D -> 5

CarND-Controls-PID

Self-Driving Car Engineer Nanodegree Program

Dependencies

cmake >= 3.5
All OSes: click here for installation instructions
make >= 4.1
Linux: make is installed by default on most Linux distros
Mac: install Xcode command line tools to get make
Windows: Click here for installation instructions
gcc/g++ >= 5.4
Linux: gcc / g++ is installed by default on most Linux distros
Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
Windows: recommend using MinGW
uWebSockets
Run either ./install-mac.sh or ./install-ubuntu.sh.
If you install from source, checkout to commit e94b6e1, i.e.
git clone https://github.com/uWebSockets/uWebSockets 
cd uWebSockets
git checkout e94b6e1
Some function signatures have changed in v0.14.x. See this PR for more details.
Simulator. You can download these from the project intro page in the classroom.
There's an experimental patch for windows in this PR

Basic Build Instructions

Clone this repo.
Make a build directory: mkdir build && cd build
Compile: cmake .. && make
Run it: ./pid.
Editor Settings

We've purposefully kept editor configuration files out of this repo in order to keep it as simple and environment agnostic as possible. However, we recommend using the following settings:

indent using spaces
set tab width to 2 spaces (keeps the matrices in source code aligned)
Code Style

Please (do your best to) stick to Google's C++ style guide.

Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using cmake and make!

More information is only accessible by people who are already enrolled in Term 2 of CarND. If you are enrolled, see the project page for instructions and the project rubric.

Hints!

You don't have to follow this directory structure, but if you do, your work will span all of the .cpp files here. Keep an eye out for TODOs.
Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice. If you've created a profile for an IDE that you think other students would appreciate, we'd love to have you add the requisite profile files and instructions to ide_profiles/. For example if you wanted to add a VS Code profile, you'd add:

/ide_profiles/vscode/.vscode
/ide_profiles/vscode/README.md
The README should explain what the profile does, how to take advantage of it, and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles before. I believe the best way to handle this would be to keep them out of the repo root to avoid clutter. My expectation is that most profiles will include instructions to copy files to a new location to get picked up by the IDE, but that's just a guess.

One last note here: regardless of the IDE used, every submitted project must still be compilable with cmake and make./
