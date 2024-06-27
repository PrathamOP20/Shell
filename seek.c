#include"headers.h"
void seek(char* val,char x[])
{
    struct dirent *di;
     int i=0;
    
      char show_path[4096]=".";
 strcat(show_path,x+strlen(target_directory));
     DIR* dr = opendir(x);
    if (dr == NULL)
    {
        perror("The requested directory could not be opened\n");
        return;
    }
     while ((di = readdir(dr)) != 0)
    {
         struct stat entry_stat;
        
if(strcmp(di->d_name,".")==0 || strcmp(di->d_name,"..")==0)
continue;
    // You need to construct the full path of the current entry
    char full_path[4096];
    // if(strcmp(di->d_name,".git")==0)
    // continue;
    strcpy(full_path, x);
    strcat(full_path, "/");
    strcat(full_path, di->d_name);


    // Use stat to get file information
    if (stat(full_path, &entry_stat) == -1) {
        perror("Error getting file information");
        continue;
    }
       
        if (S_ISDIR(entry_stat.st_mode) )
        {
            char* sr=(char*)malloc(sizeof(char)*4096);
            strcpy(sr,di->d_name);
            int i=0;
            while(i<strlen(val))
            {
                if(sr[i]!=val[i])
                break;
                i++;
            }
            if(i==strlen(val))
           {flag=1;printf(COLOR_BLUE"%s/%s\n"COLOR_RESET,show_path,di->d_name);}
         
            seek(val,full_path);
        }
        else
        {
            
           char* sr=(char*)malloc(sizeof(char)*4096);
            strcpy(sr,di->d_name);
            int i=0;
            while(i<strlen(val))
            {
                if(sr[i]!=val[i])
                break;
                i++;
            }
            if(i==strlen(val))
           {flag=1;printf(COLOR_GREEN"%s/%s\n"COLOR_RESET,show_path,di->d_name);}
        }

    
    }
    closedir(dr);
}
void seek_d(char* val,char x[])
{
    struct dirent *di;
     int i=0;
      char show_path[4096]=".";
 strcat(show_path,x+strlen(target_directory));
     DIR* dr = opendir(x);
    if (dr == NULL)
    {
        perror("The requested directory could not be opened\n");
        return;
    }
     while ((di = readdir(dr)) != 0)
    {
         struct stat entry_stat;
        
if(strcmp(di->d_name,".")==0 || strcmp(di->d_name,"..")==0)
continue;
    // You need to construct the full path of the current entry
    char full_path[4096];
    // if(strcmp(di->d_name,".git")==0)
    // continue;
    strcpy(full_path, x);
    strcat(full_path, "/");
    strcat(full_path, di->d_name);


    // Use stat to get file information
    if (stat(full_path, &entry_stat) == -1) {
        perror("Error getting file information");
        continue;
    }
       
        if (S_ISDIR(entry_stat.st_mode) )
        {
            char* sr=(char*)malloc(sizeof(char)*4096);
            strcpy(sr,di->d_name);
            int i=0;
            while(i<strlen(val))
            {
                if(sr[i]!=val[i])
                break;
                i++;
            }
            if(i==strlen(val))
           {flag=1;printf(COLOR_BLUE"%s/%s\n"COLOR_RESET,show_path,di->d_name);}
         
            seek_d(val,full_path);
        }
       
    
    }
    closedir(dr);
}
void seek_f(char* val,char x[])
{
    struct dirent *di;
     int i=0;
      char show_path[4096]=".";
 strcat(show_path,x+strlen(target_directory));
     DIR* dr = opendir(x);
    if (dr == NULL)
    {
        perror("The requested directory could not be opened\n");
        return;
    }
     while ((di = readdir(dr)) != 0)
    {
         struct stat entry_stat;
        
if(strcmp(di->d_name,".")==0 || strcmp(di->d_name,"..")==0)
continue;
    // You need to construct the full path of the current entry
    char full_path[4096];
    // if(strcmp(di->d_name,".git")==0)
    // continue;
    strcpy(full_path, x);
    strcat(full_path, "/");
    strcat(full_path, di->d_name);


    // Use stat to get file information
    if (stat(full_path, &entry_stat) == -1) {
        perror("Error getting file information");
        continue;
    }
       
        if (S_ISDIR(entry_stat.st_mode) )
        {
            char* sr=(char*)malloc(sizeof(char)*4096);
            strcpy(sr,di->d_name);
            
         
            seek(val,full_path);
        }
        else
        {
            
           char* sr=(char*)malloc(sizeof(char)*4096);
            strcpy(sr,di->d_name);
            int i=0;
            while(i<strlen(val))
            {
                if(sr[i]!=val[i])
                break;
                i++;
            }
            if(i==strlen(val))
           {flag=1;printf(COLOR_GREEN"%s/%s\n"COLOR_RESET,show_path,di->d_name);}
        }

    
    }
    closedir(dr);
}

