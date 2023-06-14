#!/bin/bash

#ping volume relative dir
VOLUME=../ft_ping
CONTAINER_TAG=ft_ping

docker build -t $CONTAINER_TAG .
docker run --rm  -v $PWD/${VOLUME}:/ft_ping:rw -it $CONTAINER_TAG
