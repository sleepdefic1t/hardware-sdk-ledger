#!/usr/bin/env bash

if [ "$(docker images | grep 'ledger-app-builder')" == "" ]; then
    docker build -t ledger-app-builder:1.6.0 "${PWD}"
fi

docker run -v "${PWD}":/app ledger-app-builder:1.6.0 sh -c "cd app/ && make clean && make"
