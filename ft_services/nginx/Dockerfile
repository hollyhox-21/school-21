FROM alpine:latest

RUN apk update && apk upgrade
RUN apk add nginx
RUN apk add openssl
RUN apk add openssh
RUN apk add supervisor
RUN apk add openrc

RUN openssl req -newkey rsa:4096 \
			-x509 \
			-sha256 \
			-days 3650 \
			-nodes \
			-out /etc/ssl/certs/nginx-selfsigned.crt \
			-keyout /etc/ssl/private/nginx-selfsigned.key \
			-subj "/C=RU/ST=RT/L=Default/O=Security/OU=PG Department/CN=www.example.com"

COPY ./script.sh /tmp/script.sh
COPY ./nginx-localhost /etc/nginx/conf.d/default.conf
COPY ./supervisor.conf /etc/supervisord.conf
RUN chmod +x /tmp/script.sh
RUN mkdir -p /run/nginx


EXPOSE 80 443 22

CMD sh /tmp/script.sh