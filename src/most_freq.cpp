/**
 * @brief Prints out count of most frequently occurring digit
 *       in a string (read from stdin).
 */

#include <iostream>
#include <string>

using namespace std;

int get_max_count(const string&);

/**
 * @fn main
 * @brief Reads strings from stdin and prints out the most
 *       frequently occurring digit's count.
 */
int main()
{
   string in_string;

   while(cin >> in_string)
      cout << get_max_count(in_string) << "\n";

   return 0;
}

/**
 * @fn get_max_count
 * @brief Takes in a string as input and returns the count of
 *       the digit which appears most often in said string.
 */
int get_max_count (
	const string & s	/**< String to look at. */
) {
   const unsigned NUM_DIGITS = 10;      /* Number of digits. */
   unsigned digits[NUM_DIGITS] = { 0 };  /* Array of counters; for each digit. */
   unsigned maxCount = 0;              /* Count of digit which appears most. */

   /* For each char of the string, uptick its associated counter. */
   for (unsigned i = 0; i < s.length(); ++i){
      if(s[i] >= 48 && s[i] <= 57){
         ++digits[static_cast<unsigned>(s[i]) - 48];
      }
   }

   /* Get the count of the char which appears most often. */
   for (unsigned i = 0; i < NUM_DIGITS; ++i)
      if (maxCount < digits[i])
         maxCount = digits[i];

   return maxCount;
}

