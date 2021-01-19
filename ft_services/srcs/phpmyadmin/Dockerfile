FROM alpine:3.11.7

RUN apk update && apk upgrade
RUN apk add nginx supervisor openrc bash php7 php7-fpm
RUN rc-update add php-fpm7 default
RUN apk add php7-json \
			php7-mbstring \
			php7-mysqli \
			php7-phar \
			php7-iconv \
			php7-session
RUN apk add --no-cache --repository=http://dl-cdn.alpinelinux.org/alpine/edge/main libc6-compat

RUN sed -i 's/bin\/ash/bin\/bash/g' /etc/passwd

ADD https://dl.influxdata.com/telegraf/releases/telegraf-1.15.2_linux_amd64.tar.gz /
RUN tar -xvzf telegraf-1.15.2_linux_amd64.tar.gz && rm telegraf-1.15.2_linux_amd64.tar.gz
COPY ./telegraf.conf /telegraf-1.15.2/etc/telegraf/telegraf.conf

COPY ./supervisord.conf /etc/supervisord.conf
RUN mkdir -p /var/www/phpmyadmin
COPY ./phpmyadmin /var/www/phpmyadmin
RUN chmod -R 755 /var/www/*
COPY ./nginx.conf /etc/nginx/nginx.conf
RUN mkdir -p /var/run/nginx /var/run/php

EXPOSE 5000

CMD ["/usr/bin/supervisord", "-c", "/etc/supervisord.conf"]