#! /bin/bash

find . -name "*.eps" -exec sh -c 'echo "Convert {}" ; epstopdf {}' \;
