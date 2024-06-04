/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** copy of ls bash fonction
*/

#include <sys/types.h>
#include <sys/sysmacros.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/ls.h"

static int case_print_two(struct stat *sb)
{
    switch (sb->st_mode & __S_IFMT) {
        case __S_IFLNK:
            my_putstr("l\n");
            break;
        case __S_IFREG:
            my_putstr("f\n");
            break;
        case __S_IFSOCK:
            my_putstr("s\n");
            break;
        default:
            my_putstr("?\n");
            break;
    }
}

static int case_print(struct stat *sb)
{
    switch (sb->st_mode & __S_IFMT) {
        case __S_IFBLK:
            my_putstr("b\n");
            break;
        case __S_IFCHR:
            my_putstr("c\n");
            break;
        case __S_IFDIR:
            my_putstr("d\n");
            break;
        case __S_IFIFO:
            my_putstr("p\n");
            break;
        default:
            case_print_two(sb);
            break;
    }
}

static int type(struct stat *sb)
{
    case_print(sb);
}

static int fileprint
(char *filepath, struct stat *sb)
{
    my_putstr("\nAllocated space: ");
    my_put_nbr(sb->st_blksize);
    my_putstr("\nMinor: ");
    my_put_nbr(minor(sb->st_dev));
    my_putstr("\nMajor: ");
    my_put_nbr(major(sb->st_dev));
    my_putstr("\nUID: ");
    my_put_nbr(sb->st_uid);
    my_putstr("\nGID: ");
    my_put_nbr(sb->st_gid);
}

int bsstat(char *filepath)
{
    struct stat sb;
    int typefile = 0;

    if (stat(filepath, &sb) == -1) {
        perror("stat");
        return -1;
    }
    my_putstr("Name: ");
    my_putstr(filepath);
    my_putstr("\nType: ");
    typefile = type(&sb);
    my_putstr("Inode: ");
    my_put_nbr(sb.st_ino);
    my_putstr("\nHard Link: ");
    my_put_nbr(sb.st_nlink);
    my_putstr("\nSize: ");
    my_put_nbr(sb.st_size);
    fileprint(filepath, &sb);
}
