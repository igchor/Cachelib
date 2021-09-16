# syntax=docker/dockerfile:1
FROM ubuntu:20.04
COPY . /cachelib
ENV PATH="/cachelib/opt/cachelib/bin/:${PATH}"
RUN apt-get update && TZ="America/Los_Angeles" DEBIAN_FRONTEND="noninteractive" apt-get install -y \
    sudo \
    git \
    tzdata \
 && rm -rf /var/lib/apt/lists/*
RUN cd cachelib \
 && ./contrib/build.sh -j -v
