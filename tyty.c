#include<stdio.h>  
//#include<conio.h>  
#include<string.h>  
//#include<io.h>                                   /*input/outpot header file*/  
#include<stdlib.h>
#include <unistd.h>  
#include <fcntl.h>

int main()  
    {  
       //clrscr();  
       char *filename="/dev/ttyACM0";
       int filedes, close_err;  
       /*open the file , filename for writing or create It if it does not exist*/   
       filedes= open(filename , O_RDWR);  
       // write data
       write(filedes, "q", 2); //gauche
		sleep(5);
		write(filedes, "d", 2); // droite
		sleep(5);
		write(filedes, "d", 2);//droite
		sleep(5);
		write(filedes, "d", 2);//droite
		sleep(5);
		write(filedes, "q", 2);//gauche
		sleep(5);
		write(filedes, "s", 2);//arriere
		sleep(5);
		write(filedes, "z", 2);//avant
		sleep(5);
		write(filedes, "q", 2);//gauche
		sleep(5);
		write(filedes, "s", 2);//arriere
		sleep(5);
		write(filedes, "d", 2);//droite
		sleep(5);
		
	   close(filedes);  
       //getch();  
       return 0;  
    }
