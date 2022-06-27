#pragma once

#include<iostream>
#include<string>
#include<cstdint>
#include<array>

const std::array<char, 14>allowedSymbols{ '0','1','2','3','4','5','6','7','8','9','(',')',',','.' };

std::string checkInput(const char* out, std::int16_t& lBrakets, std::int16_t& operations);

bool isBracketsEquals(const std::string example, std::int16_t& lBrakets);

bool isOperationsEquals(const std::string example, std::int16_t& operations);

bool isAllowedSymbols(const std::string example);