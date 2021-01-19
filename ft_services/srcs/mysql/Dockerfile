FROM alpine:3.11.7

RUN apk update && apk upgrade
RUN apk add mysql mysql-client supervisor openrc bash
RUN apk add --no-cache --repository=http://dl-cdn.alpinelinux.org/alpine/edge/main libc6-compat

RUN sed -i 's/bin\/ash/bin\/bash/g' /etc/passwd

ADD https://dl.influxdata.com/telegraf/releases/telegraf-1.15.2_linux_amd64.tar.gz /
RUN tar -xvzf telegraf-1.15.2_linux_amd64.tar.gz && rm telegraf-1.15.2_linux_amd64.tar.gz
COPY ./telegraf.conf /telegraf-1.15.2/etc/telegraf/telegraf.conf

RUN mkdir -p /var/lib/mysql
COPY ./my.cnf /etc/mysql/
COPY ./wordpress.sql /
COPY ./supervisord.conf /etc/supervisor/conf.d/
COPY ./import.sh /tmp/import.sh
RUN chmod +x /tmp/import.sh

VOLUME ["/var/lib"]

EXPOSE 3306

CMD sh /tmp/import.sh