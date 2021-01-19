#!/bin/shell

openrc default
/etc/init.d/mariadb setup
rc-service mariadb start
echo "CREATE DATABASE wordpress;"| mysql
echo "CREATE USER 'admin'@'%' IDENTIFIED BY 'admin';"| mysql
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'admin' WITH GRANT OPTION;"| mysql
echo "FLUSH PRIVILEGES;"| mysql
echo "update mysql.user set plugin='mysql_native_password' where user='root';"| mysql
mysql wordpress < wordpress.sql

rc-service mariadb stop
/usr/bin/supervisord -c /etc/supervisor/conf.d/supervisord.conf