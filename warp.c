#include "headers.h"

 
void change_path(char* path,char*str,char* disp_path)
{
  
    strcpy(prev_path,disp_path);
    strcpy(prev_abs_path,path);
    char* path1=(char*)malloc(sizeof(char)*4096);// for new directory that is returned by the getcwd function
    if(chdir(str)!=0)
    {perror("Directory could not be changed\n");
    return;}
    getcwd(path1,4096);
    
    int i=0;
    int count1=0;int count2=0;

    while(i<strlen(path1) && i<strlen(path)) // to compare both the current and returned path 
    {
        if(path1[i]!=path[i])
        break;
         else
         i++;
    }
    if(i==strlen(path)) // modify the current by considering the cases 
    {
        if(strlen(path1)>strlen(path)) // if the current directory returned lies within the home of the terminal 
        {                     
            if(path1[strlen(path1)-1]=='/')
            path1[strlen(path1)-1]='\0';
            char* str1=path1+strlen(path);
            char str2[4096];
            strcpy(str2,str1);
            strcat(disp_path,str2);
            strcpy(path,path1);
            
        }        
    }
      else if(i==strlen(path1))
    {   strcpy(prev_abs_path,path);
        strcpy(path,path1);
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
        char* str1=path1+strlen(org_abs_path);
            char str2[4096]="~";
            strcat(str2,str1);
            strcpy(disp_path,str2);
    }       
            
    }
    else  // if the new directory is outside the new home of the terminal
    {
          strcpy(path,path1);
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
        char* str1=path1+strlen(org_abs_path);
            char str2[4096]="~";
            strcat(str2,str1);
            strcpy(disp_path,str2);
    }
       }
    free(path1);

}
void warp()
{
    int i=5;
    int c=0;
    char str[4096]={'\0'};
    int flag1=0;
   while(1)
   {
      
    if(strlen(input_im)<=4)
    {
       flag1=1;
      strcpy(prev_path,disp_path);
      strcpy(disp_path,"~");
      
      strcpy(prev_abs_path,path);
      strcpy(path,org_abs_path);
      printf("%s\n",path);
      
     break; 
    }
    if(input_im[i]=='\0')
    break;
    else if(input_im[i]=='-')
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
      printf("%s\n",path);
      
      free(path2);
      i++;
    }
    else if(input_im[i]=='~')
    {
       flag1=1;
      strcpy(prev_path,disp_path);
      strcpy(disp_path,"~");
     


      strcpy(prev_abs_path,path);
      strcpy(path,org_abs_path);
      chdir(org_abs_path);
      printf("%s\n",path);
     
     i++;
    }
    else if(input_im[i]!=' ')
    {
        flag1=0;
       str[c++]=input_im[i++]; 
    }
    else if(input_im[i]==' ')
    {
        c=0;
        int l=strlen(str);
        int j=0;
        change_path(path,str,disp_path);
    } 
   }
   if(flag1==0)
 {   change_path(path,str,disp_path);
printf("%s\n",path);



 }
  

}