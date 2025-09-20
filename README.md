# FileStealer
My first attempt at C++.
The idea was to be able to search a PC for a file and then copy it to a USB drive. It works partially, but not all files are found even if they exist. This will be fixed when I get the chance. I would appreciate any feedback. 

First, enter the letter of your USB or other device and then the name of the file you are looking for, including the extension. If it is found, it will be copied to the corresponding device. Information about the file can be found in FileStealerInfo.txt.

At the moment, it only searches the Recycle.bin, which is the last major component that needs to be fixed in order to complete the programm. 
However, I haven't found a solution for this yet, as I first need to properly understand the library and folder structures in general.

It is now possible to search an entire list; simply paste it into NameList.txt. Each entry must be on a separate line.

(The letter of your USB device must be D).
