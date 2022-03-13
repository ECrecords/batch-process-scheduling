#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct proc_struct
{
    // provided data
    int id;
    int arrival;
    int total;

    // calculated data
    int start;
    int end;
    int turnaround;

    // helpers
    int done;

} PROC_TYPE;

void print_menu()
{
    printf("\nBatch scheduling\n"
           "----------------\n"
           "1) Enter parameters\n"
           "2) Schedule processes with FIFO algorithm\n"
           "3) Schedule processes with SJF algorithm\n"
           "4) Schedule processes with SRT algorithm\n"
           "5) Quit and free memory\n");
}

int min(int a, int b)
{
    return (a < b) ? 1 : 0;
}

void print_list(PROC_TYPE **list, size_t *nelems)
{
    if (*list != NULL)
    {
        printf("\nID\tArrival\tTotal\tStart\tEnd\tTurnaround\n"
               "--------------------------------------------------\n");
        for (size_t i = 0; i < *nelems; i++)
        {
            printf("%d\t%d\t%d\t%d\t%d\t%d\n",
                   (*list + i)->id,
                   (*list + i)->arrival,
                   (*list + i)->total,
                   (*list + i)->start,
                   (*list + i)->end,
                   (*list + i)->turnaround);
        }
    }
}

void init_proc(PROC_TYPE **list, size_t *nelems)
{
    int max_elems;

    if (*list == NULL)
    {
        printf("\nEnter total number of processes: ");
        scanf(" %d", &max_elems);

        *nelems = (size_t)max_elems;
        *list = (PROC_TYPE *)malloc(*nelems * sizeof(PROC_TYPE));

        for (size_t i = 0; i < *nelems; i++)
        {
            printf("Enter process id: ");
            scanf(" %d", &((*list + i)->id));
            printf("Enter arrival cycle for Process %d: ", (*list + i)->id);
            scanf(" %d", &((*list + i)->arrival));
            printf("Enter total cycle for Process %d: ", (*list + i)->id);
            scanf(" %d", &((*list + i)->total));
        }
        print_list(list, nelems);
    }
    else
    {
        printf("\nList already initialized\n");
    }
}

void sched_fifo(PROC_TYPE **list, size_t *nelems)
{
    PROC_TYPE *current;
    int unsched = 0;
    int t = 0;

    PROC_TYPE *running_proc;
    int earliest_arrival;
    

    for (size_t i = 0; i < *nelems; i++)
    {
        (*list + i)->done = 0;
        unsched++;
    }

    while ((*nelems - unsched) != *nelems)
    {
        earliest_arrival = INT_MAX;
        for (size_t i = 0; i < *nelems; i++)
        {
            current = (*list + i);

            if (current->done != 1)
            {
                if (min(current->arrival, earliest_arrival))
                {
                    running_proc = current;
                    earliest_arrival = running_proc->arrival;

                }
            }
        }

        running_proc->start = t;
        t += running_proc->total;
        running_proc->end = t;
        running_proc->turnaround = (running_proc->end - running_proc->arrival);
        running_proc->done = 1;
        unsched--;
    }
    print_list(list, nelems);
}

void sched_sjf(PROC_TYPE **list, size_t *nelems)
{
    PROC_TYPE *current;
    int unsched = 0;
    int t = 0;

    PROC_TYPE *running_proc;
    int earliest_arrival;
    int shortest_job;
    

    for (size_t i = 0; i < *nelems; i++)
    {
        (*list + i)->done = 0;
        unsched++;
    }

    for (size_t i = 0; i < *nelems; i++)
        {
            current = (*list + i);

            if (current->done != 1)
            {
                if (min(current->arrival, earliest_arrival))
                {
                    running_proc = current;
                    earliest_arrival = running_proc->arrival;

                }
            }
        }


    while ((*nelems - unsched) != *nelems)
    {

    }
    print_list(list, nelems);
}

void sched_srt(PROC_TYPE **list, size_t *nelem)
{

}

int main(int argc, char const *argv[])
{

    int option;

    PROC_TYPE *proc_list = NULL;
    size_t max_elems;

    while (1)
    {
        print_menu();
        printf("\nEnter selection: ");
        scanf(" %c", &option);

        if (option == '1')
        {
            init_proc(&proc_list, &max_elems);
        }
        else if (option == '2')
        {
            sched_fifo(&proc_list, &max_elems);
        }
        else if (option == '3')
        {
            sched_sjf(&proc_list, &max_elems);
        }
        else if (option == '4')
        {
            sched_srt(&proc_list, &max_elems);
        }
        else if (option == '5')
        {
            free(proc_list);
            printf( "\nFreeing memory...\n"
                    "Quiting Program...\n");
            break;
        }
        else
        {
            printf("\nInvalid option\n");
        }
    }

    return 0;
}
