# Versão mínima requerida do CMake
cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(projeto)

# Definir a versão do C++ utilizada
set(CMAKE_CXX_STANDARD 17)

# Incluir diretórios de inclusão
include_directories(include)

# Adicionar arquivos de origem e cabeçalhos
file(GLOB_RECURSE SOURCES "src/*.cpp")  # Use o padrão '**/*.cpp' para capturar recursivamente
file(GLOB_RECURSE HEADERS "include/*.h") # Use o padrão '**/*.h' para capturar recursivamente

# Nome e origem do executável
add_executable(projeto ${SOURCES} ${HEADERS})
