#!/bin/bash

echo ""
echo "  ██      ███████ ███████  █████"
echo "  ██         ███       ██ ██   ██"
echo "  ██        ███       ██   █████"
echo "  ██       ███       ██   ██   ██"
echo "  ███████ ███████    ██    █████"
echo "  Autor: Nicolás de Rivas Morillo"
echo ""

# Calculates the compression ratio of a file and its compressed counterpart
get_ratio() {
    old_size=$(du "$1" | cut -f 1)
    new_size=$(du "$2" | cut -f 1)
    ratio=$(echo "scale=2; (${old_size}-${new_size})*100/${old_size}" | bc)
    old_size=$(du -h "$1" | cut -f 1)
    new_size=$(du -h "$2" | cut -f 1)
    echo -n "${old_size} -> ${new_size} | ${ratio}%"
}

# Prints compression ratio and sizes
print_compression_info() {
    echo -e -n "\033[1;32mOK\033[0m: $1\t"
    get_ratio "$1" intermediate
    printf "\t"
    get_ratio "$1" "$1.gzip"
    echo ""
}

# Prints information message
info() {
    echo -e "\033[1;34mINFO\033[0m: $1"
}

# Main program
info "Ejecutando tests..."

for f in test/*.txt; do
    if [ "$f" = "test/*.txt" ]; then # Check if the wildcard expanded
        info "No se han encontrado tests en ./test"
        break
    fi
    cat "$f" | bin/lz78 -c | tee intermediate | bin/lz78 -d > "${f}_error" # Compress and decompress the file
    if ! diff "$f" "${f}_error" > /dev/null; then # If diff is not ok theres an error
        rm -f intermediate
        echo -e "\033[1;31mERROR\033[0m: el archivo $f no produce la misma salida que entrada. Salida: ${f}_error."
    else # Else, the test is passed
        gzip -c "$f" > "${f}.gzip"
        print_compression_info "$f"
        rm -f "${f}_error" intermediate "${f}.gzip"
    fi
done

info "Tests finalizados."
