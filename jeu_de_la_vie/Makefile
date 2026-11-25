# ==============================================================================
# Makefile - Projet POO : Le Jeu de la Vie
# ==============================================================================

# 1. Compilateur et options de compilation
CXX      = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude -g

# Bibliothèques pour l'édition de liens (à décommenter à l'étape 5 pour SFML)
LDFLAGS  =
# LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# 2. Fichiers source, en-têtes et objets générés automatiquement
SRC      = $(wildcard src/*.cpp)
OBJ      = $(SRC:src/%.cpp=build/%.o)
HEADERS  = $(wildcard include/*.hpp)
EXEC     = jeu_de_la_vie

# 3. Cible par défaut (exécutée quand on tape simplement "make")
all: $(EXEC)

# 4. Édition de liens : assemble tous les fichiers objets (.o) en un exécutable
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC) $(LDFLAGS)

# 5. Compilation séparée : transforme chaque src/X.cpp en build/X.o
#    Dépend aussi des .hpp pour recompiler si un en-tête est modifié
build/%.o: src/%.cpp $(HEADERS)
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 6. Lance le programme après l'avoir compilé si besoin
run: $(EXEC)
	./$(EXEC)

# 7. Nettoie les fichiers générés (objets et exécutable)
clean:
	rm -rf build $(EXEC)

# Indique que ces cibles sont des commandes et non des noms de fichiers
.PHONY: all run clean
