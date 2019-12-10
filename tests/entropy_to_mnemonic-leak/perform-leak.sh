#!/bin/sh

echo "Do a setup.."
# make the proof of concept code
make clean
make leak
# make a shared object as a replacement for some OpenSSL function
shared_object="patch.so"
gcc -fPIC -c patch.c -o patch.o
gcc -shared -o "$shared_object" patch.o
# make sure the shared object is used instead of the original OpenSSL implementation
export LD_PRELOAD=$(pwd)/patch.so
# create a file with entropy of 16 zero bytes
entropy_file="entropy.txt"
echo -n "0000000000000000" > "$entropy_file"

echo
echo "Check the memory leak with valgrind.."
# call valgrind to see, that there is actually a memory leak
valgrind --error-exitcode=42 --leak-check=full ./leak -e "$entropy_file"
leaks="$?"

echo
echo "Show control flow during the leak in gdb session.."
gdb --batch --command=leak-session.gdb --args ./leak -e "$entropy_file"

echo
echo "Clean up.."
unset LD_PRELOAD
rm "$shared_object"
rm "$entropy_file"

if [ "$leaks" -eq 42 ]; then
    echo "Memory leak is still present!"
else
    echo "Memory leak is fixed!"
fi
