** TO USE:
* Create a folder named C:\Projects
* Open CMD
* type 'cd C:\Projects'
* type 'git clone https://github.com/johnmwilburn/Computer-Organization-Project'
* [Make your git credentials work somehow until the clone works properly.]

* Open the cloned solution file with Visual Studio 2019
* Go to Project > ComporgProject Properties > Debugging > Command Arguments
* Ensure that the first option is set to -d or -e depending on if you want to decrypt or encrypt
* Ensure that the path to the target file is something like C:\Projects\Computer-Organization-Project\<what you want to decrypt / encrypt>
* Ensure that the path to the key file is C:\Projects\Computer-Organization-Project\Key.dat

* Everything should now be configured to execute the program