/*
 * ██     ██████ ██████ ▄████▄
 * ██      ▄▄▀▀    ▄██▀ ██▄▄██
 * ██████ ██████  ██▀   ▀█▄▄█▀
 * Author: Nicolás de Rivas Morillo
 *
 * File: LZ78 algorithm definition
 */

#pragma once

#include <iostream>

// Encodes in datastream and prints it in out
void encode(std::istream &in, std::ostream &out);

// Decodes in datastream and prints it in out
void decode(std::istream &in, std::ostream &out);
