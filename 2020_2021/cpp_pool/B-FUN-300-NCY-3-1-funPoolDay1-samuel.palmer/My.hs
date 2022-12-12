--
-- EPITECH PROJECT, 2021
-- mySucc.hs
-- File description:
-- My
--

mySucc :: Int -> Int
mySucc a = a + 1

myIsNeg :: Int -> Bool
myIsNeg a | a < 0  = True
          | a >= 0 = False

myAbs :: Int -> Int
myAbs a | a >= 0 = a
        | a < 0 = -a

myMin :: Int -> Int -> Int
myMin a b | a > b = b
          | otherwise = a

myMax :: Int -> Int -> Int
myMax a b | a < b = b
          | otherwise = a

myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

myFst :: (a, b) -> a
myFst (a, b) = a

mySnd :: (a, b) -> b
mySnd (a, b) = b

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

myHead :: [a] -> a  
myHead [] = error "Can't call head on an empty list, dummy!"  
myHead (x:_) = x

myTail :: [a] -> [a]
myTail [] = error "Can't call last of an empty list, dummy!"
myTail (_:x) = x

myLength :: [a] -> Int
myLength [] = 0
myLength (x:xs) = 1 + myLength xs

myNth :: [a] -> Int -> a 
myNth [] _ = error "Can't call index on an empty list, dummy!"
myNth (x:_) 1 = x
myNth (_:xs) n = myNth xs (n-1)