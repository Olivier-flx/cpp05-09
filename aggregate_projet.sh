#!/bin/bash

# On crée/écrase le fichier projet.txt
> projet.txt

# Fonction pour ajouter un fichier au projet.txt
add_file() {
    echo "================ $1 ============" >> projet.txt
    cat "$1" >> projet.txt
    echo -e "\n## FIN DU FICHIER $1 ##\n" >> projet.txt
}

# On ajoute tous les .hpp du dossier headers
for file in headers/*.hpp; do
    if [ -f "$file" ]; then
        add_file "$file"
    fi
done

# On ajoute tous les .cpp du dossier src
for file in src/*.cpp; do
    if [ -f "$file" ]; then
        add_file "$file"
    fi
done

# On ajoute le main.cpp à la racine
if [ -f "main.cpp" ]; then
    add_file "main.cpp"
fi

# On ajoute le Makefile à la racine
if [ -f "Makefile" ]; then
    add_file "Makefile"
fi

echo "Le fichier projet.txt a été généré avec succès."

cat projet.txt | xclip -selection clipboard

echo "Project copié"
