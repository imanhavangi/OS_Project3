#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;
struct Task
{
    string name;
    int duration;
    char type;
    int ran = 0;
    int waitingTime;
    int tat;
    bool status = 0;
};
void swap(Task tasks[], int a, int b)
{
    string strTemp = tasks[a].name;
    tasks[a].name = tasks[b].name;
    tasks[b].name = strTemp;

    int intTemp = tasks[a].duration;
    tasks[a].duration = tasks[b].duration;
    tasks[b].duration = intTemp;

    char charTemp = tasks[a].type;
    tasks[a].type = tasks[b].type;
    tasks[b].type = intTemp;

    intTemp = tasks[a].ran;
    tasks[a].ran = tasks[b].ran;
    tasks[b].ran = intTemp;

    intTemp = tasks[a].waitingTime;
    tasks[a].waitingTime = tasks[b].waitingTime;
    tasks[b].waitingTime = intTemp;

    intTemp = tasks[a].tat;
    tasks[a].tat = tasks[b].tat;
    tasks[b].tat = intTemp;

    bool boolTemp = tasks[a].status;
    tasks[a].status = tasks[b].status;
    tasks[b].status = intTemp;
}
void sortDuration(Task tasks[], int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (tasks[j].duration > tasks[j + 1].duration)
            {
                swap(tasks, j, j + 1);
            }
        }
    }
}
void output(Task tasks[], int num)
{
    int i = 0;
    while (tasks[i].status == 0)
    {
        i++;
    };
    cout << "Current: " << tasks[i].name << "(" << tasks[i].ran << "/" << tasks[i].duration << ")" << endl;
    cout << "Quee:    ";
    for (int j = i + 1; j < num; j++)
        if (tasks[j].ran != tasks[j].duration)
            cout << tasks[j].name << "(" << tasks[j].ran << "/" << tasks[j].duration << ")"
                 << " ";
    for (int j = 0; j < i; j++)
        if (tasks[j].ran != tasks[j].duration)
            cout << tasks[j].name << "(" << tasks[j].ran << "/" << tasks[j].duration << ")"
                 << " ";
    cout << endl
         << endl;
}
void FCFS(Task tasks[], int num)
{
    cout << "FCFS:" << endl;

    for (int i = 0; i < num; i++)
        tasks[i].ran = 0;
    int t = 0;
    for (int i = 0; i < num; i++)
    {
        tasks[i].status = 1;
        t = tasks[i].duration;
        tasks[i].ran = tasks[i].duration;
        tasks[i].waitingTime = t - tasks[i].ran;
        output(tasks, num);
        tasks[i].status = 0;
    }
}
void RR(Task tasks[], int num, int quantum)
{
    cout << "RR:" << endl;

    for (int i = 0; i < num; i++)
        tasks[i].ran = 0;
    int t = 0; 
    while (1)
    {
        bool done = true;
        for (int i = 0; i < num; i++)
        {
            tasks[i].status = 1;
            if (tasks[i].ran < tasks[i].duration)
            {
                done = false;

                if (tasks[i].duration - tasks[i].ran > quantum)
                {
                    t += quantum;
                    tasks[i].ran += quantum;
                }
                else
                {
                    t = t + tasks[i].duration - tasks[i].ran;
                    tasks[i].waitingTime = t - tasks[i].duration;
                    tasks[i].ran = tasks[i].duration;
                }
                output(tasks, num);
            }
            tasks[i].status = 0;
        }
        if (done == true)
            break;
    }
}
void SJFS(Task tasks[], int num)
{
    cout << "SJFS:" << endl;
    for (int i = 0; i < num; i++)
        tasks[i].ran = 0;
    int t = 0;
    sortDuration(tasks, num);
    for (int i = 0; i < num; i++)
    {
        tasks[i].status = 1;
        t = tasks[i].duration;
        tasks[i].ran = tasks[i].duration;
        tasks[i].waitingTime = t - tasks[i].ran;
        output(tasks, num);
        tasks[i].status = 0;
    }
}
int main()
{
    int num, temp;

    cin >> num;
    Task tasks[num];

    for (int i = 0; i < num; i++)
    {
        cin >> tasks[i].name;
        cin >> tasks[i].type;
        cin >> tasks[i].duration;
    }
    int quantum = 1;
    FCFS(tasks, num);
    RR(tasks, num, quantum);
    SJFS(tasks, num);
    return 0;
}