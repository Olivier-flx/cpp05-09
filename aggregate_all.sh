#!/bin/bash

# On récupère le 1er argument. S'il est vide, on utilise le dossier courant (.)
BASE_DIR="${1:-.}"

# Petite sécurité : on enlève le slash final s'il y en a un (ex: ./cpp05/ devient ./cpp05)
BASE_DIR="${BASE_DIR%/}"

if [ ! -d "$BASE_DIR" ]; then
    echo "Erreur : le répertoire '$BASE_DIR' n'existe pas."
    exit 1
fi

# On crée/écrase le fichier global à la racine du dossier passé en argument
OUTPUT="$BASE_DIR/project_all.txt"
> "$OUTPUT"

# Fonction pour ajouter un fichier au fichier de sortie
add_file() {
    echo "================ $1 ============" >> "$OUTPUT"
    cat "$1" >> "$OUTPUT"
    echo -e "\n## FIN DU FICHIER $1 ##\n" >> "$OUTPUT"
}

shopt -s nullglob

# BOUCLE PRINCIPALE : on parcourt tous les dossiers qui commencent par "ex"
for EX_DIR in "$BASE_DIR"/ex*/; do

    # On enlève le slash final pour un affichage plus propre
    EX_DIR="${EX_DIR%/}"

    echo "Agrégation de $EX_DIR..."

    # Ajout d'un gros séparateur visuel pour séparer les exercices dans le .txt
    echo -e "\n\n################################################################################" >> "$OUTPUT"
    echo "#################### DOSSIER : $EX_DIR ####################" >> "$OUTPUT"
    echo -e "################################################################################\n" >> "$OUTPUT"

    # On ajoute tous les .hpp du dossier headers de CE sous-dossier
    for file in "$EX_DIR/headers"/*.hpp; do
        if [ -f "$file" ]; then add_file "$file"; fi
    done

    # On ajoute tous les .cpp du dossier src de CE sous-dossier
    for file in "$EX_DIR/src/"*.cpp; do
        if [ -f "$file" ]; then add_file "$file"; fi
    done

    # On ajoute le main.cpp de CE sous-dossier
    if [ -f "$EX_DIR/main.cpp" ]; then
        add_file "$EX_DIR/main.cpp"
    fi

    # On ajoute le Makefile de CE sous-dossier
    if [ -f "$EX_DIR/Makefile" ]; then
        add_file "$EX_DIR/Makefile"
    fi

done

echo "Le fichier $OUTPUT a été généré avec succès avec tous les exercices !"

# On copie le tout dans le presse-papier
cat "$OUTPUT" | xclip -selection clipboard

echo "Projet entier copié dans le presse-papier !"
