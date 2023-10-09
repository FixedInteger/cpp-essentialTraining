#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 10

int ft_strlen(char *str)
{
    int i =0;
    while(str[i])
    {
        i++;
    }
    return(i);
}
char *ft_strdup(char *s)
{
    int i =0;
    char *p  = malloc(sizeof(char) *ft_strlen(s) + 1);
    if(!p)
        return(NULL);
    while(s[i])
    {
        p[i] = s[i];
        i++;
    }
    p[i] = '\0';
    return(p);
}

char *ft_strjoin(char *s1 ,char *s2)
{
    int  i;
    int  j;

    i =0;
    j=0;
    char *p = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
    while(s1[i])
    {
        p[i] = s1[i];
        i++;   
    }
    while(s2[j])
    {
        p[i+j] = s2[j];
        j++;
    }
    p[i + j] = '\0';
    free(s1);
    return(p);
}

char *ft_substr(char *str ,int start , int  bytes)
{
    int i =0;
    char *p = malloc(sizeof(char) * bytes + 1);
    if(!p)
        return(NULL);
    while(i < bytes && str[start + i])
    {
        p[i] = str[start + i];
        i++;
    }
    p[i] = '\0';
    return(p);
}
int ft_line(char *str)
{
    int i =0;

    while(str[i])
    {
        if(str[i] == '\n')
            return(i);
        i++;
    }
    return(-1);
}
char *ft_rest(char **f,int i)
{
    int len = ft_strlen(*f + i);
    char *p = ft_substr(*f,i,len);
    free(*f);
    *f = NULL;
    return(p);
}

char *ft_sline(char **f,char *buffer,int i)
{
    buffer = ft_substr(*f , 0 ,i + 1);
    *f = ft_rest(f, i +1);
    return(buffer);
}
char *ft_get_next_line(int fd)
{
    char *buffer;
    static char *f;
    char *line = NULL;
    int     i;
    int reader;

    i =0;
    if(!f)
        f = ft_strdup("");
    buffer = malloc(sizeof(char ) * BUFFER_SIZE + 1);
    reader = read(fd,buffer,BUFFER_SIZE);
    while(reader >= 0)
    {
        if(!f[0] && !reader || reader == -1)
            break ;
        buffer[reader] = '\0';
        f = ft_strjoin(f,buffer);
        i = ft_line(f);
        if (i != -1)
            return(free(buffer),ft_sline(&f,line,i));
        if(!reader)
            return(free(buffer),ft_rest(&f,i));
        reader = read(fd,buffer,BUFFER_SIZE);
    }
    return(free(buffer),free(f), f = NULL ,NULL);
}

int main()
{
    int fd = open("get_next_line.c",O_RDONLY);
    char *line;
    while((line = ft_get_next_line(fd)))
    {
        printf("%s",line);
        free(line);
    }
    close(fd);
    return(0);
}