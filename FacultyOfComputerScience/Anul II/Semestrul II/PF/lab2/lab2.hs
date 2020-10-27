data Culori = Blue
              |Red
              |Purple
              |Orange
              |Green
              deriving(Show)

data MobileDevice = Laptop {-- Laptop Culori --}
                    |Smartphone {--Laptop Culori--}
                    |Tablet {--Laptop Culori--}
                    deriving(Show)

descriere::MobileDevice->String->String
descriere Laptop all@(x:xs) = "Laptopul este " ++ all 
descriere Tablet all@(x:xs)= "Tableta este " ++all
descriere Smartphone all@(x:xs) = "Telefonul este " ++ all

data Nat = Zero
          |Succ Nat
          deriving(Show)

val::Nat->Int
val Zero=0
val Succ 