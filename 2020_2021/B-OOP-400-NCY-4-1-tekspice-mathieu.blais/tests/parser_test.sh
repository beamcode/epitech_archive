#!/bin/sh

echo '\n========================='
echo '==[ PARSER UNIT TESTS ]=='
echo '=========================\n'

echo 'Testing with known good file...'
if ! echo -e "" | ./../nanotekspice ../nts_parser/good_file.nts > /dev/null 2>&1; then
    echo '==> TEST FAILED\n'
else
    echo '==> TEST PASSED\n'
fi

echo 'Testing with bad pin in file...'
if ! ./nanotekspice nts_parser/bad_pin.nts > /dev/null 2>&1; then
    echo '==> TEST PASSED\n'
else
    echo '==> TEST FAILED\n'
fi

echo 'Testing with bad syntax in file...'
if ! ./nanotekspice nts_parser/bad_syntax.nts > /dev/null 2>&1; then
    echo '==> TEST PASSED\n'
else
    echo '==> TEST FAILED\n'
fi

echo 'Testing with duplicate name in file...'
if ! ./nanotekspice nts_parser/dup_name.nts > /dev/null 2>&1; then
    echo '==> TEST PASSED\n'
else
    echo '==> TEST FAILED\n'
fi

echo 'Testing with no chipset in file...'
if ! ./nanotekspice nts_parser/no_chipset.nts > /dev/null 2>&1; then
    echo '==> TEST PASSED\n'
else
    echo '==> TEST FAILED\n'
fi

echo 'Testing with unknown name in file...'
if ! ./nanotekspice nts_parser/unknown_name.nts > /dev/null 2>&1; then
    echo '==> TEST PASSED\n'
else
    echo '==> TEST FAILED\n'
fi

echo 'Testing with unknown variable in file...'
if ! ./nanotekspice nts_parser/unknown_var.nts > /dev/null 2>&1; then
    echo '==> TEST PASSED\n'
else
    echo '==> TEST FAILED\n'
fi

echo 'Testing with empty file...'
if ! ./nanotekspice nts_parser/lol > /dev/null 2>&1; then
    echo '==> TEST PASSED\n'
else
    echo '==> TEST FAILED\n'
fi