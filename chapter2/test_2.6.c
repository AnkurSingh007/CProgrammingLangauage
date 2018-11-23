0
3
2 
4


// Assuming 16 bit integers
// x =   0  0  0  0  0  0  0  0 0 0 0 0 0 0 0 0 0
//       16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0 
// y =   0  0  0  0  0  0  0  0 0 0 0 0 0 0 0 1 1
//       16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0 
// Expected answer is   0  0  0  0  0  0  0  0 0 0 0 0 1 1 0 0 0
//                      16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
// set 2 bits from position 4 of x. Set this bits to the rightmost 2 bits of y.
