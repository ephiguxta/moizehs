#!/usr/bin/env bash

(( $# != 1 )) && exit 1

port="$1"

# checa se o arduino-cli está instalado
arduino_cli_path=$(whereis arduino-cli | grep -Eo '/.*')
test -e $arduino_cli_path || exit 1

mv src moizehs

SRC="moizehs/moizehs.ino"

arduino-cli compile $SRC \
    -v \
    --fqbn esp32:esp32:esp32 \
    --log \
    --log-level trace

build_error="$?"

(( build_error != 0 )) && {
    mv moizehs src; exit 1
}

arduino-cli upload $SRC \
    --fqbn esp32:esp32:esp32 \
    -p $port

mv moizehs src