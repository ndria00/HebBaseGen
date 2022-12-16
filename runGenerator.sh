echo "Executing make"
make -j 8 > /dev/null 2>&1
echo "Compiling logic program for language $1"
./output/main compile $1 $2
make -j 8 > /dev/null 2>&1
echo "Generating base"
./output/main generate $3