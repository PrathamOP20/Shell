#include"headers.h"
void pastevents_exec(int n)
{
    
    int fd=open(history_path,O_RDONLY,0644);
    if(fd<0)
    perror("couldnot retrieve history and execute\n");
    int i=0,c=0;
    char store[100000]="\0";
    read(fd,store,100000);
    while(i<strlen(store))
    {
        if(c==n-1)
        break;
        else if(store[i]=='\n')
        {
            c++;
        }
        i++;
    }
    c=0;
    char store1[100000]={'\0'};
    while(i<strlen(store))
    {
        if(store[i]=='\n')
        break;
        else 
        store1[c++]=store[i++];
    }
 strcpy(input,store1);
 input_process(input);
 return;


}
void purge()
{
      // Open the file in write-only mode
    int fd = open(history_path, O_WRONLY,0644);
    
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    // Truncate the file to 0 length
    if (ftruncate(fd, 0) == -1) {
        perror("Error deleting the history\n");
        close(fd); 
        return;
    }
count_com=0;
   
    close(fd);

    return ;
}
void pastevents(char* x)
{
    if(strcmp(x,prev_entry)==0)
    return;
    char compare[4096]={'\0'};
    int j=0;
    for(j=0;j<10;j++)
    compare[j]=x[j];
    if(strcmp(compare,"pastevents")==0)
    return;
    char store[100000]={'\0'};
    strcat(x,"\n");
int fd=open(history_path,O_RDWR,0644);
if(fd<0)
{perror("Error storing in history\n");
return;}
if(count_com<15)
{
  
        ssize_t size=read(fd,store,100000);
        if(size<0)
       {perror("Error reading\n");}
       else if(size==0)
       {
        lseek(fd,0,SEEK_SET);
    if(write(fd,x,strlen(x))<0)
    perror("Command could not be written in history\n");
    else
    { 
             count_com++;
             strcpy(prev_entry,x);
    }
   
       }
        
    else
    {       
          lseek(fd,0,SEEK_SET);
write(fd,store,strlen(store));
 if(write(fd,x,strlen(x))<0)
    perror("Command could not be written in history\n");
    else
    {count_com++;
             strcpy(prev_entry,x);
    }
    }

    
}
else
{
    int m=count_com%15;
  m++;
  ssize_t size=read(fd,store,100000);
 lseek(fd,0,SEEK_SET);
int i=0;
int c=0;
while(i<strlen(store))
{
    if(c==m)
    break;
if(store[i++]=='\n')
c++;
}
int t=i;
char store2[100000]={'\0'};
 c=0;
read(fd,store2,i);
i=0;
while(i<strlen(store))
{
    if(c==m-1)
    break;
if(store[i++]=='\n')
c++;
}
store2[i]='\0';
strcat(store2,x);

char store1[100000]={'\0'};
lseek(fd,t,SEEK_SET);
read(fd,store1,100000);
strcat(store2,store1);
i=0;
lseek(fd,0,SEEK_SET);
if(write(fd,store2,strlen(store2)))
 { count_com++;
             strcpy(prev_entry,x);
 }
}

close(fd);
}
void pastevents_print()
{
    int fd=open(history_path,O_RDWR,0644);
if(fd<0)
{perror("Error opening the file\n");
return;}
    char print[100000]={'\0'};
read(fd,print,100000);
int f=0;
while(f<strlen(print)-1)
{
    if(print[f]=='\n' && print[f+1]=='\n')
    {
        break;}
    else 
    printf("%c",print[f]);
    f++;
}
printf("\n");
close(fd);
}


