if [[ $1 != "clean" ]]; then mkdir test & for i in {1..15}; do touch test/pates${i}.txt; done; else rm -rf test; fi
