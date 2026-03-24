#!/bin/bash

# On récupère le 1er argument. S'il est vide, on utilise le dossier courant (.)
BASE_DIR="${1:-.}"
if [ ! -d "$BASE_DIR" ]; then
    echo "Erreur : le répertoire '$BASE_DIR' n'existe pas."
    exit 1
fi

OUTPUT="$BASE_DIR/project.txt"
# On crée/écrase le fichier projet.txt
> "$OUTPUT"


# Fonction pour ajouter un fichier au projet.txt
add_file() {
    echo "================ $1 ============" >> "$OUTPUT"
    cat "$1" >> "$OUTPUT"
    echo -e "\n## FIN DU FICHIER $1 ##\n" >> "$OUTPUT"
}

shopt -s nullglob

# On ajoute tous les .hpp du dossier headers
for file in "$BASE_DIR/headers"/*.hpp; do
    if [ -f "$file" ]; then
        add_file "$file"
    fi
done

# On ajoute tous les .cpp du dossier src
for file in "$BASE_DIR/src/"*.cpp; do
    if [ -f "$file" ]; then
        add_file "$file"
    fi
done

# On ajoute le main.cpp à la racine
if [ -f "$BASE_DIR/main.cpp" ]; then
    add_file "$BASE_DIR/main.cpp"
fi

# On ajoute le Makefile à la racine
if [ -f "$BASE_DIR/Makefile" ]; then
    add_file "$BASE_DIR/Makefile"
fi

echo "Le fichier $OUTPUT a été généré avec succès."

cat "$OUTPUT" | xclip -selection clipboard

echo "Project copié"
