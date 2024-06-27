#include"headers.h"
void change_path1(char* path,char*str,char* disp_path)
{
  
    strcpy(prev_path,disp_path);
    strcpy(prev_abs_path,path);
    char* path12=(char*)malloc(sizeof(char)*4096);
   
  // for new directory that is returned by the getcwd function
    if(chdir(str)!=0)
    {perror("Directory could not be changed\n");
    return;}
    getcwd(path12,4096);
    
    int i=0;
    int count1=0;int count2=0;

    while(i<strlen(path12) && i<strlen(path)) // to compare both the current and returned path 
    {
        if(path12[i]!=path[i])
        break;
         else
         i++;
    }
    if(i==strlen(path)) // modify the current by considering the cases 
    {
        if(strlen(path12)>strlen(path)) // if the current directory returned lies within the home of the terminal 
        {                     
            if(path12[strlen(path12)-1]=='/')
            path12[strlen(path12)-1]='\0';
            char* str1=path12+strlen(path);
            char str2[4096];
            strcpy(str2,str1);
            strcat(disp_path,str2);
            strcpy(path,path12);
            
        }        
    }
      else if(i==strlen(path12))
    {   strcpy(prev_abs_path,path);
        strcpy(path,path12);
        strcpy(prev_path,disp_path);
       i=0;
        while(i<strlen(org_abs_path) && i<strlen(path)) // to compare both the current and returned path 
    {
        if(org_abs_path[i]!=path[i])
        break;
         else
         i++;
    }
    if(i==strlen(org_abs_path))
    {
        char* str1=path12+strlen(org_abs_path);
            char str2[4096]="~";
            strcat(str2,str1);
            strcpy(disp_path,str2);
    }       
            
    }
    else  // if the new directory is outside the new home of the terminal
    {
          strcpy(path,path12);
        i=0;
        while(i<strlen(org_abs_path) && i<strlen(path)) // to compare both the current and returned path 
    {
        if(org_abs_path[i]!=path[i])
        break;
         else
         i++;
    }
    if(i==strlen(org_abs_path))
    {
        char* str1=path12+strlen(org_abs_path);
            char str2[4096]="~";
            strcat(str2,str1);
            strcpy(disp_path,str2);
    }
       }
    free(path12);

}
char* convert(char *m)
{
     int i=0;
    int c=0;
    char prev_path1[4096];
    char prev_abs_path1[4096];
    char disp_path1[4096];
    char path1[4096];
    strcpy(prev_path1,prev_path);
    strcpy(prev_abs_path1,prev_abs_path);
    strcpy(disp_path1,disp_path);
    strcpy(path1,path);

    char str[4096]={'\0'};
    int flag1=0;
   while(1)
   {
      
    if(strlen(m)<=4)
    {
       flag1=1;
      strcpy(prev_path,disp_path);
      strcpy(disp_path,"~");
      
      strcpy(prev_abs_path,path);
      strcpy(path,org_abs_path);
      printf("%s\n",path);
      
     break; 
    }
    if(m[i]=='\0')
    break;
    else if(m[i]=='-')
    {
        flag1=1;
      char* path2=(char*)malloc(sizeof(char)*4096);
      strcpy(path2,prev_path);
      strcpy(prev_path,disp_path);
      strcpy(disp_path,path2);
         
      strcpy(path2,prev_abs_path);
      strcpy(prev_abs_path,path);
      strcpy(path,path2);
     chdir(path);
      char* new_path=(char*)malloc(sizeof(char)*4096);
strcpy(new_path,path);
strcpy(path,path1);
strcpy(prev_abs_path,prev_abs_path1);
strcpy(disp_path,disp_path1);
strcpy(prev_path,prev_path1);
chdir(path);
strcpy(target_directory,new_path);
return new_path;
      
      free(path2);
      i++;
    }
    else if(m[i]=='~')
    {
       flag1=1;
      strcpy(prev_path,disp_path);
      strcpy(disp_path,"~");
     


      strcpy(prev_abs_path,path);
      strcpy(path,org_abs_path);
      chdir(org_abs_path);
  char* new_path=(char*)malloc(sizeof(char)*4096);
strcpy(new_path,path);
strcpy(path,path1);
strcpy(prev_abs_path,prev_abs_path1);
strcpy(disp_path,disp_path1);
strcpy(prev_path,prev_path1);
chdir(path);
strcpy(target_directory,new_path);
return new_path;
     
     i++;
    }
 
    else if(m[i]!=' ')
    {
        flag1=0;
       str[c++]=m[i++]; 
    }
    else if(m[i]==' ')
    {
        c=0;
        int l=strlen(str);
        int j=0;
        change_path1(path,str,disp_path);
    } 
   }
   if(flag1==0)
 {   change_path1(path,str,disp_path);

  char* new_path=(char*)malloc(sizeof(char)*4096);
strcpy(new_path,path);
strcpy(path,path1);
strcpy(prev_abs_path,prev_abs_path1);
strcpy(disp_path,disp_path1);
strcpy(prev_path,prev_path1);
chdir(path);
strcpy(target_directory,new_path);
return new_path;


 }
  

}