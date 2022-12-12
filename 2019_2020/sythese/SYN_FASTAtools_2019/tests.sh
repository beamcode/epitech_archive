#!/bin/bash

./FASTAtools 1 < ../fasta/exampleone.fasta
./FASTAtools 1 < ../fasta/exampletwo.fasta
./FASTAtools 1 < ../fasta/cancer.fasta

./FASTAtools 2 < ../fasta/exampleone.fasta
./FASTAtools 2 < ../fasta/exampletwo.fasta
./FASTAtools 2 < ../fasta/cancer.fasta

./FASTAtools 3 < ../fasta/exampleone.fasta
./FASTAtools 3 < ../fasta/exampletwo.fasta
./FASTAtools 3 < ../fasta/cancer.fasta

./FASTAtools 4 3 < ../fasta/exampleone.fasta
./FASTAtools 4 3 < ../fasta/exampletwo.fasta
./FASTAtools 4 3 < ../fasta/cancer.fasta

./FASTAtools 5 < ../fasta/exampleone.fasta
./FASTAtools 5 < ../fasta/exampletwo.fasta
./FASTAtools 5 < ../fasta/cancer.fasta

./FASTAtools 6 < ../fasta/exampleone.fasta
./FASTAtools 6 < ../fasta/exampletwo.fasta
./FASTAtools 6 < ../fasta/cancer.fasta