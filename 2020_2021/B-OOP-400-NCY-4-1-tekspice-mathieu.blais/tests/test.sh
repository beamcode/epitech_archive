#!/bin/sh

echo '\n=========================='
echo '==[ GATES UNIT TESTS ]=='
echo '==========================\n'

echo "in_01=1\nin_05=1\nin_06=1\nin_09=0\nin_12=0\nin_13=0\nsimulate\ndisplay\n" | ./../nanotekspice ../nts_single/4001_nor.nts > .tmp4001

echo "in_01=1\nin_02=1\nin_05=1\nin_08=0\nin_09=1\nin_12=0\nin_13=0\nsimulate\ndisplay\n" | ./../nanotekspice ../nts_single/4030_xor.nts > .tmp4030

echo "in_03=1\nin_05=0\nsimulate\ndisplay\n" | ./../nanotekspice ../nts_single/4069_not.nts > .tmp4069

echo "in_01=1\nin_02=1\nin_05=1\nin_06=0\nin_13=1\nin_08=0\nsimulate\ndisplay\n" | ./../nanotekspice ../nts_single/4081_and.nts > .tmp4081

echo "in_01=1\nin_02=1\nin_05=1\nin_06=0\nin_08=1\nin_12=0\nsimulate\ndisplay\n" | ./../nanotekspice ../nts_single/4071_or.nts > .tmp4071

echo "in_01=1\nin_02=1\nin_05=1\nin_06=0\nin_08=1\nin_12=0\nsimulate\ndisplay\n" | ./../nanotekspice ../nts_single/4011_nand.nts > .tmp4011

echo "in_a=0\nin_b=1\nin_c=1\nin_d=1\nsimulate\ndisplay\n" | ./../nanotekspice ../nts_advanced/and.nts > .tmpA4081

echo "in_a=0\nin_b=0\nin_c=1\nsimulate\ndisplay\n" | ./../nanotekspice ../nts_advanced/and-or-not.nts > .tmpAand-or-not

diff .tmp4001 4001 > /dev/null
if [ $? -eq 0 ]
then
    echo "Tests NOR gates (4001) \t\t\tPASSED\n"
else
    echo "Tests NOR gates (4001) \t\t\tFAILED\n"
fi

diff .tmp4030 4030 > /dev/null
if [ $? -eq 0 ]
then
    echo "Tests XOR gates(4030) \t\t\tPASSED\n"
else
    echo "Tests XOR gates (4030) \t\t\tFAILED\n"
fi

diff .tmp4069 4069 > /dev/null
if [ $? -eq 0 ]
then
    echo "Tests NOT gates (4069) \t\t\tPASSED\n"
else
    echo "Tests NOT gates (4069) \t\t\tFAILED\n"
fi

diff .tmp4081 4081 > /dev/null
if [ $? -eq 0 ]
then
    echo "Tests AND gates (4081) \t\t\tPASSED\n"
else
    echo "Tests AND gates (4081) \t\t\tFAILED\n"
fi

diff .tmp4071 4071 > /dev/null
if [ $? -eq 0 ]
then
    echo "Tests OR gates (4071) \t\t\tPASSED\n"
else
    echo "Tests OR gates (4071) \t\t\tFAILED\n"
fi

diff .tmp4011 4011 > /dev/null
if [ $? -eq 0 ]
then
    echo "Tests NAND gates (4011) \t\tPASSED\n"
else
    echo "Tests NAND gates (4011) \t\tFAILED\n"
fi

diff .tmpA4081 A4081 > /dev/null
if [ $? -eq 0 ]
then
    echo "Advanced Tests AND gates (4081) \tPASSED\n"
else
    echo "Advanced Tests AND gates (4081) \tFAILED\n"
fi

diff .tmpAand-or-not Aand-or-not > /dev/null
if [ $? -eq 0 ]
then
    echo "Advanced Tests AND OR NOT  \t\tPASSED\n"
else
    echo "Advanced Tests AND OR NOT  \t\tFAILED\n"
fi

rm -f .tmp