#include"headers.h"

void input_process(char* input)
{
     int l=strlen(input);
     pastevents(input);
     int i;
     int indicate=0;
     int c=0;
     for(i=0;i<4096;i++)
    input_str[i]='\0';
     for(i=0;i<4096;i++)
    input_im[i]='\0';
    i=0;
     for(i=0;i<l;i++)
     {
        if(input[i+1]==';' || input[i+1]=='&')
        {input_str[c++]=input[i];
        input_str[c++]=' ';}
        else if (input[i]==';' || input[i]=='&')
        {
        input_str[c++]=input[i];
        input_str[c++]=' ';}
        else
        {
            input_str[c++]=input[i];
        }
     }
     char copy[4096]={'\0'};
     
     strcpy(copy,input_str);
    for(i=0;i<4096;i++)
    input_str[i]='\0';
    i=0;
     c=0;
int count=0;
    while(i<strlen(copy))
    {
        char sub[15]={'\0'};
        c=0;
        if(copy[i]=='-')
        {
            int j;
            for(j=i;j<strlen(copy);j++)
            {
                if(copy[j]==' ')
                continue;
                if(copy[j]=='l' || copy[j]=='f' || copy[j]=='d' || copy[j]=='a' || copy[j]=='e' || copy[j]=='-')
                sub[c++]=copy[j];
                else 
                break;
            }
            count+=c;
            if(j==strlen(copy))
            i=j-1;
            else 
            i=j-2;
            sub[c]='\0';
            strcat(input_str,sub);
        }
        else 
        input_str[count++]=copy[i];
        i++;
    }
   

    char* token = strtok(input_str, " ");
       while (token != NULL) {
        if(strcmp(token,";")==0)
        {
         
        }
         else if(strcmp(token,"&")==0)
        {


        }
        else
        {
            if(strcmp(token,"warp")==0)
            {
              token = strtok(NULL, " ");
              if(token!=NULL && (strcmp(token,";")== 0 || strcmp(token,"&")==0))
              {
                indicate=1;
                strcpy(input_im,"warp");
                warp();

              }
              else if(token==NULL)
              {
                strcpy(input_im,"warp");
                warp();
              }
              else
              {
               strcpy(input_im,"warp");
               strcat(input_im," ");
                strcat(input_im,token);
                warp();
             

              }
            }
            else if(strcmp(token,"peek")==0)  
            {
                token = strtok(NULL, " ");
                 if(token!=NULL && (strcmp(token,";")== 0 || strcmp(token,"&")==0))
              {
               indicate=1;
                peek_no();

              }
              else if (token!=NULL && (strcmp(token,"-l-a")==0 || strcmp(token,"-a-l")==0 || strcmp(token,"-la")==0 || strcmp(token,"-al")==0))
              {
              token = strtok(NULL, " ");
              if(token!=NULL && (strcmp(token,";")== 0 || strcmp(token,"&")==0))
                {indicate=1;
                    peek_la();}
                else if(token!=NULL)
                {strcpy(input_im,convert(token));
                peek_la_arg();
              }
              else if(token==NULL)
              {
                 peek_la();
              }


            }
            else if(token!=NULL && (strcmp(token,"-l")==0))
            {
                 token = strtok(NULL, " ");
              if(token!=NULL && (strcmp(token,";")== 0 || strcmp(token,"&")==0))
                {indicate=1;
                    peek_l();}
                else if(token!=NULL)
                {strcpy(input_im,convert(token));
                peek_l_arg();
              }
              else if(token==NULL)
              {
                 peek_l();
              }

            }
             else if(token!=NULL && (strcmp(token,"-a")==0))
            {
                 token = strtok(NULL, " ");
              if(token!=NULL && (strcmp(token,";")== 0 || strcmp(token,"&")==0))
                {indicate=1;
                    peek_a();}
                else if(token!=NULL)
                {strcpy(input_im,convert(token));
                peek_a_arg();
              }
              else if(token==NULL)
              {
                 peek_a();
              }

            }

             else if(token==NULL)
              {
                 peek_no();
              }
              }
            else  if (strcmp("seek",token)==0)
            {
                  token = strtok(NULL, " ");
                  if(token==NULL)
                  perror("No argument provided\n");
                 if(token !=NULL && (strcmp(token,";")== 0 || strcmp(token,"&")==0 ))
              {
               indicate=1;
               perror("Arguments not provided\n");

              }
              else if (token!= NULL && (strcmp(token,"-f")==0 ))
              {
                token=strtok(NULL," ");
                if(token !=NULL && (strcmp(token,";")== 0 || strcmp(token,"&")==0 ))
                {
                    indicate=1;
               perror("Arguments not provided\n");
                                    }
            else if(token!=NULL)
            {
                 char str_r[4096];
                     strcpy(str_r,token);
                    token=strtok(NULL," ");
                    if(token !=NULL && (strcmp(token,";")== 0 || strcmp(token,"&")==0 ))
                       {seek_f(str_r,(path));indicate=1;
                       if(flag==0)
                       printf("No Match Found\n");
                       else 
                       flag=0;}
                       else if(token!=NULL)
                      {seek_f(str_r,convert(token));
                      if(flag==0)
                       printf("No Match Found\n");
                       else 
                       flag=0;}
                      else if(token==NULL)
                    {seek_f(str_r,(path));
                    if(flag==0)
                       printf("No Match Found\n");
                       else 
                       flag=0;}
            }
                else 
                {
                    perror("Nothing provided!\n");
                }
              

              }
              else if(token!=NULL && (strcmp(token,"-f-d")==0 || strcmp(token,"-d-f")==0 ))
              {
                printf("Invalid flags!\n");
              }
              else if(token!=NULL && (strcmp(token,"-d")==0 ))
             {
                token=strtok(NULL," ");
                if(token !=NULL && (strcmp(token,";")== 0 || strcmp(token,"&")==0 ))
                {
                    indicate=1;
               perror("Arguments not provided\n");
                                    }
            else if(token!=NULL)
            {
                 char str_r[4096];
                     strcpy(str_r,token);
                    token=strtok(NULL," ");
                    if(token !=NULL && (strcmp(token,";")== 0 || strcmp(token,"&")==0 ))
                       {seek_d(str_r,(path));indicate=1;
                       if(flag==0)
                       printf("No Match Found\n");
                       else 
                       flag=0;}
                       else if(token!=NULL)
                      {seek_d(str_r,convert(token));
                      if(flag==0)
                       printf("No Match Found\n");
                       else 
                       flag=0;}
                      else if(token==NULL)
                     {seek_d(str_r,(path));
                     if(flag==0)
                       printf("No Match Found\n");
                       else 
                       flag=0;}
            }
                else 
                {
                    perror("Nothing provided!\n");
                }
              

             }
             else if(token!=NULL)
             {
                char str_r[4096];
                     strcpy(str_r,token);
                token=strtok(NULL," ");
                if(token !=NULL && (strcmp(token,";")== 0 || strcmp(token,"&")==0 ))
                {
                    indicate=1;
                    seek(token,(path));
                                    if(flag==0)
                       printf("No Match Found\n");
                       else 
                       flag=0;}
            else if(token!=NULL)
            {
                 char* dm=convert(token);
                      seek(str_r,dm);
                      if(flag==0)
                       printf("No Match Found\n");
                       else 
                       flag=0;

            }
                else if(token==NULL) 
                {
                    seek(str_r,(path));
                    if(flag==0)
                       printf("No Match Found\n");
                       else 
                       flag=0;
                    
                }
              


             }

            }
            else if(strcmp("proclore",token)==0)
            {
                token=strtok(NULL," ");
                if(token!=NULL &&(strcmp(token,";")!= 0 && strcmp(token,"&")!=0))
                {
                    proclore(atoi(token));
                }
                else
                {
                    proclore(getpid());
                }
            }
            else if(strcmp("pastevents",token)==0)
            {
                 token=strtok(NULL," ");
                  if(token!=NULL && (strcmp(token,";")!= 0 && strcmp(token,"&")!=0))
                  {
                   
                      
                        if(strcmp(token,"purge")==0)
                        {
                            purge();
                        }
                        else 
                        {
                            if(strcmp(token,"execute")==0)
                        {
                            token=strtok(NULL," ");
                            if(token!=NULL)
                            pastevents_exec(atoi(token));
                            else 
                            perror("Nothing provided\n");
                            
                        }
                        else{
                            printf("%s not found\n",token);
                        }
                        
                       }

                  }
                  else if(token!=NULL && (strcmp(token,";")== 0 || strcmp(token,"&")==0))
                  {
                    indicate=1;
                    pastevents_print();

                  }
                  else if(token!=NULL)
                  {
                    perror("Invalid argument!\n");
                  }
                  else 
                  {
                     pastevents_print();
                  }
            }
            else
            {
       perror("No such command\n");
            }
        }
       
     if(indicate==0)
     token=strtok(NULL," ");  
    }

}

