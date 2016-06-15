#!/bin/bash

service mysql start 
service apache2 start &
mysql -uroot -pAdmin2015 -e """
drop database exampleDB;
SET PASSWORD = PASSWORD('XCTFP@SSW0RDV3RYL0NGANDG00D'); 
CREATE USER 'continental'@'localhost' IDENTIFIED BY 'XCTFP@SSW0RDV3RYL0NGANDG00D';
GRANT ALL ON continental.* TO 'continental'@'localhost';
CREATE DATABASE continental;
USE continental;
CREATE TABLE users (id INT NOT NULL AUTO_INCREMENT, username varchar(30) NOT NULL, password varchar(64) NOT NULL, address varchar(256), isAdmin INT DEFAULT 0, PRIMARY KEY (id));
INSERT INTO users VALUES (null, 'johnwick', md5('akszxmciu41534567uasnd217^%$#@$%'), 'XCTF{S0_W!CK3D_TRUNC@T3D}', 1);
INSERT INTO users VALUES (null, 'harry', md5('akszxmciu41534567uasnd217^%$#@$%'), '', 1);
INSERT INTO users VALUES (null, 'viggotarasov', md5('akszxmciu41534567uasnd217^%$#@$%'), '', 1);
INSERT INTO users VALUES (null, 'msperkins', md5('akszxmciu41534567uasnd217^%$#@$%'), '', 1);
INSERT INTO users VALUES (null, 'amon', md5('akszxmciu41534567uasnd217^%$#@$%'), '', 1);
INSERT INTO users VALUES (null, 'kaiyuan', md5('akszxmciu41534567uasnd217^%$#@$%'), '', 1);
"""

/bin/bash