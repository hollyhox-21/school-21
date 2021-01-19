FROM alpine:3.11.7

RUN apk update && apk upgrade
RUN apk add supervisor openrc bash
RUN apk add --no-cache --repository=http://dl-cdn.alpinelinux.org/alpine/edge/main libc6-compat

ADD https://dl.influxdata.com/telegraf/releases/telegraf-1.15.2_linux_amd64.tar.gz /
RUN tar -xvzf telegraf-1.15.2_linux_amd64.tar.gz && rm telegraf-1.15.2_linux_amd64.tar.gz

RUN sed -i 's/bin\/ash/bin\/bash/g' /etc/passwd
ADD https://dl.grafana.com/oss/release/grafana-7.3.7.linux-amd64.tar.gz /
RUN tar -xvzf grafana-7.3.7.linux-amd64.tar.gz && rm grafana-7.3.7.linux-amd64.tar.gz
COPY ./telegraf.conf /telegraf-1.15.2/etc/telegraf/telegraf.conf
COPY ./grafana.db /grafana-7.3.7/data/grafana.db
COPY ./supervisord.conf /etc/supervisord.conf

EXPOSE 3000

CMD ["supervisord", "-c", "/etc/supervisord.conf"]
