#! /bin/bash

mkdir -p Output/FrontBackMatter

latexmk -quiet -f -pdf -synctex=1 -jobname=thesis -outdir=$PWD/Output $PWD/main.tex
