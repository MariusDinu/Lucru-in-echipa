f x=x+x
sumThree :: Int->Int->Int->Int
sumThree x y z=x + y + z

mulThreeInt :: Int->Int->Int->Int            
mulThreeInt a b c=a*b*c

mulThreeFloat :: Float->Float->Float->Float
mulThreeFloat a b c=a*b*c

maxThree :: Int->Int->Int->Int
maxThree a b c = if a<=b then (if b<=c then c else b) else (if a<=c then c else a)

bigDiv :: Int->Int->Int
bigDiv a b=if(a/=b) then (if(a==b)then a else bigDiv(a-b) b) else (if(a==b) then b else bigDiv a (b-a))


main =putStrLn(show 3)