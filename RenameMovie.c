#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <sys/types.h>
#include <dirent.h>

char *rename_str(char *name)
{
    char *new_name = malloc(sizeof(char) * 500);
    strcpy(new_name, name);
    for (int j = 0; j < strlen(name); j++)
    {
        if (name[j] == '.')
        {
            new_name[j] = ' ';
        }

        if (name[j] >= '0' && name[j] <= '9')
        {
            new_name[j] = '\0';
            break;
        }
    }
    return new_name;
}

void rename_all(char *dirname)
{
    DIR *d;
    struct dirent *dir;
    d = opendir(dirname);
    int i = 0;
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            if (dir->d_name[0] > 64)
            {
                char *new_name = rename_str(dir->d_name);
                rename(dir->d_name, new_name);
            }
        }
        closedir(d);
    }
}

void rename_all_num(char *dirname)
{
    DIR *d;
    struct dirent *dir;
    d = opendir(dirname);
    int i = 1;
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            i++;
        }
        i -= 3;
        rewinddir(d);
        while ((dir = readdir(d)) != NULL)
        {
            if (dir->d_name[0] > 64)
            {
                char *new_name = rename_str(dir->d_name);
                char new_name_num[500];
                sprintf(new_name_num, "%d - ", i);
                i++;
                strcat(new_name_num, new_name);
                rename(dir->d_name, new_name_num);
            }
        }
        closedir(d);
    }
}

int main()
{
    char cur_dir[500];
    _getcwd(cur_dir, 500);

    char quest;
    printf("Deseja numerar os filmes conforme a data em que foi baixado? (y/n)\n");
    scanf("%c", &quest);

    if (quest == 'n' || quest == 'N')
    {
        rename_all(cur_dir);
    }
    else if (quest == 'y' || quest == 'Y')
    {
        rename_all_num(cur_dir);
    }
}