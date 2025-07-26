#!/usr/bin/env bash

(( $# != 1 )) && exit 1

port="$1"

# checa se o arduino-cli está instalado
arduino_cli_path=$(whereis arduino-cli | grep -Eo '/.*')
test -e $arduino_cli_path || exit 1

test -d moizehs || mkdir moizehs; cp src/moizehs.ino moizehs/

SRC="moizehs/moizehs.ino"

arduino-cli compile $SRC \
    -v \
    --fqbn esp32:esp32:esp32 \
    --log \
    --log-level trace

build_error="$?"
(( build_error != 0 )) && exit 1

arduino-cli upload $SRC \
    --fqbn esp32:esp32:esp32 \
    -p $port

rm -rf moizehs/