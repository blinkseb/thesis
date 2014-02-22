thesis
======

PHD thesis

Setup
=====

In order to have correct feynman digrams with xelatex, you need to edit the feynmf package to remove the bounding box of EPS files.

Edit the file /usr/local/texlive/2013/texmf-dist/metapost/feynmf/feynmp.mp, and comment line 128.