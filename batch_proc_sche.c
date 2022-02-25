#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct proc_struct
{
    int id;
    int arrival;
    int total;
    int start;
    int end;
    int turnaround;
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
    }
    else
    {
        printf("\nಠ__ಠ NO\n");
    }
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
        scanf(" %d", &option);

        if (option == 1)
        {
            init_proc(&proc_list, &max_elems);
            print_list(&proc_list, &max_elems);
        }
        else if (option == 2)
        {
            /* code */
        }
        else if (option == 3)
        {
            /* code */
        }
        else if (option == 4)
        {
            /* code */
        }
        else if (option == 5)
        {
            break;
        }
        else
        {
            /* code */
        }
    }

    return 0;
}
