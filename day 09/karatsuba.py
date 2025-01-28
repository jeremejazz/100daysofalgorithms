 
from math import ceil, floor 
from decimal import Decimal 
def karatsuba(left: int , right) -> int:

    if left < 10 and right < 10:
        return left * right
    
    # split by 2

    s_left = str(left)
    s_right = str(right)
    n = max(len(s_left), len(s_right))
    l_half = ceil(len(s_left) / 2)
    r_half = ceil(len(s_right) / 2)

    leftH = floor(left / 10 ** l_half )
    leftL = (left - leftH * 10 ** l_half)

    rightH = floor(right / 10 ** r_half )
    rightL = (right - rightH * 10 ** r_half)

    a = leftH * rightH
    d = leftL  * rightL
    e = ( leftH + leftL ) * (rightH + rightL) - a - d
    xy = (a * 10 ** n) + (e * 10 ** (n/2)) + d
    
 

    return Decimal(xy)

if __name__ == "__main__":
    num = 3141592653589793238462643383279502884197169399375105820974944592 
    multiplier = 3141592653589793238462643383279502884197169399375105820974944592
    result = karatsuba(num, multiplier)
    # result = karatsuba (10,20)
    print(result)

