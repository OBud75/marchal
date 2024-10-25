#!/usr/bin/sh

for ((i=1; i<6; i++)); do
  for ((j=0; j<=i; j++)); do
    echo -n "*";
  done
  echo ""
done
