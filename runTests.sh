#!/bin/bash

echo -e "\e[1;34mINFO\e[0m: Ejecutando tests..."

for f in test/*.txt; do
    cat $f | bin/lz78 -c | tee intermediate | bin/lz78 -d > ${f}_error
    diff $f ${f}_error > /dev/null
    if [[ $? -ne 0 ]]; then
        rm -f intermediate
        echo -e "\e[1;31mERROR\e[0m: el archivo $f no produce la misma salida que entrada. Salida: ${f}_error."
    else
        peso_antiguo=$(du $f | cut -f 1)
        peso_nuevo=$(du intermediate | cut -f 1)
        tasa=$(echo "scale=2; (${peso_antiguo}-${peso_nuevo})*100/${peso_antiguo}" | bc)
        gzip -c $f > ${f}.gzip
        peso_gzip=$(du ${f}.gzip | cut -f 1)
        tasa_gzip=$(echo "scale=2; (${peso_antiguo}-${peso_gzip})*100/${peso_antiguo}" | bc)
        peso_antiguo=$(du -h $f | cut -f 1)
        peso_nuevo=$(du -h intermediate | cut -f 1)
        peso_gzip=$(du -h ${f}.gzip | cut -f 1)
        echo -e "\e[1;32mOK\e[0m: $f\t${peso_antiguo} -> ${peso_nuevo} | ${tasa}%\t${peso_antiguo} -> ${peso_gzip} | ${tasa_gzip}%"
        rm -f ${f}_error
        rm -f ${f}.gzip
        rm -f intermediate
    fi
done

echo -e "\e[1;34mINFO\e[0m: Tests finalizados."
