Name : Akshay Gore

Bug Report for ConnectX game

1.  inBounds() :

   - This function ignoring the value of width.
   - It is returning only according to the value of height.
   - For example :- inBounds(-12,3) is returning TRUE where as it should return FALSE.

 2. at() :

   - It is returning GARBAGE VALUES even if the provided location is not within board.
   - returns INVALID only if the provided hight is out of bound.

 3. Constructor :

   - The Count of sequential pieces(x) can be greater than the height and width of the board.
