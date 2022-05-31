#ifndef BBS_RC4
#define BBS_RC4
#include <stdlib.h> //for rand
#include <time.h> //for rand
#include <iostream>
#include <string>
#include <conio.h>
#include "bits/stdc++.h"//eslam

using namespace std;

class BBS
{
private:
    int p,q,n,s;
    int key[128];

public:
    //***1
    //construct that initializes p and q with two prime number in range between 100 and 1000(=3 mod 4) then initialize n
    BBS();
    //**2
    void rel_prime();//return(s) random number relatively prime to n
    //**3
    void create_key();//using s to fill key[128]
    //*1
    void show_prime_number();//Display p,q,n on the screen
    //*1
    void show_key();//display the key on screen

    friend class RC4;

};

class RC4
{
private:
    unsigned char intial_state_vector[256];//initial state vector
    unsigned char temp_vector[256];//temporary vector
    unsigned char permuted_state_vector[256];//permuted state vector
    unsigned char* Rc4_key;

public:
    //**3
    RC4(BBS obj);//construct that fill s1[] , t[],and s2[] t[] is fill by key[128] in class bbs (convert it from bit to byte)
    //**1
    void first_permutation();//first permutation that change s2[] by equation j=((j+s[i]+t[i])mod 256} then swap (s[i],s[j])
    //***2
    void secondPer_andCreateKey(int a);//first create key array with length a(text length) and save it to char* key then do second swap on s2[] and generate key
    //*2
    std::string En_De_cryption(std::string text);  //use the key to encrypt the text and return the encrypted text

};



#endif // BBS_RC4
