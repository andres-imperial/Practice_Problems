#Bitwise_Add -- Implementation of an adder function using no (+,-,*,%) operators

The trick here is that the carry is calculated with the "&" (and) bitwise operator
and the addition is calculated with the "^" (XOR) operator. Shift the carry to the 
left with "<<" (shift left operator) and continue to add the carry in until the 
carry equals 0.
