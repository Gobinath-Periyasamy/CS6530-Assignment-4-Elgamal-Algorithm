# CS6530-Assignment-4-Elgamal-Algorithm
Assignment-4 Elgamal Algorithm Implementation

Assignments for IIT CS6530 Cryptography Basics

Name : Gobinath Periyasamy

Roll Number : CS21M501

Registered Mail id : janu.gobi@gmail.com

Steps to Execute the Program:

- To **open the elgamal.exe file**.

- To **input the message** Eg : Gobinath, Assignment, Cryptogrpahy Basics, etc.

It will automatically choose random p, g, x, r values.

Private and Public keys will be generated.

Given string is converted into ASCII

Cipher Texts C1 and C2 would be created from the message given using p, g, r.

Then Original message is decrypted using C1, C2, p, g, x .


**Sample Ouput:**

E:\IIT CS Prep\IIT Sem\Cryptography Basics\Elgamal\Github>elgamal.exe

Please enter any plain text: **My name is Gobinath and my Roll Number : CS21M501. This is Cryptography Basics**


ASCII of given string: 

7712132110971091013210511532711119810511097116104329711010032109121328211110810832781171099810111432583267835049775348494632841041051153210511532671141211121161111031149711210412132669711510599115

***********************************************************
* Elgamal Encryption C1 = g^r mod p and C2 = m*y ^ mod p: *
***********************************************************
Private Key :
        x : 21218
Public Key :
        Random prime number p : 99823
        primitive root g : 21

Cipher message C1 : 28759
Cipher Message C2 : 62142406102490459938865464632140982490393655262124907415327354700153936545993886543398258004249088654459933273724906463240610249068770273548327183271249043503153436463270015140987126024901699124904888650131662808491962142103633735849194101324903149258004393655262124903936552621249048886712604061087153398227354766437126088654871558004406102490675258865452621393655137652621

***********************************************
* Elgamal Decryption m = c2 * (ci^x)^-1 mod p *
***********************************************

Decrypted ASCII Message : 7712132110971091013210511532711119810511097116104329711010032109121328211110810832781171099810111432583267835049775348494632841041051153210511532671141211121161111031149711210412132669711510599115

The above ASCII to Original given plain text Message : **My name is Gobinath and my Roll Number : CS21M501. This is Cryptography Basics**


E:\IIT CS Prep\IIT Sem\Cryptography Basics\Elgamal\Github>




**Sample Output 2:**

E:\IIT CS Prep\IIT Sem\Cryptography Basics\Elgamal\Github>elgamal.exe
Please enter any plain text: **Welcome to the Elgamal Algorithm Assignment-4 :)**


ASCII of given string: 8710110899111109101321161113211610410132691081039710997108326510810311111410511610410932651151151051031101091011101164552325841

***********************************************************
* Elgamal Encryption C1 = g^r mod p and C2 = m*y ^ mod p: *
***********************************************************
Private Key :
        x : 29845
Public Key :
        Random prime number p : 99079
        primitive root g : 3

Cipher message C1 : 48755
Cipher Message C2 : 86380877533890026321796331921877537390982147179637390982147668168775373909138443890073795165903192116590389007390941760389007379517963961055983782147668163192173909417608912689126598377379524942319218775324942821478226133408739099061311098

***********************************************
* Elgamal Decryption m = c2 * (ci^x)^-1 mod p *
***********************************************

Decrypted ASCII Message : 8710110899111109101321161113211610410132691081039710997108326510810311111410511610410932651151151051031101091011101164552325841

The above ASCII to Original given plain text Message : **Welcome to the Elgamal Algorithm Assignment-4 :)**


E:\IIT CS Prep\IIT Sem\Cryptography Basics\Elgamal\Github>
