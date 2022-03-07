#!/bin/bash

# userProc - Un script que da infromación sobre procesos de usuarios


############### Opciones por defecto ###############
NUM_SEG=1
ListaUsuario=$(ps -e -o user| tail -n+2 | sort | uniq)
sort_command="sort -k1"
count=0

############### Funciones ###############

# Muestra el grupo del propietario, el uid del propietario, el número total 
# de procesos de ese usuario, el nombre del usuario, el pid del proceso con 
# más tiempo consumido y el tiempo total del proceso con más tiempo consumido.
AllInfo()
{
  printf "%16s" "USUARIO" "UserID" "GroupID" "NUM_PROCESS" "PID_MAX" "TIEMPO_MAX"
  echo
  for usuario in $@
  do 
    printf "%15s %15s %15s" $usuario $(id -u $usuario) $(id -g $usuario) $(ps -U $usuario | wc -l) $(ps -U $usuario -o time,pid | sort | tail -n 1 | awk -F ' ' ' {print $2} ') $(ps -U $usuario -o time,pid | sort | tail -n 1 | awk -F ' ' ' {print $1} ')
    echo 
  done | $sort_command 
}

#Función encargada de generar una lista con los procesos que tengan un timepo mayor a N
TieneProcesoMayorN()
{
  Var=
  for usuario in $ListaUsuario
  do
    proceso_time=$(ps -U $usuario -o time,pid | sort | tail -n 1 | awk -F ' ' ' {print $1} ' | awk -F ':' ' {print $1*3600 + $2*60 + $3} ')
    if [ $proceso_time -gt $NUM_SEG ]; then
      Var="$Var $usuario"
    fi
  done
  ListaUsuario=$Var
}

# Imprime el numero de procesos que su tiempo de ejecución es mayor que N
NumeroProcesosPorUsuario()
{
  for usuario in $@
  do
  contador=0
    for procesos in $(ps -U $usuario -o time | awk -F ':' ' {print $1*3600 + $2*60 + $3} ')
    do
      if [ $procesos -gt $NUM_SEG ]; then
        contador=$((contador + 1))
      fi
    done
    if [ $contador -ne 0 ]; then
      echo -e "El $usuario tiene $contador procesos mayores que $NUM_SEG"
    fi
  done | $sort_command
}


Usage()
{
  echo "Opciones de ejecución: "
  echo "-t       Modificador de segundos, predeterminado en 1"
  echo "-u       Seleccionar los usuarios especificos"
  echo "-usr     Imprime solo los usarios que estan activos"
  echo "-count   Muestra los progrmas que tiene cada usarios"
  echo "-inv     Imprime el resultado pero invertido"
  echo "-c       Imprime el resultado pero en orden de mayor número de procesos"
  echo "-pid     Imprime el resultado pero en orden de mayor pid de maximo timepo de cada usuario"

}




#Lectura de parámetros
while [ "$1" != "" ]; do
  case $1 in
      -t )
          shift
          NUM_SEG=$1
          ;;
      -u )
          while [ "$1" != "" ]; 
          do
              if [ $(echo $1 | cut -c1) != "-" ]; then
              lista="$lista $1"
              fi
              shift
          done
          ListaUsuario=$lista
          ;;
      -usr )
          ListaUsuario=$(who | awk ' {print $1} ')
          ;;
      -count )
          count=1
          ;;
      -inv )
          sort_command="$sort_command -r"
          ;;
      -pid )
          sort_command="sort -k5"
          ;;
      -c )
          sort_command="sort -k4"
          ;;
      -h | --help )
          Usage
          exit
          ;;
      * )
          Usage
          exit 1
  esac
  shift
done


# Count se pondrá a 1 si se activa la opcion -count
# Llamamos aquí la función con el fin de esperar si se ingresan más parámetros
if [ $count -eq 1 ]; then 
  NumeroProcesosPorUsuario $ListaUsuario
  exit 0
fi
TieneProcesoMayorN $ListaUsuario
AllInfo $ListaUsuario
