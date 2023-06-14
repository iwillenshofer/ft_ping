#FROM debian:wheezy
FROM debian:jessie
COPY sources_jessie.list /etc/apt/sources.list

RUN apt-get update && apt-get install netbase net-tools make vim gcc man --force-yes -y

WORKDIR /ft_ping
