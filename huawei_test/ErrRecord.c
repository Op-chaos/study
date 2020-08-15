// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// #include<malloc.h>

// typedef struct _error_log{
//     char address[100];
//     int num;
//     int couter;
//     struct _error_log *next;
// } error_log;

// typedef struct _list_log{
//     error_log *head;
//     error_log *tail;
// } list_log;

// list_log log_list;

// int update_log(char address[], int num)
// {
//     error_log *log, *p;
//     memcpy(log->address, address, sizeof(address));
//     log->num = num;
//     log->next = NULL;
//     if (log_list.tail) {
//         if(log_list.tail->couter < 8) {
//             p = (error_log *)malloc(sizeof(error_log));
//             memcpy(p->address, address, sizeof(address));
//             p->num = num;
//             p->next = NULL;
//             p->couter = log_list.tail->couter + 1;
//             log_list.tail->next = p;
//         } else {
//             log = log_list.head;
//             log_list.head = log_list.head->next;
//             memcpy(log->address, address, sizeof(address));
//             log->num = num;
//             log->couter = log_list.tail->couter + 1;
//             log->next = NULL;

//             log_list.tail->next = log;
//             log_list.tail = log;
//         }

//     } else {
//         p = (error_log *)malloc(sizeof(error_log));
//         memcpy(p->address, address, sizeof(address));
//         p->num = num;
//         p->next = NULL;
//         p->couter = 1;

//         log_list.head = p;
//         log_list.tail = p;
//     }
//     return 0;
// }

// int main()
// {
//     char address[100], p;
//     int num,len;
//     error_log *log;
//     while(scanf("%s %d", address, num) != EOF) {
//         p = strrchr(address, '\\');
//         p++;
//         len = strlen(p);
//         if (len > 16) {
//             p = p + len - 16;
//             for(log = log_list.head; log; log = log->next) {
//                 if (strcmp(log->address, p) == 0) {
//                     break;
//                 }
//                 update_log(p, num);
//             }
//         }
//     }
//     for(log = log_list.head; log; log = log->next) {
//         printf("%s %d %d\n",log->address, log->num, log->couter);
//     }
//     return 0;
// }


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<math.h>

typedef struct{
    char str[100];
    int num;
    int cnt;
} err_log;

int main()
{
    int i, len, row,times, Flag,arr_cnt;
    char str[10000];
    char *p, *q;
    err_log *tmp, *ar[100];
    times = 0;
    Flag = 0;
    arr_cnt = 0;
    tmp = (err_log *)malloc(sizeof(err_log));
    while(scanf("%s %d", tmp->str, &tmp->num) != EOF) {
        p = strrchr(tmp->str, '\\');
        p++;
        len = strlen(p);
        if (len > 16) {
            p = p + len -16;
        }
        for(i = 0;i < arr_cnt; i++) {
            if(strcmp(ar[i]->str, p) == 0) {
                if(ar[i]->num == tmp->num) {
                    ++ar[i]->cnt;
                    break;
                }
            }
        }
        if(arr_cnt == i) {
            ar[arr_cnt] = (err_log *)malloc(sizeof(err_log));
            ar[arr_cnt]->num = tmp->num;
            strcpy(ar[arr_cnt]->str, p);
            ar[arr_cnt]->cnt = 1;
            arr_cnt++;
        }
    }
    if (arr_cnt < 8) {
        i = 0;
    } else {
        i = arr_cnt -8;
    }
    for(;i<arr_cnt;i++) {
        printf("%s %d %d\n", ar[i]->str, ar[i]->num, ar[i]->cnt);
    }

    return 0;
}