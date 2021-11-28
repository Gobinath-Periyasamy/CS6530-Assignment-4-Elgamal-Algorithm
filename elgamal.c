#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

// Random number
uint64_t randoms(uint64_t upper, uint64_t lower)

{
    uint64_t num = ( rand()%
                (upper - lower +1)) + lower;
    return num;

}

//Find whether given number is prime or not

uint64_t prime(uint64_t n)
{
    uint64_t i, flag = 0;
    for (i=2;i<n/2; ++i)
    {
        //condition for non-prime
        if (n % i == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

// get random and prime
uint64_t prime_ran(uint64_t upper,uint64_t lower)
{
    uint64_t p;
    uint64_t flag = 1;
    while(flag)
    {
        p = randoms(upper, lower);
        flag = prime(p);
    }
    return p;
}

// Euclid Algorithm
uint64_t Euc_gcd(uint64_t a, uint64_t b)
{
    if (a == 0)
        return b;
    return Euc_gcd(b % a, a);
}

//Modular Exponentiation
uint64_t power(uint64_t  x, uint64_t y, uint64_t p)
{
    uint64_t res = 1;     // Initialize result

    x = x % p; // Update x if it is more than or
                // equal to p

    if (x == 0) return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

// Exponent
uint64_t Exponent(uint64_t bit, uint64_t n, uint64_t* y, uint64_t* a)
{
    if (bit == 1) {
        *y = (*y * (*a)) % n;
    }
 
    *a = (*a) * (*a) % n;
}
 

// Finding t_value
uint64_t t_value(uint64_t a, uint64_t m, uint64_t n)
{
    uint64_t r;
    uint64_t y = 1;
 
    while (m > 0)
    {
        r = m % 2;
        Exponent(r, n, &y, &a);
        m = m / 2;
    }
 
    return y;
}


// Finding Primitive Root
uint64_t PrimitiveRoot(uint64_t p)
{
    uint64_t flag;
    for (uint64_t a = 2; a < p; a++)
    {
        flag = 1;
        for (uint64_t i = 1; i < p; i++)
        {
            if (t_value(a, i, p) == 1 && i < p - 1) {
                flag = 0;
            }
            else if (flag && t_value(a, i, p) == 1 && i == p - 1) {
                return a;
            }
        }
    }
}




// Choosing x
uint64_t x_value(uint64_t p)

{
        uint64_t x_arr[sizeof(p)];

        uint64_t z_len;
        z_len = p - 2;
//                                            printf("z_len : %d",z_len);
        uint64_t arr[z_len];
        uint64_t size, i, toSearch = 3, found = 0;

        for(i=2; i<z_len; i++)
        {
            uint64_t z_val = i % p;
            // printf("Zp values : %d ", z_val);
            arr[i] = z_val;
        }

    while ((found == 0))
    {

        toSearch = randoms(p,2);


        /* Assume that element does not exists in array */
        found = 0; 
        
        for(i=0; i<z_len; i++)
        {
            /* 
            * If element is found in array then raise found flag
            * and terminate from loop.
            */
            if(arr[i] == toSearch)
            {
                found = 1;
                break;
            }
        }
    }

    return toSearch;



}



//Driver code

int main()

{

    // Key Generation :

    uint64_t p,g,x,y;

    uint64_t upper = 100000;
    uint64_t lower = (upper-1000);

    srand (time(0));

    // Choose Random Prime P
    p = prime_ran(upper,lower);
    
    // Finding Primitive Root of P:
    g = PrimitiveRoot(p);
    
    // Choosing x
    x = x_value(p);

    // calculating public key y
    y = power(g,x,p);

    
    // Getting the String from the user:
    char str[1000];
    uint64_t i=0;
    uint64_t mes[1000], c2[1000];

    printf("Please enter any plain text: ");
    //scanf("%s",str);
    gets(str);
    printf("\n\n");
    
    printf("ASCII of given string: ");

    while(str[i])
    {
        mes[i] = str[i];
        printf("%d",mes[i]);
        i++;
    }

    printf("\n\n");

    // Encryption :

    printf("***********************************************************\n");
    printf("* Elgamal Encryption C1 = g^r mod p and C2 = m*y ^ mod p: *\n");
    printf("***********************************************************\n");
    // 1 < r < p
    uint64_t r;
    do {
        r = rand() % (p - 1) + 1;
    }
    while (Euc_gcd(r, p) != 1);

    uint64_t c1 = power(g, r, p);


    i = 0; 
    while(mes[i])
    {
        c2[i] = mes[i] * power(y, r, p) % p;
        i++;
    }

    printf("Private Key :\n\tx : %d\n",x);

    printf("Public Key : \n");
    printf("\tRandom prime number p : %d\n",p);
    printf("\tprimitive root g : %d\n\n",g);

    printf("Cipher message C1 : %d \n",c1);


    printf("Cipher Message C2 : ");
    i = 0;
    while (c2[i])
    {
        printf("%d", c2[i]);
        i++;
    }
    
    printf("\n\n");

    // Decryption 

    printf("***********************************************\n");
    printf("* Elgamal Decryption m = c2 * (ci^x)^-1 mod p *\n");
    printf("***********************************************\n");

    i = 0; 
    while(c2[i])
    {
        uint64_t c_2 = c2[i];
        mes[i] = c_2 * power(c1, p-1-x, p) % p;
        i++;
    }

    printf("\n");

    printf("Decrypted ASCII Message : ");
    i = 0; 
    while(mes[i])
    {
        printf("%d",mes[i]);
        i++;
    }

    printf("\n\n");

    // Converting ASCII to Original:

    printf("The above ASCII to Original given plain text Message : ");
    i = 0; 
    while(mes[i])
    {
        printf("%c",mes[i]);
        i++;
    }
    printf("\n\n");

    return 0;
}
