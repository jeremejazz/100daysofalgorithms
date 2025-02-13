 
from math import ceil, floor
from gmpy2 import mpz
from decimal import Decimal

def karatsuba(x, y):

    #base case
    if x < 10 and y < 10: # in other words, if x and y are single digits
        return x*y

    n = max(len(str(x)), len(str(y)))
    m = ceil(n/2)   #Cast n into a float because n might lie outside the representable range of integers.

    x_H  = floor(x / 10**m)
    x_L = x % (10**m)

    y_H = floor(y / 10**m)
    y_L = y % (10**m)

    #recursive steps
    a = karatsuba(x_H,y_H)
    d = karatsuba(x_L,y_L)
    e = karatsuba(x_H + x_L, y_H + y_L) - a - d
  
    return mpz(a)* mpz(10**(m*2)) + mpz(e) * mpz(10**m) + mpz(d)
    

if __name__ == "__main__":
 
    result = karatsuba (348173,118394)
 
    print(result)

 