#!/bin/bash
export LC_ALL="en_US.UTF-8"
cd / && ./root/extremum/extremum
mv /plot_dichotomy.pdf /usr/share/nginx/html/plot_dichotomy.pdf
mv /plot_section.pdf /usr/share/nginx/html/plot_section.pdf
mv /plot_fib.pdf /usr/share/nginx/html/plot_fib.pdf
mv /precision_dichotomy.pdf /usr/share/nginx/html/precision_dichotomy.pdf