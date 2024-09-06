def bubble_sortEstudiantes(estudiantes):
    n = len(estudiantes)

    for i in range(n):
        for j in range(0, n-i-1):

            if estudiantes[j][1] < estudiantes[j+1][1]:
                estudiantes[j], estudiantes[j+1] = estudiantes[j+1], estudiantes[j]

            elif estudiantes[j][1] == estudiantes[j+1][1] and estudiantes[j][0] > estudiantes[j+1][0]:
                estudiantes[j], estudiantes[j+1] = estudiantes[j+1], estudiantes[j]
    
    return estudiantes

estudiantes = [("Sebastian", 4.0), ("Jacobo", 4.5), ("Esteban", 5.0), ("Julian", 3.5), ("David", 3.0), ("Andres", 4.5), ("Juan", 4.0)]

sortedEstudiantes = bubble_sortEstudiantes(estudiantes)
print(sortedEstudiantes)