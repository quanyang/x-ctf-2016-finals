#!/bin/bash

service mysql start 
service apache2 start &
mysql -uroot -pAdmin2015 -e "drop database exampleDB;SET PASSWORD = PASSWORD('XCTFP@SSW0RDV3RYL0NGANDG00D');"


/bin/bash