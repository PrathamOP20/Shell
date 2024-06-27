#include"headers.h"
void print_file_info(struct stat entry_stat, const char* filename)
{
    char permissions[11]; // 9 characters for permissions + 1 for NULL terminator
    snprintf(permissions, sizeof(permissions), "%c%c%c%c%c%c%c%c%c%c",
             S_ISDIR(entry_stat.st_mode) ? 'd' : '-',
             entry_stat.st_mode & S_IRUSR ? 'r' : '-',
             entry_stat.st_mode & S_IWUSR ? 'w' : '-',
             entry_stat.st_mode & S_IXUSR ? 'x' : '-',
             entry_stat.st_mode & S_IRGRP ? 'r' : '-',
             entry_stat.st_mode & S_IWGRP ? 'w' : '-',
             entry_stat.st_mode & S_IXGRP ? 'x' : '-',
             entry_stat.st_mode & S_IROTH ? 'r' : '-',
             entry_stat.st_mode & S_IWOTH ? 'w' : '-',
             entry_stat.st_mode & S_IXOTH ? 'x' : '-');

    struct passwd* user_info = getpwuid(entry_stat.st_uid);
    struct group* group_info = getgrgid(entry_stat.st_gid);

    char time_str[20];
    strftime(time_str, sizeof(time_str), "%b %d %H:%M", localtime(&entry_stat.st_mtime));
     
    printf("%s %2lu %-8s %-8s %8lld %s ",
           permissions,
           entry_stat.st_nlink,
           user_info ? user_info->pw_name : "unknown",
           group_info ? group_info->gr_name : "unknown",
           (long long)entry_stat.st_size,
           time_str);
        
}