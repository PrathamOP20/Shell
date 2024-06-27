#include "headers.h"


void prompt() {
   char* host_name=(char*)malloc(sizeof(char)*HOST_NAME_MAX);
  gethostname(host_name,HOST_NAME_MAX);

   
  char* username=(char*)malloc(sizeof(char)*LOGIN_NAME_MAX);
  getlogin_r(username,LOGIN_NAME_MAX);
  username[strlen(username)]='@';
 
  


   printf(COLOR_CYAN"%s%s"COLOR_RESET,username,host_name);
   printf(COLOR_GREY":%s> "COLOR_RESET,disp_path );

free(host_name);
free(username);
     
}
