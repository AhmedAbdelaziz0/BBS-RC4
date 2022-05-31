#include "BBS_RC4.h"

using namespace std;

//swap two elements
//used twice
template <typename E>
void mySwap(E& a, E& b)
{
    E temp = a;
    a = b;
    b = temp;
}

int gcd(int a, int b)
{
    int c = 1;
    if(b > a) //make a always bigger
        mySwap<int> (a, b);

    //Euclidean algorithm
    while(true)
    {
        c = a % b;
        if(!c) //c == 0
            return b;
        a = b;
        b = c;
    }
}

void BBS::rel_prime()
{
    srand(time(0)); //should we control seed?
    int r = rand()%900 + 100; // r in range 100 to 999

    while(gcd(r,n) != 1)    //it will probably run one time
        r = rand()%900 + 100;
    s=r;
}

void RC4::secondPer_andCreateKey(int textlenght)
{
    Rc4_key = new unsigned char[textlenght];


    //just using the algorithm
    int i = 0, j = 0;
    for(int plen = 0; plen < textlenght; plen++)
    {
        i = (i + 1) % 256;
        j = (j + permuted_state_vector[i]) % 256;

        mySwap<unsigned char> (permuted_state_vector[i], permuted_state_vector[j]);

        Rc4_key[plen] = permuted_state_vector[(permuted_state_vector[i] + permuted_state_vector[j]) % 256];
    }
}

string RC4::En_De_cryption(string text)
{
    string en_decrpt;

    int SIZE = text.size();

    for(int i = 0; i < SIZE; i++)
        en_decrpt += Rc4_key[i] ^ text[i];

    return en_decrpt;
}
