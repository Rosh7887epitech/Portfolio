#include "include/ls.h"

int main(void)
{
    list *tkt = NULL;

    add_list(&tkt, 8);
    add_list(&tkt, 3);
    put_list(&tkt);
    del_list(&tkt, 0);
    put_list(&tkt);

}