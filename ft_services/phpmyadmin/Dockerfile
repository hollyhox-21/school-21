FROM alpine:latest

RUN apk update && apk upgrade
RUN apk add nginx
RUN apk add php7
RUN apk add phpmyadmin

# RUN mkdir -p /usr/share/webapps/
# RUN cd /usr/share/webapps
# RUN wget http://files.directadmin.com/services/all/phpMyAdmin/phpMyAdmin-5.0.2-all-languages.tar.gz
# RUN tar zxvf phpMyAdmin-5.0.2-all-languages.tar.gz
# RUN rm phpMyAdmin-5.0.2-all-languages.tar.gz
# RUN mv phpMyAdmin-5.0.2-all-languages phpmyadmin
RUN chmod -R 777 /usr/share/webapps/
RUN ln -s /usr/share/webapps/phpmyadmin/ /var/www/html/phpmyadmin
COPY ./config.inc.php /etc/phpmyadmin/config.inc.php
COPY ./start.sh /tmp/start.sh
COPY ./nginx-localhost /etc/nginx/conf.d/default.conf
RUN chmod +x /tmp/start.sh
RUN mkdir -p /run/nginx

EXPOSE 5000

CMD sh /tmp/start.sh