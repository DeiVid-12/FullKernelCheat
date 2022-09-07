# FullKernelCheat
- FullKernelCheat is a educational project that demonstrate how a driver can use to hack games, without any communication method
- The purpose of this project is educational, if you are learning the basics of windows kernel development this project is very useful
- Only contains basics functions like get module base, read and write virtual memory

# Detection vectors
- This project eliminates some detection vectors because of not using any communication with usermode
- Use MmCopyVirtualMemory so can be detect by good kernel anticheats
- This driver use a thread to make a loop, that can be easily detect
- The project is not designed with security as priority, so you have to modify this driver to make it safer

# Compiling
- Install visual studio 2019
- Install windows driver kit
- Download the project
- Compile in x64 or x86 

# Installing the driver
- Put computer on test mode bcdedit /set testsigning on
- Restart your computer
- Create a service for driver sc create smk type=kernel binpath="path to driver"
- Start the service sc start smk

### Note: It's not a safe mode to load a cheat driver, look for methods to manual map your driver with a vulnerable driver
