for file in $(ls test); do
  #num=$(echo ${file} | grep -o "[0-9]\+")
  #ext="${file##*.}"
  #name="${file%.*}"
  mv test/${file} test/${file%.txt}.img
done
