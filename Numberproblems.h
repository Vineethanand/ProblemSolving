#include "common.h"

void productTwoarrays(int a_array[], int digits_a, int b_array[], int digits_b)
{

    int carry_sum = 0;
    int carry_product = 0;
    int a_idx = digits_a-1;
    int b_idx = digits_b-1;

    int result_digits = (digits_a*digits_b) +2;

    int product_store[digits_b][result_digits];

    int result[result_digits];

    for(int i=0; i< result_digits; i++)
        result[i] = 0;

    int result_idx = result_digits-1;

    for(int i=0;i<digits_b;i++)
    {
        for(int j=0;j<result_digits;j++)
        {
            product_store[i][j]=0;
        }
    }

    int prodct_str_rw_idx = 0;

    for(b_idx=digits_b-1;b_idx >=0; b_idx--)
    {
        int prdct_str_cl_idx = result_digits-prodct_str_rw_idx-1;
        carry_product=0;
        for(a_idx = digits_a-1; a_idx >= 0; a_idx--)
        {
            int prod = (a_array[a_idx] * b_array[b_idx]) + carry_product;
            carry_product = prod/10;
            prod = prod%10;

            product_store[prodct_str_rw_idx][prdct_str_cl_idx] = prod;
            prdct_str_cl_idx--;
        }
        product_store[prodct_str_rw_idx][prdct_str_cl_idx] = carry_product;
        prodct_str_rw_idx++;
    }

//    for(int i=0;i<digits_b;i++)
//    {
//        for(int j=0;j<result_digits;j++)
//        {
//            cout << product_store[i][j] << " ";
//        }
//        cout << endl;
//    }

    for(b_idx = result_digits-1; b_idx >=0; b_idx--)
    {
        for(a_idx = 0; a_idx < digits_b;a_idx++)
        {
            result[result_idx] += product_store[a_idx][b_idx];
        }
        result[result_idx] = result[result_idx] + carry_sum;
        carry_sum = result[result_idx]/10;
        result[result_idx] = result[result_idx]%10;
        result_idx--;
    }

    a_idx = digits_a-1;
    result_idx = result_digits-1;

    while(a_idx >=0 && result_idx >=0)
    {
        a_array[a_idx--] = result[result_idx--];
    }

}
void productUsingArrays(long long a, long long b)
{
    int digits_a = 0, digits_b=0;
    int a_idx, b_idx;
    long long tempa = a;
    long long tempb = b;

    while(tempa>0)
    {
        tempa=tempa/10;
        digits_a++;
    }

    int a_array[digits_a];
    tempa = a;
    a_idx = digits_a-1;
    while(tempa>0)
    {
        a_array[a_idx] = tempa%10;
        tempa=tempa/10;
        a_idx--;
    }

    while(tempb>0)
    {
        tempb=tempb/10;
        digits_b++;
    }

    int b_array[digits_b];
    tempb = b;
    b_idx = digits_b-1;
    while(tempb>0)
    {
        b_array[b_idx] = tempb%10;
        tempb=tempb/10;
        b_idx--;
    }

    productTwoarrays(a_array,digits_a,b_array,digits_b);
//    for(int a_idx=0;a_idx < digits_a;a_idx++)
//    {
//        cout << a_array[a_idx] << " ";
//    }
//    cout << endl;
//
//    for(int b_idx=0;b_idx < digits_b;b_idx++)
//    {
//        cout << b_array[b_idx] << " ";
//    }
//    cout << endl;


}


void longFactorial(int n)
{


    int digits_a = 0, digits_b=0;
    int a_idx, b_idx;
    int tempa = n;
    int tempb;

    digits_a = n*2 + 2;
    int a_array[digits_a];

    for(a_idx=0;a_idx<digits_a;a_idx++)
    {
        a_array[a_idx]=0;
    }

    tempa = n;
    a_idx = digits_a-1;
    while(tempa>0)
    {
        a_array[a_idx] = tempa%10;
        tempa=tempa/10;
        a_idx--;
    }
    n=n-1;
    while(n>=1)
    {
        tempb = n;
        digits_b = 0;
        while(tempb>0)
        {
            tempb=tempb/10;
            digits_b++;
        }

        int b_array[digits_b];
        for(b_idx=0;b_idx<digits_b;b_idx++)
        {
            b_array[b_idx]=0;
        }
        tempb = n;
        b_idx = digits_b-1;
        while(tempb>0)
        {
            b_array[b_idx] = tempb%10;
            tempb=tempb/10;
            b_idx--;
        }
        productTwoarrays(a_array,digits_a,b_array,digits_b);
        n=n-1;
    }

    bool start = false;
    for(int a_idx=0;a_idx < digits_a;a_idx++)
    {
        if(a_array[a_idx] != 0 || start)
        {
            start = true;
            cout << a_array[a_idx];
        }

    }
    cout << endl;
}
