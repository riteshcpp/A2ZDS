#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>

// This program counts the frequency of each character in the string "hello world"
// and then sorts the characters by their frequency in descending order. If two characters have the same frequency, they are sorted in ascending order by their character value.
// The output will show each character followed by its frequency.
int main()
{
	std::string iStr ("hello world");

	// Create a frequency map to count occurrences of each character
	std::unordered_map<char, int> freqMap;
	for (auto c : iStr) {
		if (c != ' ') // Ignore spaces
			freqMap[c]++;
	}

	// Convert the frequency map to a vector of pairs for sorting
	std::vector<std::pair<char, int>> freqVec(freqMap.begin(), freqMap.end());
	// Sort the vector by frequency (descending) and then by character (ascending) if frequencies are equal
	std::ranges::sort(freqVec, [](const auto& a, const auto& b) {
		if (a.second != b.second) { // Compare frequencies
			return a.second > b.second;
		}

		return a.first < b.first; // If frequencies are equal, sort by character
	});

	for (const auto& [key, val] : freqVec) {
		std::cout << key << "  " << val << std::endl;
	}
	
	return 0;
}