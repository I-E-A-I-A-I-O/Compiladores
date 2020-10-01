# Compiladores
Repositorio para la materia de diseño de compiladores

ASIGNACION NUMERO 1

Asignación del Primer Proyecto: Realizar un programa (C/C++) que permita ingresar una cadena con la siguiente estructura: (Inicio)Espacio(cadena)Espacio(fin) donde cadena es una expresión aritmética de la forma: (variable)=(número)(operador)(número)
y que cumpla con las siguientes reglas:

- inicio y fin: palabras en minúscula
- Número: Dígito o Cifra (Entero)
- Operador: (+) suma  (-) resta (*) multiplicación (/) división
- Una cadena puede contener operaciones aritméticas agrupadas con paréntesis(solamente) por ejemplo suma=(5+3)/4+4*(2+1)
- Una cadena no puede contener operadores aritméticos consecutivos, por ejemplo:  sum=3*+5 
- En cada cadena que contenga paréntesis, esta debe tener el paréntesis que abre "(" y el paréntesis de cierre ")"
- Al ingresar la cadena y ejecutar solo se debe mostrar un mensaje que diga "válido" (si cumple con las reglas) o "inválida" (si no cumple con las reglas)
