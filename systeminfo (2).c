#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/sysinfo.h>
#include <sys/types.h>
#include <pwd.h>
#include <time.h>
#include <X11/Xlib.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <dirent.h>
#include <sys/statvfs.h>

WINDOW *win1 = NULL;
WINDOW *win2 = NULL;
WINDOW *win3 = NULL;
WINDOW *win4 = NULL;
WINDOW *win5 = NULL;
WINDOW *win6 = NULL;
WINDOW *win7 = NULL;
WINDOW *win8 = NULL;
WINDOW *win9 = NULL;

WINDOW *createWindow(WINDOW *win, WINDOW *subwin1, int row, int col, int stRow, int stCol)
{
    subwin1 = subwin(win, row, col, stRow, stCol);
    box(subwin1, 0, 0);
    wrefresh(subwin1);
    wrefresh(win);
    return subwin1;
}

void BuildWindow()
{
    int row, col;
    getmaxyx(stdscr, row, col);
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLACK);
    bkgd(COLOR_PAIR(4));
    box(stdscr, 0, 0);

    int a = 1;
    if (col % 2 == 0)
        a = 0;

    win1 = createWindow(stdscr, win1, 7, col, 2, 0);
    win3 = createWindow(stdscr, win3, 5, col / 2 + 1, 9, 0);

    win7 = createWindow(stdscr, win7, 3, col / 3, row - 4, 0);
    win8 = createWindow(stdscr, win8, 3, col / 3, row - 4, col / 3);
    win9 = createWindow(stdscr, win9, 3, (col + a) / 3, row - 4, 2 * col / 3);

    win2 = createWindow(stdscr, win2, 4, col / 2 + a - 1, 9, col / 2 + 1);
    win4 = createWindow(stdscr, win4, 5, col / 2 + a - 1, 13, col / 2 + 1);

    win5 = createWindow(stdscr, win5, 3, col / 2 + 1, 14, 0);
    win6 = createWindow(stdscr, win6, 3, col / 2 + 1, 17, 0);

    wattrset(stdscr, COLOR_PAIR(2) | A_BOLD);
    mvwprintw(stdscr, 0, (col - strlen("SYSTEM INFORMATION")) / 2, "SYSTEM INFORMATION");
    mvwprintw(stdscr, row - 1, (col - strlen("PRESS q TO QUIT")) / 2, "PRESS q TO QUIT");

    wattrset(win1, COLOR_PAIR(1) | A_BOLD);
    wattrset(win2, COLOR_PAIR(1) | A_BOLD);
    wattrset(win3, COLOR_PAIR(1) | A_BOLD);
    wattrset(win4, COLOR_PAIR(1) | A_BOLD);
    wattrset(win8, COLOR_PAIR(1) | A_BOLD);
    mvwprintw(win1, 0, (col - strlen("OS INFORMATION")) / 2, "OS INFORMATION");
    mvwprintw(win2, 0, (col / 2 - strlen("DISPLAY INFORMATION")) / 2, "DISPLAY INFORMATION");
    mvwprintw(win3, 0, (col / 2 - strlen("MEMORY INFORMATION")) / 2, "MEMORY INFORMATION");
    mvwprintw(win4, 0, (col / 2 - strlen("USER INFORMATION")) / 2, "USER INFORMATION");
    mvwprintw(win8, 0, (col / 3 - strlen("CURRENT TIME AND DATE")) / 2, "CURRENT DATE AND TIME");

    refresh();
    wrefresh(win1);
    wrefresh(win2);
    wrefresh(win3);
    wrefresh(win4);
    wrefresh(win5);
    wrefresh(win6);
    wrefresh(win7);
    wrefresh(win8);
    wrefresh(win9);

    // getch();
}

int OsInfo()
{
    FILE *file = fopen("/etc/os-release", "r");
    if (file == NULL)
    {
        fprintf(stderr, "Can't open /etc/os-release\n");
        return 1;
    }

    char value[256];
    char buffer[256];
    wattrset(win1, COLOR_PAIR(4) | A_NORMAL);
    while (fgets(buffer, sizeof(buffer), file))
    {
        if (strncmp(buffer, "NAME=", 5) == 0)
        {
            sscanf(buffer, "NAME=\"%[^\"]", value);
            mvwprintw(win1, 1, 1, "OS name: %s", value);
        }
        else if (strncmp(buffer, "VERSION=", 8) == 0)
        {
            sscanf(buffer, "VERSION=\"%[^\"]", value);
            mvwprintw(win1, 2, 1, "OS version: %s", value);
        }
    }
    wrefresh(win1);
    fclose(file);
    return 0;
}

int SystemInfo()
{
    struct utsname unameData;
    if (uname(&unameData) != 0)
    {

        fprintf(stderr, "Can't use uname()\n");
        return 1;
    }
    mvwprintw(win1, 3, 1, "Kernel version: %s", unameData.release);
    mvwprintw(win1, 4, 1, "Kernel info: %s", unameData.version);
    mvwprintw(win1, 5, 1, "Machine type: %s", unameData.machine);
    wrefresh(win1);
    return 0;
}

int MemoryInfo()
{
    struct sysinfo si;
    if (sysinfo(&si) != 0)
    {
        fprintf(stderr, "Can't use sysinfo()\n");
        return 1;
    }
    int col = getmaxx(win9);
    wattrset(win3, COLOR_PAIR(4) | A_NORMAL);
    wattrset(win7, COLOR_PAIR(4) | A_NORMAL);
    wattrset(win9, COLOR_PAIR(4) | A_NORMAL);
    mvwprintw(win3, 1, 1, "Total RAM: %ld MB", si.totalram / 1024 / 1024);
    mvwprintw(win3, 2, 1, "Free RAM: %ld MB", si.freeram / 1024 / 1024);
    mvwprintw(win7, 1, 1, "Processes: %d ", si.procs);
    mvwprintw(win9, 1, (col - 17), "Uptime: %02ld:%02ld:%02ld", si.uptime / 3600, si.uptime % 3600 / 60, si.uptime % 60);
    return 0;
}

int FreeSpaceInfo()
{
    struct statvfs buffer;

    if (statvfs("/", &buffer) != 0)
    {
        fprintf(stderr, "Can't use statcfs()\n");
        return 1;
    }
    mvwprintw(win3, 3, 1, "Free space in home directory: %lu MB", buffer.f_bsize * buffer.f_bfree / 1024 / 1024);
    return 0;
}

int CPUInfo()
{
    FILE *file = fopen("/proc/cpuinfo", "r");
    if (file == NULL)
    {
        fprintf(stderr, "Can't open /proc/cpuinfo\n");
        return 1;
    }
    int col, row;
    char buffer[256];
    char value[256];
    wattrset(stdscr, COLOR_PAIR(4) | A_NORMAL);
    while (fgets(buffer, sizeof(buffer), file))
    {

        if (strncmp(buffer, "model name", 10) == 0)
        {
            sscanf(buffer, "model name :%[^\n]", value);
            mvprintw(1, 1, "%s", value);
            getyx(stdscr, row, col);
        }
        else if (strncmp(buffer, "cpu MHz", 7) == 0)
        {
            sscanf(buffer, "cpu MHz :%[^\n]", value);
            mvwprintw(stdscr, row, col + 1, "%s MHz", value);
        }
    }
    refresh();
    fclose(file);
    return 0;
}

int CoreInfo()
{
    int num_cores = sysconf(_SC_NPROCESSORS_ONLN);
    wattrset(win6, COLOR_PAIR(4) | A_NORMAL);
    mvwprintw(win6, 1, 1, "Number of cores: %d", num_cores);
    return 0;
}

int DisplayInfo()
{
    Display *dis = XOpenDisplay(NULL);
    if (dis == NULL)
    {
        fprintf(stderr, "Can't open display\n");
        return 1;
    }
    int scr = DefaultScreen(dis);
    wattrset(win2, COLOR_PAIR(4) | A_NORMAL);
    mvwprintw(win2, 1, 1, "Width: %d pixels", DisplayWidth(dis, scr));
    mvwprintw(win2, 2, 1, "Height: %d pixels", DisplayHeight(dis, scr));

    XCloseDisplay(dis);
    return 0;
}

int BatteryInfo()
{
    FILE *file = fopen("/sys/class/power_supply/BAT0/capacity", "r");
    int capacity;
    if (file == NULL)
    {
        fprintf(stderr, "Can't open /sys/class/power_supply/BAT0/capacity\n");
        return 1;
    }

    fscanf(file, "%d", &capacity);

    wattrset(win5, COLOR_PAIR(4) | A_NORMAL);
    mvwprintw(win5, 1, 1, "Battery capacity: %d%%", capacity);
    fclose(file);
    return 0;
}

int DateTimeInfo()
{
    int col = getmaxx(win8);
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    wattrset(win8, COLOR_PAIR(4) | A_NORMAL);
    mvwprintw(win8, 1, (col - 19) / 2, "%02d:%02d:%02d %02d-%02d-%d",
              tm.tm_hour, tm.tm_min, tm.tm_sec, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    return 0;
}

int MyInfo()
{
    uid_t uid = geteuid();
    struct passwd *pw = getpwuid(uid);
    wattrset(win4, COLOR_PAIR(4) | A_NORMAL);
    if (pw)
    {
        mvwprintw(win4, 1, 1, "Name: %s", pw->pw_name);
        mvwprintw(win4, 2, 1, "Home directory: %s", pw->pw_dir);
        mvwprintw(win4, 3, 1, "ID: %d", pw->pw_uid);
    }
    else
    {
        fprintf(stderr, "getpwuid: no password entry for uid %u\n", uid);
        return 1;
    }

    return 0;
}

int main()
{
    initscr();
    noecho();

    BuildWindow();
    OsInfo();
    SystemInfo();
    MemoryInfo();
    FreeSpaceInfo();
    CPUInfo();
    CoreInfo();
    DisplayInfo();
    BatteryInfo();
    DateTimeInfo();
    MyInfo();

    refresh();
    wrefresh(win1);
    wrefresh(win2);
    wrefresh(win3);
    wrefresh(win4);
    wrefresh(win5);
    wrefresh(win6);
    wrefresh(win7);
    wrefresh(win8);
    wrefresh(win9);
    while (getch() != 'q')
    {
        continue;
    }

    endwin();
    return 0;
}