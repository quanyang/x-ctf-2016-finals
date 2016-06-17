#!/bin/bash

service mysql start 
service apache2 start &
mysql -uroot -pAdmin2015 -e """
drop database exampleDB;
SET PASSWORD = PASSWORD('XCTFP@SSW0RDV3RYL0NGANDG00DSOLONGSOGOOD'); 
CREATE USER 'continental'@'localhost' IDENTIFIED BY 'XCTFP@SSW0RDV3RYL0NGANDG00DSOLONGSOGOOD';
GRANT ALL ON continental.* TO 'continental'@'localhost';
CREATE DATABASE continental;
USE continental;
CREATE TABLE users (id INT NOT NULL AUTO_INCREMENT, username varchar(30) NOT NULL, password varchar(64) NOT NULL, address varchar(256), isAdmin INT DEFAULT 0, PRIMARY KEY (id));
INSERT INTO users VALUES (null, 'johnwick', md5('12345zxc12346g'), '', 1);
"""

/bin/bash