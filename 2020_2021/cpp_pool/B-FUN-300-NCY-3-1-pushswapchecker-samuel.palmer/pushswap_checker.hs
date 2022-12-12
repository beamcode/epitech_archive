--
-- EPITECH PROJECT, 2021
-- checker.hs
-- File description:
-- checker
--

module Main where
import Text.Read
import Data.Char
import Data.Maybe
import Data.List
import System.Exit
import System.Environment

main :: IO ()
main = do
    args <- getArgs
    line <- getLine
    let args_list = stringToInts args
    let ints_list = words line
    if null args_list || null ints_list
        then exitWith $ ExitFailure 84
        else putStrLn "OK"

{-
indexOf :: [a] -> [String] -> IO ()
indexOf list nums =
    let step l index = case l of
            [] -> Nothing
            (x:xs) ->
                if x == "sa"
                    then Just "sa"
                else if x == "sb"
                    then Just "sb"
                else if x == "sc"
                    then Just "sc"
                else if x == "pa"
                    then Just "pa"
                else if x == "pb"
                    then Just "pb"
                else if x == "ra"
                    then Just "ra"
                else if x == "rb"
                    then Just "rb"
                else if x == "rr"
                    then Just "rr"
                else if x == "rra"
                    then Just "rra"
                else if x == "rrb"
                    then Just "rrb"
                else if x == "rrr"
                    then Just "rrr"
                else step xs (index + 1)
    in step list 0
-}

stringToInts :: [String] -> [Int]
stringToInts [] = []
stringToInts a = map read a

printRes :: Bool -> IO ()
printRes True = putStrLn "OK"
printRes False = putStrLn "KO"

-- Ra, rb et rr
swap :: [a] -> [a]
swap [] = []
swap [x] = [x]
swap (x:xs) = (last xs : init xs) ++ [x]

-- rra rrb rrr
rotate :: [Int] -> [Int]
rotate [] = []
rotate (x:xs) = reverse $ x:(reverse xs)

-- sa, sb, sc
swapElementsfs :: [a] -> [a]
swapElementsfs [] = []
swapElementsfs [a] = [a]
swapElementsfs xs = let elemI = xs !! 0
                        elemJ = xs !! 1
                        left = take 0 xs
                        middle = take (1 - 0 - 1) (drop (0 + 1) xs)
                        right = drop (1 + 1) xs
                in  left ++ [elemJ] ++ middle ++ [elemI] ++ right