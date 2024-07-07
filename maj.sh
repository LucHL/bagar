#!/bin/bash

if git pull; then
    echo "Mise à jour réussie."
    exit 0
else
    echo "Pas de mise à jour à faire."
    exit 1
fi
