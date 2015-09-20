#!/bin/sh
projdir=/var/www/html
cp ../*.html $projdir
cp ../*.jsp $projdir
cp -r ../webroot $projdir
cp ../src/php/*.php $projdir
cp -r ../document $projdir
cd ..
proj=`pwd`
job="cd $proj/api/python/cases/55haitao && python fiftyfive_order.py"
echo $job 
