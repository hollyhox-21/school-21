#!/bin/shell

minikube start --vm-driver=virtualbox --extra-config=apiserver.service-node-port-range=1-35000
eval $(minikube docker-env)
minikube addons enable metallb
minikube addons enable dashboard
kubectl apply -f ./srcs/configmap.yaml
minikube dashboard &
docker build -t influx_image ./srcs/influxdb
docker build -t nginx_image ./srcs/nginx
docker build -t pma_image ./srcs/phpmyadmin
docker build -t wp_image ./srcs/wordpress
docker build -t mysql_image ./srcs/mysql
docker build -t ftps_image ./srcs/ftps
docker build -t grafana_image ./srcs/grafana
kubectl apply -f ./srcs/influxdb/influx.yaml
kubectl apply -f ./srcs/nginx/nginx.yaml
kubectl apply -f ./srcs/phpmyadmin/pma.yaml
kubectl apply -f ./srcs/wordpress/wp.yaml
kubectl apply -f ./srcs/mysql/mysql.yaml
kubectl apply -f ./srcs/grafana/grafana.yaml
kubectl apply -f ./srcs/ftps/ftps.yaml