#include "headers.h"


int compare(const void*a, const void* b)
{
   const char*x =*(const char**)a;
   const char*y =*(const char**)b;
    if(strcmp(x,y)>0)
    return 1;
    else if(strcmp(x,y)<0)
    return -1;
    return 0;

}
void peek_no()
{
    struct dirent *di;
    char* directory[200];
    int i = 0;
    for (i = 0; i < 200; i++)
    {
        directory[i] = (char*)malloc(sizeof(char) * 4096);
    }
    DIR* dr = opendir(path);
    if (dr == NULL)
    {
        perror("The requested directory could not be opened\n");
        return;
    }
    i = 0;
    while ((di = readdir(dr)) != 0)
    {
        struct stat entry_stat;
        char entry_path[4096];
        snprintf(entry_path, sizeof(entry_path), "%s/%s", path, di->d_name);

        if (stat(entry_path, &entry_stat) == -1)
        {
            perror("Error getting file/directory information");
            closedir(dr);
            return;
        }

        if (S_ISDIR(entry_stat.st_mode))
        {
            strncpy(directory[i], di->d_name, 4096);
        }
        else if (access(entry_path, X_OK) == 0)
        {
            strncpy(directory[i], di->d_name, 4096);
        }
        else
        {
            strncpy(directory[i], di->d_name, 4096);
        }

        i++;
    }
    qsort(directory, i, sizeof(char*), compare);
    int n = i;
    i = 0;
    while (i < n)
    {
        struct stat entry_stat;
        char entry_path[4096];
        snprintf(entry_path, sizeof(entry_path), "%s/%s", path, directory[i]);
        if (stat(entry_path, &entry_stat) == -1) {
    perror("Error getting file/directory information");
    closedir(dr);
    return;
}
        if (directory[i] != NULL)
        {
            if (strcmp(directory[i], "..") == 0 || strcmp(directory[i], ".") == 0)
       {i++; continue;}
            if (S_ISDIR(entry_stat.st_mode))
            {
                printf(COLOR_BLUE "%s\n" COLOR_RESET, directory[i]);
            }
            else if (access(entry_path, X_OK) == 0)
            {
                printf(COLOR_GREEN "%s\n" COLOR_RESET, directory[i]);
            }
            else
            {
                printf(COLOR_GREY "%s\n" COLOR_RESET, directory[i]);
            }
            
            free(directory[i]);
        }
        i++;
    }

    closedir(dr);
}






