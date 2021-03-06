﻿#include <iostream>
#include <Windows.h>

const std::string pattern = "a???55661";

bool isInNumbers(char s) {
	return (48 <= int(s) && int(s) <= 57); //0..9  
}

bool isInLetters(char s) {
	return (97 <= int(s) && int(s) <= 122); //a..z
}

bool isInPatternRange(char s) {
	return (isInNumbers(s)) || //0..9 
		(isInLetters(s));	   //a..z
}

bool isCorrectTicket(std::string s) {
	if (s.length() != pattern.length())
		return false;
	bool b = true;
	int letters = 0, numbers = 0;
	for (int i = 0; i < pattern.length(); i++) {
		if (pattern[i] == '?') {
			b = b and isInPatternRange(s[i]);
		} else {
			b = b and (s[i] == pattern[i]);
		}
		if (isInLetters(s[i]))
			letters++;
		if (isInNumbers(s[i]))
			numbers++;
		if (!b) break;
	}
	return b and (letters == 2) and (numbers == 7);
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	std::cout << "Введите количество билетов N: ";
	std::cin >> n;
	std::cout << "Введите билеты: ";
	bool isCorrectTicketFound = false;
	for (int i = 0; i < n; i++) {
		std::string s;
		std::cin >> s;
		if (isCorrectTicket(s)) {
			std::cout << s << " ";
			isCorrectTicketFound = true;
		}
	}
	if (!isCorrectTicketFound)
		std::cout << -1 << std::endl;
}