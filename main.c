#include "headers.h"

char input[4096];
char path[4096];
char disp_path[4096]={'~'};
char prev_path[4096]={'~'};
char prev_abs_path[4096];
char org_abs_path[4096];
int flag=0;
int count_com=0;
char input_str[4096];
char search[4096]=".";
char path_search[4096]=".";
char target_directory[4096];
char new_disp_path[4096];
char input_im[4096];
char prev_entry[4096];
char history_path[4096];
int main()
{
    // Keep accepting commands
    getcwd(org_abs_path,4096);
       strcpy(path,org_abs_path);
         strcpy(target_directory,org_abs_path);
         strcpy(history_path,org_abs_path);
         strcat(history_path,"/history.txt");
         int fd=open(history_path,O_CREAT|O_RDWR,0644);
         if(fd<0)
         {
            perror("File could not be opened\n");
         }
         else 
         {
            lseek(fd,-1000,SEEK_END);
            char q[1000]={'\0'};
            if(read(fd,q,1000)==0)
            strcpy(prev_entry,"\0");
            else
            {
            
            int j=strlen(q)-2;
            int c=0;
            char s[100];
            while(q[j]!='\n')
            {
                s[c++]=q[j];
                j--;
            }
            s[c]='\0';
            strcpy(prev_entry,s);
        
            lseek(fd,0,SEEK_SET);
            char u[100000]={'\0'};
            read(fd,u,100000);
            c=0;
             for(j=0;j<strlen(u);j++)
             {
                 if(u[j]=='\n')
                 c++;
             }
             count_com=c;
            }
            close(fd);
         }
    while (1)
    {
        // Print appropriate prompt with username, systemname and directory before accepting input
          
        prompt();
      
        fgets(input, 4096, stdin);
        input[strlen(input)-1]='\0';
       
       
        input_process(input);
      
   
    }
}
