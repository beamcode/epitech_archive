--
-- EPITECH PROJECT, 2021
-- DoOp.hs
-- File description:
-- DoOp
--

myElem :: Eq a => a -> [a] -> Bool
myElem _ [] = False
myElem x (y:ys) = x == y || myElem x ys

safeDiv :: Int -> Int -> Maybe Int
safeDiv a b =
    if b == 0 then Nothing
    else Just (a `div` b)

safeNth :: [a] -> Int -> Maybe a
safeNth [] _ = Nothing
safeNth (x:xs) a | (a == 0) = Just x 
                 | otherwise = safeNth xs (a-1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc (Just a) = Just (a + 1)
safeSucc Nothing = Nothing

myLookup :: Eq a => a -> [(a, b)] -> Maybe b
myLookup a [] = Nothing
myLookup a ((c,b):r) = if a == c then Just b else myLookup a r

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo a Nothing c         = Nothing
maybeDo a b Nothing         = Nothing
maybeDo a (Just b) (Just c) = Just (a b c)

--maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c

--readInt :: [Char] -> Maybe Int

getLineLength :: IO Int
getLineLength = do s <- getLine
                   return (length s)

printAndGetLength :: String -> IO Int
printAndGetLength s = do putStrLn (s)
                         return (length s)

--concatLines :: Int -> IO String

--getInt :: IO (Maybe Int)




