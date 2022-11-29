echo "Executing make"
make > /dev/null 2>&1
cd output
echo "Compiling logic program"
./main compile $1
cd ..
make > /dev/null 2>&1
cd output
echo "Generating base"
./main generate $2