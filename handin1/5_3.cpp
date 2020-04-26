#ifndef TEST_5_3
#define TEST_5_3

void swap_pointer(double *a, double *b)
    {
        double temp = *a;
        *a = *b;
        *b = temp;

    }
void swap_ref(double &a, double &b)
    {
        double temp = a;
        a = b;
        b = temp;
    }

#endif 