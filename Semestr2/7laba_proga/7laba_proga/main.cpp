#include <stdio.h>
#include <string.h>

struct list {
    list* next;
    void* pdata;
};
void print(void* p) { puts((char*)p); }
void print_int(void* p) { printf("%d ", *(int*)p); }
void for_each(list* pv, void (*pf)(void*))
{
    for (; pv != NULL; pv = pv->next) (*pf)(pv->pdata);
}

list* sort_list(list* ph, int (*pf)(void*, void*))
{
    list* q, * out, * p, * pr;
    out = NULL;
    while (ph != NULL) {
        q = ph; ph = ph->next;
        for (p = out, pr = NULL; p != NULL && ((*pf)(q->pdata, p->pdata) > 0); pr = p, p = p->next);
        if (pr == NULL)
        {
            q->next = out; out = q;
        }
        else
        {
            q->next = p; pr->next = q;
        }
    }
    return out;
}

void sort(void** pp, int (*pf)(void*, void*))
{
    int i, k;
    do
        for (k = 0, i = 1; pp[i] != nullptr; i++)
            if ((*pf)(pp[i - 1], pp[i]) >= 0) {                   // вызов функции сравнения
                void* q;                                          // перестановка указателей
                k++;
                q = pp[i - 1]; pp[i - 1] = pp[i]; pp[i] = q;
            }
    while (k);
}

int scmp(void* p1, void* p2)
{
    return strlen((char*)p1) - strlen((char*)p2);
}
int cmp_int(void* p1, void* p2)
{
    return *(int*)p1 - *(int*)p2;
}

int main()
{
    int b1 = 5, b2 = 6, b3 = 3, b4 = 2;
    const char* s1 = "tw", * s2 = "one", * s3 = "fiver", * s4 = "your";
    void* PP[] = { &b1, &b2, &b3, &b4, nullptr };
    void* PS[] = { (char*)s1, (char*)s2, (char*)s3, (char*)s4, nullptr };
    list a1 = { NULL, (void*)"aaaaaaaaaa" }, a2 = { &a1, (void*)"bbbb" }, a3 = { &a2, (void*)"ccccc" }, * PH = &a3;
    list l1 = { NULL, (void*)&b2 }, l2 = { &l1, (void*)&b1 }, l3 = { &l2, (void*)&b3 }, * PH1 = &l3;
    sort(PP, cmp_int);
    sort(PS, scmp);
    list* phh = sort_list(PH, scmp);
    for_each(phh, print);
    list* phh1 = sort_list(PH1, cmp_int);
    for_each(phh1, print_int);
    printf("\n");
    for (int i = 0; PP[i] != nullptr; i++) printf("%d ", *(int*)PP[i]);
    printf("\n");
    for (int i = 0; PS[i] != nullptr; i++) printf("%c ", *(char*)PS[i]);
    return 0;
}

//void (*P1(void(*ff)(void))) (void) {
//    return ff;
//}
//
//void god(void) {
//    printf("I'm God\n");
//}
//
//int main() {
//    (*P1(god))();
//}