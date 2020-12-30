FROM debian:buster

RUN apt-get -y update && apt-get -y upgrade

RUN apt-get -y install nano

RUN apt-get -y install wget

RUN apt-get -y install nginx

RUN apt-get -y install mariadb-server

RUN apt-get -y install php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring


WORKDIR /var/www/html/
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-all-languages.tar.gz
RUN tar -xf phpMyAdmin-5.0.1-all-languages.tar.gz && rm -rf phpMyAdmin-5.0.1-all-languages.tar.gz
RUN mv phpMyAdmin-5.0.1-all-languages phpmyadmin

COPY ./srcs/config.inc.php phpmyadmin

RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvzf latest.tar.gz && rm -rf latest.tar.gz

COPY ./srcs/wp-config.php /var/www/html/wordpress
#RUN mkdir /etc/nginx/ssl
RUN openssl req -newkey rsa:4096 \
			-x509 \
			-sha256 \
			-days 3650 \
			-nodes \
			-out /etc/ssl/nginx-selfsigned.crt \
			-keyout /etc/ssl/nginx-selfsigned.key \
			-subj "/C=RU/ST=RT/L=Default/O=Security/OU=PG Department/CN=www.example.com"

RUN chown -R www-data:www-data /var/www/*
RUN chmod -R 755 /var/www/*
COPY ./srcs/script.sh ./

RUN rm /etc/nginx/sites-available/default
COPY ./srcs/default /etc/nginx/sites-available

EXPOSE 80 443

CMD bash script.sh