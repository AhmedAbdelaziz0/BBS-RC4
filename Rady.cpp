#include "BBS_RC4.h"

void BBS::create_key()
{
    int x=s;
    for (int i=0; i<128; i++) //fill key from s
    {
        x=((x*x)%n);
        if((x%2)==0)
            key[i]=0;
        else
            key[i]=1;
    }
}

RC4::RC4(BBS obj)
{
    int a=0,loop=0;
    int key[16]= {0}; //to save 16 byte temp key from 128 bit BBS key
    for(int i=0; i<256; i++)
    {
        intial_state_vector[i]=i;//initialize intial_state_vector with 0 to 256
        permuted_state_vector[i]=i;//initialize  permuted_state_vector with 0 to 256
    }

    for(int i=0; i<16; i++)
    {
        //convert 8 bit to one byte
        a=((128*obj.key[0+loop])+(64*obj.key[1+loop])+(32*obj.key[2+loop])+(16*obj.key[3+loop])+(8*obj.key[4+loop])+(4*obj.key[5+loop])+(2*obj.key[6+loop])+(1*obj.key[7+loop]));
        key[i]=a;
        loop+=8;//using this variable to detect correct bit in BBS key
    }

    for(int i=0; i<256; i++)
    {
        temp_vector[i]=key[i%16];//fill temp vector with byte
    }
}
