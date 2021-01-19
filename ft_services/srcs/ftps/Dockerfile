FROM alpine:3.11.7

RUN apk update && apk upgrade
RUN apk add vsftpd openssl openrc supervisor bash
RUN apk add --no-cache --repository=http://dl-cdn.alpinelinux.org/alpine/edge/main libc6-compat

RUN openssl req -newkey rsa:4096 \
			-x509 \
			-sha256 \
			-days 3650 \
			-nodes \
			-out /etc/ssl/certs/vsftpd.crt \
			-keyout /etc/ssl/private/vsftpd.key \
			-subj "/C=RU/ST=RT/L=KAZAN/O=Security/OU=PG Department/CN=www.example.com"

RUN sed -i 's/bin\/ash/bin\/bash/g' /etc/passwd

ADD https://dl.influxdata.com/telegraf/releases/telegraf-1.15.2_linux_amd64.tar.gz /
RUN tar -xvzf telegraf-1.15.2_linux_amd64.tar.gz && rm telegraf-1.15.2_linux_amd64.tar.gz
COPY ./telegraf.conf /telegraf-1.15.2/etc/telegraf/telegraf.conf

RUN echo root:root | chpasswd

COPY ./supervisord.conf /etc/supervisord.conf
COPY ./vsftpd.conf /etc/vsftpd/vsftpd.conf

EXPOSE 21
EXPOSE 21210

CMD ["supervisord", "-c", "/etc/supervisord.conf"]