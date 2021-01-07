#!/bin/shell

ssh-keygen -A

/usr/bin/supervisord -c /etc/supervisord.conf
