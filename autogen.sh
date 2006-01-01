#!/bin/sh
echo "* Running aclocal"
aclocal 
echo "* Running autoheader" 
autoheader 
echo "* Running automake"
automake -a -c -f --gnu 
echo "* Running autoconf"
autoconf
echo "Please run ./configure now"
