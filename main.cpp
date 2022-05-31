#include "BBS_RC4.h"

#define HEX(x) setw(2) << setfill('0') << hex << (int)( x ) //

void cleanString(string& text)//clean string from space and other Quotations marks
{
    int Size = text.size();

    //we go backward because after erase the string shrinks and text[i] become out of index
    for(int i =Size-1; i >=0; i--)
    {
        if(text[i] >= 'A' && text[i] <= 'Z')
            text[i] = text[i] + 'a' - 'A';
        if(text[i] < 'a' || text[i] > 'z')
            text.erase(i, 1);
    }
}


void print(string& word) {
    unsigned char* temp = new unsigned char[word.size()];
    int s = word.size();
    for(int i = 0; i < s; i++)
    {
        temp[i] = word[i];
    }

    for (int i = 0; i < s; i++)
        cout << HEX(temp[i]) << ' ';

    cout << endl;
}



int main()
{
    BBS bbs_obj;
    bbs_obj.rel_prime();//create s
    bbs_obj.create_key();// create 128 bit key

    RC4 rc4_obj(bbs_obj);
    rc4_obj.first_permutation();

    //choose plain text from user
    cout << "Enter the text you want to cypher:\n";
    string text;

    while(text.back() != 13) //ASCII for enter key
        text += getche();
    cout << endl;
    cleanString(text);

    rc4_obj.secondPer_andCreateKey(text.size());//second permutation and generate key (byte)

    int choose;//variable from user
    bool toggle = true; //to toggle between encryption and decryption
    cout << "\nWhat do you want\n"
         << "[1] see prime number we use.\n"
         << "[2] show key from BBS.\n"
         << "[3] Encryption/Decryption the text.\n"
         << "Other to exit!\n";
    while(true)
    {
        cin >> choose;
        switch (choose)
        {
        case 1:
            cout << "The prime numbers:\n";
            bbs_obj.show_prime_number();
            cout << endl;
            break;

        case 2:
            cout << "The Key:\n";
            bbs_obj.show_key();
            cout << endl;
            break;

        case 3:
            cout << (toggle? "En":"De") << "cryption:\n";
            toggle = !toggle;
            text=rc4_obj.En_De_cryption(text);
            cout << endl; print(text); cout << endl;
            break;

        default:
            return 0;
        }
    }
}
