#!/bin/bash
#
# Script interactivo para lanzar varios clientes IRC, unirlos a un canal
# y que el primero fije un límite de usuarios con MODE +l.
#

read -rp "Host del servidor: " HOST
read -rp "Puerto: " PORT
read -rp "Número de clientes: " COUNT
read -rp "Contraseña del servidor: " PASSWD
read -rp "Nombre del canal (incluye #): " CHANNEL
read -rp "Máximo de usuarios en el canal: " MAX_USERS

[[ "$PORT"  =~ ^[0-9]+$ ]] || { echo "Error: puerto no numérico."; exit 1; }
[[ "$COUNT" =~ ^[0-9]+$ ]] || { echo "Error: número de clientes no numérico."; exit 1; }
[[ "$MAX_USERS" =~ ^[0-9]+$ ]] || { echo "Error: máximo de usuarios no numérico."; exit 1; }

echo
echo "Lanzando $COUNT clientes hacia $HOST:$PORT en $CHANNEL (límite $MAX_USERS)…"
echo

for i in $(seq 1 "$COUNT"); do
    NICK="nick${i}"
    USERNAME="user${i}"
    REALNAME="RealName${i}"

    # Comandos básicos
    PAYLOAD="PASS ${PASSWD}\r\nNICK ${NICK}\r\nUSER ${USERNAME} 0 * :${REALNAME}\r\nJOIN ${CHANNEL}\r\n"

    # El primer cliente fija el modo +l (límite de usuarios)
    if [ "$i" -eq 1 ]; then
        PAYLOAD="${PAYLOAD}MODE ${CHANNEL} +l ${MAX_USERS}\r\n"
        echo "-> Cliente $i (OPERADOR): fija MODE +l $MAX_USERS"
    else
        echo "-> Cliente $i"
    fi

    # Lanzar cada cliente en nueva ventana si es posible
    if command -v gnome-terminal >/dev/null 2>&1; then
        gnome-terminal -- bash -c " { printf '%b' \"$PAYLOAD\"; cat; } | nc $HOST $PORT"
    elif command -v xterm >/dev/null 2>&1; then
        xterm -hold -e "bash -c \"{ printf '%b' \\\"$PAYLOAD\\\"; cat; } | nc $HOST $PORT\"" &
    else
        { printf "%b" "$PAYLOAD"; cat; } | nc "$HOST" "$PORT" &
    fi
done

