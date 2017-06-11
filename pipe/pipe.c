#include <unistd.h>  
#include <stdio.h>  
#include <string.h>
int main(int argc,char **argv )  
{  
    int filedes[2];  
    char buf[BUFSIZ];  
    pid_t pid;  
      
    pipe( filedes );  
    pid=fork();          
    if (pid > 0)  
    {  
        
        
        if(write( filedes[1], argv[1], strlen(argv[1]) ) >0)  
        {
            printf( "parent process,write a string to the pipe:%s\n",argv[1]);  
             
            
            close( filedes[1] );  
             
        }
        
        
    }  
    else if(pid == 0)  
    {  
        
        if(read( filedes[0], buf ,sizeof(buf) ) > 0)
        {
           printf( "child process,read a string from the pipe:%s\n",buf); 
        }
        close( filedes[0] );  ;
        
    }  
      
    waitpid(pid,NULL,0);
      
    return 0;  
}  