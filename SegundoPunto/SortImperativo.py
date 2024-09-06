def bubbleSort_estudiantes(estudiantes):
    n = len(estudiantes)
    
    for i in range(n):

        maxIndex = i
        
        for j in range(i+1, n):
            if estudiantes[j][1] > estudiantes[maxIndex][1]:
                maxIndex = j
            elif estudiantes[j][1] == estudiantes[maxIndex][1] and estudiantes[j][0] < estudiantes[maxIndex][0]:
                maxIndex = j
        
        estudiantes[i], estudiantes[maxIndex] = estudiantes[maxIndex], estudiantes[i]
    
    return estudiantes

estudiantes = [("Sebastian", 4.0), ("Jacobo", 4.5), ("Esteban", 5.0), ("Julian", 3.5), ("David", 3.0), ("Andres", 4.5), ("Juan", 4.0)]

sortedEstudiantes = bubbleSort_estudiantes(estudiantes)
print(sortedEstudiantes)
