#include"headers.h"
void proclore(int pid)
{
  char status[4096];
  snprintf(status,4096,"/proc/%d/status",pid);
  FILE *status_file = fopen(status, "r");
    if (status_file == NULL) {
        perror("Given pid doesnot exist or cant retrieve the information\n");
        return ;
    }
     printf("pid: %d\n", pid);
    
  char line[1000];
  while(fgets(line,1000,status_file))
  {
   
        if (strstr(line, "State:") == line) {
            char*y=line + strlen("State:");
            int j=0;
            while(j<strlen(y))
            {
                if((int)y[j]>=65 && (int)y[j]<=90)
                {printf("Process Status: %c\n",y[j]);
                break;}
                y++;
            }
            
        }
        }
        fclose(status_file);
        status_file = fopen(status, "r");
         printf("Process Group: %d\n", getpgid(pid));  
while(fgets(line,1000,status_file))
  { if (strstr(line, "VmSize:") == line) {
            printf("Virtual Memory:%s", line + strlen("VmSize:"));
        }
  }
  
   fclose(status_file);

    char executable[4096];
    snprintf(executable, 4096, "/proc/%d/exe", pid);

    char exe_link[4096];
    ssize_t exe_size = readlink(executable, exe_link, sizeof(exe_link) - 1);
    if (exe_size != -1) {
        exe_link[exe_size] = '\0';
        printf("Executable Path: %s\n", exe_link);
    } else {
        perror("Error reading executable path");
    }

 
}

