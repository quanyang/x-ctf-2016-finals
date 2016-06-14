#!/bin/bash

service mysql start 
service apache2 start &
mysql -uroot -pAdmin2015 -e """
drop database exampleDB;
SET PASSWORD = PASSWORD('XCTFP@SSW0RDV3RYL0NGANDG00D'); 
CREATE DATABASE continental;
USE continental;
CREATE TABLE users (id INT NOT NULL AUTO_INCREMENT, username varchar(30) NOT NULL, password varchar(64) NOT NULL, PRIMARY KEY (id));
"""

/bin/bash