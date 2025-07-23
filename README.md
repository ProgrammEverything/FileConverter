
# FileConverter
THIS PROJECT DOES NOT CONTAIN A INSTALLER IT IS A PORTABLE EXECUTABLE FOR LINUX \
This project was initially made for converting all kinds of file types to another (videos, images, 3D Models, etc...) 

However since It is too hard to me (Atleast right now) I have only implemented some picture types to the other

- Well How does it work?

-  - It uses the "CImage" library for processing images

-  - Uses WxWidgets for displaying GUI's

-  - (Does not have thread support right now. So it may hang a little bit)

All documentation will be on my documentation website (You can check that out) \
So what does this project do? \
This project has a simple interface allowing you to convert between types of files. 

![Screenshot](https://github.com/ProgrammEverything/FileConverter/blob/master/images/screenshot.png) \
As you can see there is a toolbar at the top and 2 lists \
The first list is used for inserting files into it \
The second list is used for the actual conversion \
When you click onto the "Import files" You can import any number of files (Other than folders) \
When you are done you click OK (It will not be added unless you click OK)
- You can remove selected items from the list using the cancel button
- You can select all or deselect all from the "Select all items" button
- These two commands can be used within the "Export list" and the "Work list" (Both lists) based on which list is focused
- After doing your work. You can insert it into the second list by clicking "Save to export list" 
- After removing or adding onto the export list. You can click export to export all files.
- - If there is no file it will error so be careful
- You choose your save file. This is very important to know that
- -  If you don't put any extensions the program will put the default extension for the type for you
- - The file you choose to save will be in order of adding and It will add a number to the name of each file
 ```
 For example the following structure of files:
	 Mycat.png
	 MyOtherCat.png
	 MyCatCatCatsCat.png
	 MyOtherCatCatCatCatsOfACatOfCat.png
If I choose to save it in a folder called "Images"
and the save file as Cat and the type Jpeg
The following files will be made onto Images
	Cat1.jpg
	Cat2.jpg
	Cat3.jpg
	Cat4.jpg
```
If any file encounters errors (ImageMagick must be installed on your computer) \
A popup will appear stating the information for the error \
(All technical stuff related to the documentation page) \
If something goes wrong the following popup will be shown: \
![Error popup](https://github.com/ProgrammEverything/FileConverter/blob/master/images/screenshot_error.png) \
It contains information about where it occured what function and etc... \
After all logging (like error) about the files the following will be shown \
![Info popup](https://github.com/ProgrammEverything/FileConverter/blob/master/images/screenshot_info.png) \
Which will tell you what went wrong and all other info. You can copy the metadata or the whole error by their respective buttons \
The Box in the right of the picture (top right) which says (PNG Format) means all files exported will be exported to type of that Format \
For example "PNG Format" will be ".png"
## How to build
To build this program. You need the following dependencies. And all other dependencies relating to it: 
- ImageMagick (For converting images)
- WxWidgets   (For GUI)
### Needed build tools
- CMake
- Make or Other build systems (You have to use cmake for that)


Download and extract the project. Or use git for cloning. 
Run these commands for generating a make file and then building it. (If you don't want to use make. You can configure that from CMake)
```
cmake . -B build
```
Go into the directory build (`cd build`)\
Run `make` 
```
make
```
Then a file called `Platformer` will be built. You can execute it by using the following command (In the directory of build):
```
./Platformer
```
Note: For building in release mode you can use the `-D CMAKE_BUILD_TYPE=Release` argument for cmake and for debug you can use the `-D CMAKE_BUILD_TYPE=Debug` cmake argument.