#ifndef EXECUTE_H
#define EXECUTE_H
#include <bits/stdc++.h>
#include <sys/resource.h>
#include <unistd.h>
using namespace std;

void get_usage(char *argv1, char *argv2)
{
    struct rusage ru;
    getrusage(RUSAGE_SELF, &ru);
    auto time_used = ru.ru_utime.tv_sec * 1000 + ru.ru_utime.tv_usec / 1000 + ru.ru_stime.tv_sec * 1000 + ru.ru_stime.tv_usec / 1000;
    auto memory_used = ru.ru_minflt * (sysconf(_SC_PAGESIZE) / 1024);
    string filename;
    argv1[0] == '.' ? filename = argv1 + 2 : filename = argv1;
    filename = filename + "_result" + argv2 + ".txt";
    ofstream file(filename, ios::app);
    file << time_used << "\n";
    file << memory_used << "\n";
}
void set_cpu_limit(int seconds = 2)
{
    struct rlimit rl;
    rl.rlim_cur = seconds;
    rl.rlim_max = seconds + 1;
    setrlimit(RLIMIT_CPU, &rl);
}
void catch_error(int argc)
{
    if (argc < 2)
    {
        cout << "Usage: ./<code> <testcase>\n";
        exit(1);
    }
}
#endif // EXECUTE_H
