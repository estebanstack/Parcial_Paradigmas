import Data.List (sortBy)
import Data.Ord (comparing)

estudiantes :: [(String, Double)]
estudiantes = [("Sebastian", 4.0), ("Jacobo", 4.5), ("Esteban", 5.0), ("Julian", 3.5), ("David", 3.0), ("Andres", 4.5), ("Juan", 4.0)]

sortedEstudiantes :: [(String, Double)]
sortedEstudiantes = sortBy (comparing (negate . snd) <> comparing fst) estudiantes

main :: IO ()
main = print sortedEstudiantes