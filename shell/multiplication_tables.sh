#!/usr/bin/sh

display_table(){
  local N=$1
  for ((i=1;i<=10;i++)); do
    echo ${i}*${N} = $((${i}*${N}))
  done
}


if [[ "$1" -gt 0 ]]; then
  display_table $1
else
  echo "$1 is NaN"
fi


## this works, but using `if` is easier
#case $1 in 
#  [1-9][0-9]*) echo $N
#  ;;
#  *) echo "test"
#esac
