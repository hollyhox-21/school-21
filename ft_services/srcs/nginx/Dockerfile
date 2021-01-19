FROM alpine:3.11.7

RUN apk update && apk upgrade
RUN apk add nginx openrc supervisor openssh openssl bash
RUN apk add --no-cache --repository=http://dl-cdn.alpinelinux.org/alpine/edge/main libc6-compat
ADD https://dl.influxdata.com/telegraf/releases/telegraf-1.15.2_linux_amd64.tar.gz /
RUN tar -xvzf telegraf-1.15.2_linux_amd64.tar.gz && rm telegraf-1.15.2_linux_amd64.tar.gz

RUN openssl req -newkey rsa:4096 \
			-x509 \
			-sha256 \
			-days 3650 \
			-nodes \
			-out /etc/ssl/certs/nginx-selfsigned.crt \
			-keyout /etc/ssl/private/nginx-selfsigned.key \
			-subj "/C=RU/ST=RT/L=Default/O=Security/OU=PG Department/CN=www.example.com"

RUN sed -i 's/bin\/ash/bin\/bash/g' /etc/passwd

RUN adduser -D user && echo 'user:root' | chpasswd && /usr/bin/ssh-keygen -A
COPY ./telegraf.conf /telegraf-1.15.2/etc/telegraf/telegraf.conf
COPY ./nginx.conf /etc/nginx/nginx.conf
COPY ./supervisord.conf /etc/supervisord.conf
RUN mkdir -p /var/run/nginx
RUN mkdir -p /www && touch /www/index.html && echo "Hello, World!" > /www/index.html

EXPOSE 80 443 22

CMD ["/usr/bin/supervisord", "-c", "/etc/supervisord.conf"]