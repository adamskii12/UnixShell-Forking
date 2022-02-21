This program begins with asking the user for input from the command line (“Your command > “). 
From then on, the program will execute differently depending on the input; if the input ends with the ampersand character (&), only the parent process will run in the program. 
If there is no ampersand, the program will fork into two process: the parent, and the child. 
The child will then execute the command given by the user while the parent waits for the child to finish. 
Once the child finishes, the parent process resumes and the program is taken back to the beginning of the while loop and asks the user for another command. 
The user can terminate the program by simply inputting Ctrl+C.
