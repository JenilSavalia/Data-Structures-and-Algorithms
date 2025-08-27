Hashing

hash collision  -> (Reslove) -> separate chaining  // insertin O(1)    , search and deletion O(n)    , we are using linked lists


separate chaining -> (resolve) -> Linear Proabing -> Primary Clustering

Primary Clustering -> (Reslove) -> Quadratic Proabing -> Quadratic Clustering


Quadratic Clustering -> (Resolving) -> Double Hashing (increases computation and increases time complexity)




h(k) = k MOD(%) size
h(k) = (k+i) MOD(%) size
h(k) = (k+i**2) MOD(%) size

Double Hashing funct

h(k) = (h(k) + i*h**2(k)) MOD(%) size
