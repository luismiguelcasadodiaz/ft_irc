#!/bin/bash

# Script: irc_client.sh
# Uso: ./irc_client.sh <puerto>

if [ $# -ne 1 ]; then
    echo "Uso: $0 <puerto>"
    exit 1
fi

PUERTO="$1"

# Enviar el archivo de comandos y luego permitir entrada interactiva
cat irc_commands.txt - | nc localhost "$PUERTO"
