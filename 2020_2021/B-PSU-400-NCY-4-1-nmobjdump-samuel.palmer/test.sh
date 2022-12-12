#!/bin/sh
#Script to test epitech objdump project

objdump -fs my_objdump > .original_objdump
./my_objdump my_objdump > .test_my_objdump

if [ ! -e .original_objdump ]; then
    echo "File not found!"
    exit 84
fi

if [ ! -e .test_my_objdump ]; then
    echo "File not found!"
    exit 84
fi

if cmp --silent .original_objdump .test_my_objdump; then
    echo "[OBJDUMP TEST] test passed, files contents are identical"
else
    echo "[OBJDUMP TEST] test failed, files differ"
fi

rm -f .original_objdump
rm -f .test_my_objdump