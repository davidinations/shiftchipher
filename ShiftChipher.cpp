/* 
Nama : David Aditya Susanto
NPM  : 140810190067
Kelas: A
GeeksForGeeks (R) pengembangan dari Affine Chipher-nya 
dengan compiler tdm-gcc (g++.exe)
ntah kenapa compiler yang lain (gcc) tidak bisa
*/

#include<bits/stdc++.h>
using namespace std;
 
//Kunci Value K
const int k = 24;
 
string encryptMessage(string msg)
{
    ///Tempat pengisian teks plainteks-nya.
    string cipher = "";
    for (int i = 0; i < msg.length(); i++)
    {
        // Dibuat Aturan untuk memisahkan huruf yang terdapat spasi didalamnya
        if(msg[i]!=' ')
            /* 
            Jika isi teks tidak kosong maka di aplikasikan enkripsi dengan 
            rumus (x + k) mod m dimana x itu plainteks yang akan diubah dalam
            bentuk angka sedangkan m = 26 dan 'A' itu dibawa dalam jangkauan
            ASCII alphabet [ 65-90 | A-Z ] 
            */
            cipher = cipher +
                        (char) ((((msg[i]-'A') + k) % 26) + 'A');
        else
            //kalau kosong maka langsung dilewati ke kolom selanjutnya
            cipher += msg[i];    
    }
    return cipher;
}
 
string decryptCipher(string cipher)
{
	//Tempat pengisian teks chipher-nya.
    string msg = "";
    for (int i = 0; i < cipher.length(); i++)
    {
        if(cipher[i]!=' ')
            /*
            Jika isi teks tidak kosong maka di aplikasikan deenkripsi dengan 
            rumus (y - b) mod m dimana y itu chiperteks yang akan diubah dalam
            bentuk angka sedangkan m = 26 dan 'A' itu dibawa dalam
            jangkauan ASCII alphabet [ 65-90 | A-Z ] 
            */
            msg = msg +
                       (char) (((cipher[i]+'A' - k) % 26) + 'A');
        else
            //kalau kosong maka langsung dilewati ke kolom selanjutnya
            msg += cipher[i];
    }
 
    return msg;
}
 
//Driver Program
int main(void)
{
    string msg = "DAVID ADITYA";
     
    //memanggil fungsi enkripsi
    string cipherText = encryptMessage(msg);
    cout << "Encrypted Message is : " << cipherText<<endl;
     
    //memanggil fungsi dienkripsi
    cout << "Decrypted Message is: " << decryptCipher(cipherText);
 
    return 0;
}
